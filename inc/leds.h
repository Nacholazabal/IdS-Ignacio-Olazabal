#include <stdbool.h>
#include <stdint.h>

void leds_init(uint16_t* puerto_virtual);

void leds_turn_on(int led_number);
void leds_turn_off(int led_number);

void leds_turn_on_all(void);
void leds_turn_off_all(void);

bool leds_is_on(int led_number);
bool leds_is_off(int led_number);
