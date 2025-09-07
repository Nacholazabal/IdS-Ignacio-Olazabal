/************************************************************************************************
Copyright (c) 2024, Ignacio Olazabal

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** \brief GPIO Module Implementation
 **
 ** This file implements the GPIO functions for LED control simulation.
 ** All LED operations are simulated through console output for demonstration purposes.
 **
 ** \addtogroup gpio GPIO Module
 ** \brief LED control through simulated GPIO operations
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "gpio.h"

#include <stdio.h>
#include <string.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/** \brief Array to store the current state of all LEDs */
static led_state_t led_states[MAX_LEDS];

/** \brief Array with LED names for display purposes */
static const char* led_names[MAX_LEDS] = {"RED", "GREEN", "BLUE", "YELLOW"};

/** \brief Flag to indicate if GPIO module has been initialized */
static bool        gpio_initialized    = false;

/* === Private function declarations =========================================================== */

/**
 * \brief Validate LED identifier
 *
 * This function checks if the provided LED identifier is valid.
 *
 * \param[in] led_id LED identifier to validate
 * \return true if LED ID is valid, false otherwise
 */
static bool        is_valid_led_id(uint8_t led_id);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static bool        is_valid_led_id(uint8_t led_id)
{
    return (led_id < MAX_LEDS);
}

/* === Public function implementation ========================================================== */

bool gpio_init(void)
{
    printf("[GPIO] Initializing GPIO module...\n");

    // Initialize all LEDs to OFF state
    for (int i = 0; i < MAX_LEDS; i++) {
        led_states[i] = LED_OFF;
    }

    gpio_initialized = true;
    printf("[GPIO] GPIO module initialized successfully\n");
    printf("[GPIO] All LEDs set to OFF state\n");

    return true;
}

bool gpio_led_on(uint8_t led_id)
{
    if (!gpio_initialized) {
        printf("[GPIO] ERROR: GPIO module not initialized\n");
        return false;
    }

    if (!is_valid_led_id(led_id)) {
        printf("[GPIO] ERROR: Invalid LED ID %d\n", led_id);
        return false;
    }

    led_states[led_id] = LED_ON;
    printf("[GPIO] LED %s turned ON\n", led_names[led_id]);

    return true;
}

bool gpio_led_off(uint8_t led_id)
{
    if (!gpio_initialized) {
        printf("[GPIO] ERROR: GPIO module not initialized\n");
        return false;
    }

    if (!is_valid_led_id(led_id)) {
        printf("[GPIO] ERROR: Invalid LED ID %d\n", led_id);
        return false;
    }

    led_states[led_id] = LED_OFF;
    printf("[GPIO] LED %s turned OFF\n", led_names[led_id]);

    return true;
}

bool gpio_led_toggle(uint8_t led_id)
{
    if (!gpio_initialized) {
        printf("[GPIO] ERROR: GPIO module not initialized\n");
        return false;
    }

    if (!is_valid_led_id(led_id)) {
        printf("[GPIO] ERROR: Invalid LED ID %d\n", led_id);
        return false;
    }

    if (led_states[led_id] == LED_ON) {
        led_states[led_id] = LED_OFF;
        printf("[GPIO] LED %s toggled to OFF\n", led_names[led_id]);
    } else {
        led_states[led_id] = LED_ON;
        printf("[GPIO] LED %s toggled to ON\n", led_names[led_id]);
    }

    return true;
}

led_state_t gpio_led_get_state(uint8_t led_id)
{
    if (!gpio_initialized) {
        printf("[GPIO] ERROR: GPIO module not initialized\n");
        return LED_OFF;
    }

    if (!is_valid_led_id(led_id)) {
        printf("[GPIO] ERROR: Invalid LED ID %d\n", led_id);
        return LED_OFF;
    }

    return led_states[led_id];
}

bool gpio_all_leds_off(void)
{
    if (!gpio_initialized) {
        printf("[GPIO] ERROR: GPIO module not initialized\n");
        return false;
    }

    printf("[GPIO] Turning off all LEDs...\n");

    for (int i = 0; i < MAX_LEDS; i++) {
        led_states[i] = LED_OFF;
    }

    printf("[GPIO] All LEDs turned OFF\n");
    return true;
}

void gpio_display_status(void)
{
    if (!gpio_initialized) {
        printf("[GPIO] ERROR: GPIO module not initialized\n");
        return;
    }

    printf("[GPIO] LED Status:\n");
    printf("  +----------+--------+\n");
    printf("  |   LED    | STATE  |\n");
    printf("  +----------+--------+\n");

    for (int i = 0; i < MAX_LEDS; i++) {
        printf("  | %-8s | %-6s |\n", led_names[i], (led_states[i] == LED_ON) ? "ON" : "OFF");
    }

    printf("  +----------+--------+\n");
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
