#include "leds.h"

void leds_init(uint16_t* puerto_virtual)
{
    *puerto_virtual = 0x0000;  // Inicializar todos los LEDs apagados
}
