/*!
 * @file
 * @brief
 */

#ifndef tiny_default_uart_h
#define tiny_default_uart_h

#include "hardware/uart.h"
#include "tiny_uart0.h"
#include "tiny_uart1.h"
#include "tiny_utils.h"

#ifdef uart_default

static inline i_tiny_uart_t* tiny_default_uart_init(unsigned baudrate)
{
  return tiny_concat(tiny_concat(tiny_uart, PICO_DEFAULT_UART), _init)(
    baudrate,
    PICO_DEFAULT_UART_RX_PIN,
    PICO_DEFAULT_UART_TX_PIN);
}

#endif

#endif
