#include "leds.h"

static uint16_t* puerto;

void             leds_init(uint16_t* puerto_virtual)
{
    puerto  = puerto_virtual;
    *puerto = 0x0000;  // Inicializar todos los LEDs apagados
}

void leds_turn_on(int led_number)
{
    if (led_number < 1 || led_number > 16)
        return;  // Manejo de error simple, no hacer nada si está fuera de rango

    *puerto |= (1 << (led_number - 1));  // Prender el LED correspondiente
}

void leds_turn_off(int led_number)
{
    if (led_number < 1 || led_number > 16)
        return;  // Manejo de error simple, no hacer nada si está fuera de rango

    *puerto &= ~(1 << (led_number - 1));  // Apagar el LED correspondiente
}
