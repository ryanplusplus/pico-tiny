/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include <stdbool.h>
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "hardware/uart.h"
#include "tiny_uart1.h"
#include "tiny_event.h"
#include "tiny_utils.h"

static struct {
  i_tiny_uart_t interface;
  tiny_event_t on_send_complete;
  tiny_event_t on_receive;
  volatile bool sending;
} self;

static void uart1_irq_handler(void)
{
  while(uart_is_readable(uart1)) {
    tiny_uart_on_receive_args_t args;
    uart_read_blocking(uart1, &args.byte, 1);
    tiny_event_publish(&self.on_receive, &args);
  }

  if(self.sending) {
    self.sending = false;
    tiny_event_publish(&self.on_send_complete, NULL);
  }
}

static void send(i_tiny_uart_t* _self, uint8_t byte)
{
  (void)_self;
  self.sending = true;
  uart_write_blocking(uart1, &byte, 1);
}

static i_tiny_event_t* on_send_complete(i_tiny_uart_t* _self)
{
  (void)_self;
  return &self.on_send_complete.interface;
}

static i_tiny_event_t* on_receive(i_tiny_uart_t* _self)
{
  (void)_self;
  return &self.on_receive.interface;
}

static const i_tiny_uart_api_t api = { send, on_send_complete, on_receive };

i_tiny_uart_t* tiny_uart1_init(unsigned baudrate, unsigned rx, unsigned tx)
{
  self.interface.api = &api;

  gpio_set_function(rx, GPIO_FUNC_UART);
  gpio_set_function(tx, GPIO_FUNC_UART);

  tiny_event_init(&self.on_send_complete);
  tiny_event_init(&self.on_receive);

  uart_init(uart1, baudrate);
  irq_set_exclusive_handler(UART1_IRQ, uart1_irq_handler);
  irq_set_enabled(UART1_IRQ, true);
  uart_set_irq_enables(uart1, true, true);

  return &self.interface;
}
