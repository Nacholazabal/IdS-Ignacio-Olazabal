#include "leds.h"

#include "errores.h"

#define CANTIDAD_DE_LEDS        16
#define TODO_LOS_LEDS_APAGADOS  0x0000
#define TODO_LOS_LEDS_PRENDIDOS 0xFFFF
#define PRIMER_LED              1
#define LED_A_BIT_OFFSET        1

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
    if (led_number < 1 || led_number > CANTIDAD_DE_LEDS) {
        registrar_error(ERROR, __func__, __LINE__, "Número de LED inválido");
        return;  // Manejo de error simple, no hacer nada si está fuera de rango
    }

    *puerto |= leds_to_mask(led_number);  // Prender el LED correspondiente
}

void leds_turn_off(int led_number)
{
    if (led_number < 1 || led_number > CANTIDAD_DE_LEDS) {
        registrar_error(ERROR, __func__, __LINE__, "Número de LED inválido");
        return;
    }

    *puerto &= ~leds_to_mask(led_number);  // Apagar el LED correspondiente
}

void leds_turn_on_all(void)
{
    *puerto = 0xFFFF;  // Prender todos los 16 LEDs
}

void leds_turn_off_all(void)
{
    *puerto = TODO_LOS_LEDS_APAGADOS;  // Apagar todos los LEDs
}

bool leds_is_on(int led_number)
{
    if (led_number < 1 || led_number > CANTIDAD_DE_LEDS) {
        registrar_error(ERROR, __func__, __LINE__, "Número de LED inválido");
        return false;
    }

    return (*puerto & leds_to_mask(led_number)) != 0;
}

bool leds_is_off(int led_number)
{
    if (led_number < 1 || led_number > CANTIDAD_DE_LEDS) {
        registrar_error(ERROR, __func__, __LINE__, "Número de LED inválido");
        return false;
    }

    return (*puerto & leds_to_mask(led_number)) == 0;
}
