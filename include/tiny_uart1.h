/*!
 * @file
 * @brief
 */

#ifndef tiny_uart1_h
#define tiny_uart1_h

#include "hal/i_tiny_uart.h"

i_tiny_uart_t* tiny_uart1_init(unsigned baudrate, unsigned rx, unsigned tx);

#endif
