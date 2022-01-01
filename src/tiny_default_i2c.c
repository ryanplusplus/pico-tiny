/*!
 * @file
 * @brief
 */

#include "tiny_default_i2c.h"
#include "pico/stdlib.h"

#ifdef PICO_DEFAULT_I2C

static tiny_i2c_t self;

i_tiny_i2c_t* tiny_default_i2c_init(unsigned baudrate)
{
  return tiny_i2c_init(
    &self,
    i2c##PICO_DEFAULT_I2C##_inst,
    baudrate,
    PICO_DEFAULT_I2C_SDA_PIN,
    PICO_DEFAULT_I2C_SCL_PIN);
}

#endif
