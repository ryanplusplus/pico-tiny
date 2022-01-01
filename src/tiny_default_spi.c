/*!
 * @file
 * @brief
 */

#include "tiny_default_spi.h"

#ifdef spi_default

static tiny_spi_t self;

i_tiny_spi_t* tiny_default_spi_init(
  unsigned baudrate,
  spi_cpha_t cpha,
  spi_cpol_t cpol,
  spi_order_t order)
{
  tiny_spi_init(
    &self,
    spi_default,
    baudrate,
    cpha,
    cpol,
    order,
    PICO_DEFAULT_SPI_RX_PIN,
    PICO_DEFAULT_SPI_TX_PIN,
    PICO_DEFAULT_SPI_SCK_PIN);
}

#endif
