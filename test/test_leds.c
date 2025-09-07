/*
prender un led y apagarlo en ambos extremos
prender todos los leds
prender y apagar todos los leds
prender algunos leds mas de una vez y verificar que sigue prendido
apagar algunos leds mas de una vez y verificar que siguen apagados
prender algunos leds, despues prender todos y comprobar que todos los leds quedan prendidos
prender todos, apagar algunos, apagar todos y comprobar que todos los leds quedan apagados
consultar el estado de un led encendido y comprobar que es correcto
consultar el estado de un led apagado y comprobar que es correcto
tratar de manipular un led fuera de rango y comprobar que se genera un error
*/

#include "leds.h"
#include "leds_private.h"  // Para constantes de testing
#include "unity.h"

static uint16_t puerto_virtual;  // Esto es un mockup del puerto de HW

void setUp(void)
{
    puerto_virtual = TODO_LOS_LEDS_APAGADOS;
    leds_init(&puerto_virtual);
}

void tearDown(void)
{
}

// iniciar el driver y revisar que todos los leds esten apagados
void test_LedsDriver_IniciaConTodosLosLedsApagados(void)
{
    puerto_virtual = 0xFFFF;  // Esto es un mockup del puerto de HW
    leds_init(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);
}

// prender un led y verificar que no cambia el resto
void test_LedsDriver_PrendeUnLed(void)
{
    leds_turn_on(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// prender un led y apagarlo cualquiera
void test_LedsDriver_PrendeYApagaUnLed(void)
{
    leds_turn_on(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
    leds_turn_off(5);
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);
}

// prender mas de un led, apagar uno y verificar que el resto siguen sin cambio
void test_LedsDriver_PrendeVariosYApagaUno(void)
{
    leds_turn_on(2);
    leds_turn_on(4);
    leds_turn_on(6);
    TEST_ASSERT_EQUAL_HEX16((1 << 1) | (1 << 3) | (1 << 5), puerto_virtual);
    leds_turn_off(4);
    TEST_ASSERT_EQUAL_HEX16((1 << 1) | (1 << 5), puerto_virtual);
}

// prender un led en ambos extremos y verificar que funciona
void test_LedsDriver_PrenderPrimerYUltimoLed(void)
{
    leds_turn_on(PRIMER_LED);
    TEST_ASSERT_EQUAL_HEX16(1 << 0, puerto_virtual);

    leds_turn_on(ULTIMO_LED);
    TEST_ASSERT_EQUAL_HEX16((1 << 0) | (1 << 15), puerto_virtual);
}

// tratar de manipular un led fuera de rango y comprobar que no cambia nada
void test_LedsDriver_LedFueraDeRangoNoHaceNada(void)
{
    leds_turn_on(LED_INVALIDO_BAJO);
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);

    leds_turn_on(LED_INVALIDO_ALTO);
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);
}
