/*!
 * @file
 * @brief
 */

#include "pico/stdlib.h"
#include "tiny_heartbeat.h"

#ifdef PICO_DEFAULT_LED_PIN

static void blink(void* context)
{
  (void)context;
  static bool state;
  gpio_put(PICO_DEFAULT_LED_PIN, state = !state);
}

void tiny_heartbeat_init(tiny_timer_group_t* timer_group)
{
  gpio_init(PICO_DEFAULT_LED_PIN);
  gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

  static tiny_timer_t tiny_heartbeat_timer;
  tiny_timer_start_periodic(timer_group, &tiny_heartbeat_timer, 500, NULL, blink);
}

#endif
