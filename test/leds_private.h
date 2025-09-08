#ifndef LEDS_PRIVATE_H
#define LEDS_PRIVATE_H

#include <stdint.h>

// Defines internos solo para testing
#define CANTIDAD_DE_LEDS        16
#define TODO_LOS_LEDS_APAGADOS  0x0000
#define TODO_LOS_LEDS_PRENDIDOS 0xFFFF
#define PRIMER_LED              1
#define LED_A_BIT_OFFSET        1
#define ULTIMO_LED              CANTIDAD_DE_LEDS
#define LED_INVALIDO_BAJO       0
#define LED_INVALIDO_ALTO       (CANTIDAD_DE_LEDS + 1)

#endif  // LEDS_PRIVATE_H
