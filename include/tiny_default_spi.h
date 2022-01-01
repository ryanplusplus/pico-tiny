/*!
 * @file
 * @brief
 */

#ifndef tiny_default_spi_h
#define tiny_default_spi_h

#include "tiny_spi.h"

i_tiny_spi_t* tiny_default_spi_init(
  unsigned baudrate,
  spi_cpha_t cpha,
  spi_cpol_t cpol,
  spi_order_t order);

#endif
