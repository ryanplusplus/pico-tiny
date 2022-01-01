/*!
 * @file
 * @brief
 */

#ifndef tiny_default_uart_h
#define tiny_default_uart_h

#include "tiny_uart0.h"
#include "tiny_uart1.h"

#ifdef uart_default

static inline i_tiny_uart_t* tiny_uart_default_init(unsigned baudrate)
{
  return tiny_uart##PICO_DEFAULT_UART##_init(baudrate);
}

#endif

#endif
