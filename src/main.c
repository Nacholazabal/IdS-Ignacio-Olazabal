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

/** \brief Main Application Implementation
 **
 ** This file implements the main application logic including system initialization,
 ** LED control demonstration, and program flow control.
 **
 ** \addtogroup main Main Application
 ** \brief Main program and system initialization
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "main.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

bool app_init(void) {
    printf("=================================================\n");
    printf("       LED Control System - Hello World         \n");
    printf("=================================================\n");
    printf("[MAIN] Starting system initialization...\n");
    
    // Initialize GPIO module
    if (!gpio_init()) {
        printf("[MAIN] ERROR: Failed to initialize GPIO module\n");
        return false;
    }
    
    printf("[MAIN] System initialized successfully\n");
    printf("[MAIN] Ready to run LED control demo\n");
    
    return true;
}

void app_display_info(void) {
    printf("\n[INFO] Application Information:\n");
    printf("  - Name: LED Control Demo\n");
    printf("  - Version: %d.%d.%d\n", 
           APP_VERSION_MAJOR, APP_VERSION_MINOR, APP_VERSION_PATCH);
    printf("  - Author: Ignacio Olazabal\n");
    printf("  - Course: Ingeniería de Software 2024\n");
    printf("  - Description: GPIO LED control simulation\n");
}

void app_run_demo(void) {
    printf("\n[DEMO] Starting LED control demonstration...\n");
    
    // Display initial status
    gpio_display_status();
    sleep(DEMO_DELAY_SECONDS);
    
    // Turn on LEDs one by one
    printf("\n[DEMO] Turning on LEDs sequentially...\n");
    gpio_led_on(LED_RED);
    sleep(DEMO_DELAY_SECONDS);
    
    gpio_led_on(LED_GREEN);
    sleep(DEMO_DELAY_SECONDS);
    
    gpio_led_on(LED_BLUE);
    sleep(DEMO_DELAY_SECONDS);
    
    gpio_led_on(LED_YELLOW);
    sleep(DEMO_DELAY_SECONDS);
    
    // Display status with all LEDs on
    printf("\n[DEMO] All LEDs should be ON now:\n");
    gpio_display_status();
    sleep(DEMO_DELAY_SECONDS);
    
    // Toggle some LEDs
    printf("\n[DEMO] Toggling some LEDs...\n");
    gpio_led_toggle(LED_RED);
    gpio_led_toggle(LED_BLUE);
    sleep(DEMO_DELAY_SECONDS);
    
    gpio_display_status();
    sleep(DEMO_DELAY_SECONDS);
    
    // Turn off specific LEDs
    printf("\n[DEMO] Turning off GREEN and YELLOW LEDs...\n");
    gpio_led_off(LED_GREEN);
    gpio_led_off(LED_YELLOW);
    sleep(DEMO_DELAY_SECONDS);
    
    gpio_display_status();
    sleep(DEMO_DELAY_SECONDS);
    
    // Turn off all LEDs
    printf("\n[DEMO] Turning off all LEDs...\n");
    gpio_all_leds_off();
    sleep(DEMO_DELAY_SECONDS);
    
    gpio_display_status();
    
    printf("\n[DEMO] LED control demonstration completed!\n");
}

/**
 * \brief Main function
 * 
 * This is the main entry point of the application. It initializes
 * the system, displays application information, and runs the LED demo.
 * 
 * \return 0 on success, non-zero on error
 */
int main(void) {
    // Display application information
    app_display_info();
    
    // Initialize the application
    if (!app_init()) {
        printf("[MAIN] ERROR: Application initialization failed\n");
        return 1;
    }
    
    // Run the LED control demonstration
    app_run_demo();
    
    printf("\n[MAIN] Application finished successfully\n");
    printf("=================================================\n");
    
    return 0;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */