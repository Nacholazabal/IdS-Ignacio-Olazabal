#include "leds.h"

#define CANTIDAD_DE_LEDS       16
#define TODO_LOS_LEDS_APAGADOS 0x0000
#define PRIMER_LED             1
#define LED_A_BIT_OFFSET       1

static uint16_t* puerto;

static uint16_t leds_to_mask(int led_number)
{
    return PRIMER_LED << (led_number - LED_A_BIT_OFFSET);
}

void leds_init(uint16_t* puerto_virtual)
{
    puerto  = puerto_virtual;
    *puerto = TODO_LOS_LEDS_APAGADOS;  // Inicializar todos los LEDs apagados
}

void leds_turn_on(int led_number)
{
    if (led_number < 1 || led_number > CANTIDAD_DE_LEDS)
        return;  // Manejo de error simple, no hacer nada si está fuera de rango

    *puerto |= leds_to_mask(led_number);  // Prender el LED correspondiente
}

void leds_turn_off(int led_number)
{
    if (led_number < 1 || led_number > CANTIDAD_DE_LEDS)
        return;  // Manejo de error simple, no hacer nada si está fuera de rango

    *puerto &= ~leds_to_mask(led_number);  // Apagar el LED correspondiente
}
