/*!
 * @file
 * @brief
 */

#include "tiny_default_i2c.h"

#ifdef i2c_default

static tiny_i2c_t self;

i_tiny_i2c_t* tiny_default_i2c_init(unsigned baudrate)
{
  tiny_i2c_init(
    &self,
    i2c_default,
    baudrate,
    PICO_DEFAULT_I2C_SDA_PIN,
    PICO_DEFAULT_I2C_SCL_PIN);
}

#endif
