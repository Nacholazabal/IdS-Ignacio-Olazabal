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

#ifndef GPIO_H
#define GPIO_H

/** \brief GPIO Module for LED Control
 **
 ** This module provides functions to control LEDs through GPIO simulation.
 ** All operations are simulated through console output.
 **
 ** \addtogroup gpio GPIO Module
 ** \brief LED control through simulated GPIO operations
 ** @{ */

/* === Headers files inclusions ================================================================ */

#include <stdbool.h>
#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/** \brief LED identifiers */
#define LED_RED    0 /*!< Red LED identifier */
#define LED_GREEN  1 /*!< Green LED identifier */
#define LED_BLUE   2 /*!< Blue LED identifier */
#define LED_YELLOW 3 /*!< Yellow LED identifier */

/** \brief Maximum number of LEDs */
#define MAX_LEDS   4

/* === Public data type declarations =========================================================== */

/** \brief LED state enumeration */
typedef enum {
    LED_OFF = 0, /*!< LED is turned off */
    LED_ON  = 1  /*!< LED is turned on */
} led_state_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * \brief Initialize the GPIO module
 *
 * This function initializes the GPIO module and sets up all LEDs
 * in the OFF state.
 *
 * \return true if initialization was successful, false otherwise
 */
bool gpio_init(void);

/**
 * \brief Turn on a specific LED
 *
 * This function turns on the specified LED. The operation is
 * simulated through console output.
 *
 * \param[in] led_id LED identifier (LED_RED, LED_GREEN, etc.)
 * \return true if LED was turned on successfully, false otherwise
 */
bool gpio_led_on(uint8_t led_id);

/**
 * \brief Turn off a specific LED
 *
 * This function turns off the specified LED. The operation is
 * simulated through console output.
 *
 * \param[in] led_id LED identifier (LED_RED, LED_GREEN, etc.)
 * \return true if LED was turned off successfully, false otherwise
 */
bool gpio_led_off(uint8_t led_id);

/**
 * \brief Toggle a specific LED
 *
 * This function toggles the state of the specified LED.
 * If the LED is on, it will be turned off, and vice versa.
 *
 * \param[in] led_id LED identifier (LED_RED, LED_GREEN, etc.)
 * \return true if LED was toggled successfully, false otherwise
 */
bool gpio_led_toggle(uint8_t led_id);

/**
 * \brief Get the current state of a LED
 *
 * This function returns the current state of the specified LED.
 *
 * \param[in] led_id LED identifier (LED_RED, LED_GREEN, etc.)
 * \return LED_ON if the LED is on, LED_OFF if it's off
 */
led_state_t gpio_led_get_state(uint8_t led_id);

/**
 * \brief Turn off all LEDs
 *
 * This function turns off all LEDs in the system.
 *
 * \return true if all LEDs were turned off successfully, false otherwise
 */
bool gpio_all_leds_off(void);

/**
 * \brief Display the status of all LEDs
 *
 * This function prints the current status of all LEDs to the console.
 */
void gpio_display_status(void);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* GPIO_H */
