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
*/

#include "leds.h"
#include "leds_private.h"  // Para constantes de testing
#include "mock_errores.h"  // Mock generado automáticamente por Ceedling
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
    registrar_error_ExpectAnyArgs();
    leds_turn_on(0);
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);

    registrar_error_ExpectAnyArgs();
    leds_turn_on(CANTIDAD_DE_LEDS + 1);
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);
}

// prender todos los leds
void test_LedsDriver_PrenderTodosLosLeds(void)
{
    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_PRENDIDOS, puerto_virtual);
}

// prender y apagar todos los leds
void test_LedsDriver_PrenderYApagarTodosLosLeds(void)
{
    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_PRENDIDOS, puerto_virtual);

    leds_turn_off_all();
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);
}

// prender algunos leds mas de una vez y verificar que sigue prendido
void test_LedsDriver_PrenderLedVariasVeces(void)
{
    leds_turn_on(5);
    leds_turn_on(5);                                  // Prender de nuevo
    leds_turn_on(5);                                  // Y otra vez
    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);  // Debe seguir prendido solo ese LED
}

// apagar algunos leds mas de una vez y verificar que siguen apagados
void test_LedsDriver_ApagarLedVariasVeces(void)
{
    leds_turn_on(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);

    leds_turn_off(3);
    leds_turn_off(3);  // Apagar de nuevo
    leds_turn_off(3);  // Y otra vez
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);
}

// prender algunos leds, despues prender todos y comprobar que todos los leds quedan prendidos
void test_LedsDriver_PrenderAlgunosLuegoTodos(void)
{
    leds_turn_on(2);
    leds_turn_on(5);
    TEST_ASSERT_EQUAL_HEX16((1 << 1) | (1 << 4), puerto_virtual);

    leds_turn_on_all();  // Prender todos
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_PRENDIDOS, puerto_virtual);
}

// prender todos, apagar algunos, apagar todos y comprobar que todos los leds quedan apagados
void test_LedsDriver_PrenderTodosApagarAlgunosApagarTodos(void)
{
    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_PRENDIDOS, puerto_virtual);

    leds_turn_off(3);
    leds_turn_off(7);
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_PRENDIDOS & ~((1 << 2) | (1 << 6)), puerto_virtual);

    leds_turn_off_all();
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);
}

// consultar el estado de un led encendido y comprobar que es correcto
void test_LedsDriver_ConsultarLedEncendido(void)
{
    leds_turn_on(4);
    TEST_ASSERT_TRUE(leds_is_on(4));
    TEST_ASSERT_FALSE(leds_is_off(4));
}

// consultar el estado de un led apagado y comprobar que es correcto
void test_LedsDriver_ConsultarLedApagado(void)
{
    leds_turn_off(6);  // Asegurar que está apagado
    TEST_ASSERT_TRUE(leds_is_off(6));
    TEST_ASSERT_FALSE(leds_is_on(6));
}

// test para leds_turn_off con numeros invalidos
void test_LedsDriver_ApagarLedFueraDeRango(void)
{
    registrar_error_ExpectAnyArgs();
    leds_turn_off(0);
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);

    registrar_error_ExpectAnyArgs();
    leds_turn_off(CANTIDAD_DE_LEDS + 1);
    TEST_ASSERT_EQUAL_HEX16(TODO_LOS_LEDS_APAGADOS, puerto_virtual);
}

// test para leds_is_on con numeros invalidos
void test_LedsDriver_ConsultarLedEncendidoFueraDeRango(void)
{
    registrar_error_ExpectAnyArgs();
    bool result = leds_is_on(0);
    TEST_ASSERT_FALSE(result);

    registrar_error_ExpectAnyArgs();
    result = leds_is_on(CANTIDAD_DE_LEDS + 1);
    TEST_ASSERT_FALSE(result);
}

// test para leds_is_off con numeros invalidos
void test_LedsDriver_ConsultarLedApagadoFueraDeRango(void)
{
    registrar_error_ExpectAnyArgs();
    bool result = leds_is_off(0);
    TEST_ASSERT_FALSE(result);

    registrar_error_ExpectAnyArgs();
    result = leds_is_off(CANTIDAD_DE_LEDS + 1);
    TEST_ASSERT_FALSE(result);
}
