/*!
 * @file
 * @brief
 */

#include "tiny_default_spi.h"
#include "pico/stdlib.h"

#ifdef PICO_DEFAULT_SPI

static tiny_spi_t self;

i_tiny_spi_t* tiny_default_spi_init(
  unsigned baudrate,
  spi_cpha_t cpha,
  spi_cpol_t cpol,
  spi_order_t order)
{
  return tiny_spi_init(
    &self,
    spi##PICO_DEFAULT_SPI##_inst,
    baudrate,
    cpha,
    cpol,
    order,
    PICO_DEFAULT_SPI_RX_PIN,
    PICO_DEFAULT_SPI_TX_PIN,
    PICO_DEFAULT_SPI_SCK_PIN);
}

#endif
