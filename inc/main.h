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

#ifndef MAIN_H
#define MAIN_H

/** \brief Main Application Header File
 **
 ** This file contains the main application definitions and function declarations.
 ** It includes system initialization and main program flow control.
 **
 ** \addtogroup main Main Application
 ** \brief Main program and system initialization
 ** @{ */

/* === Headers files inclusions ================================================================ */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <unistd.h>

#include "gpio.h"

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/** \brief Application version */
#define APP_VERSION_MAJOR  1
#define APP_VERSION_MINOR  0
#define APP_VERSION_PATCH  0

/** \brief Demo delay in seconds */
#define DEMO_DELAY_SECONDS 1

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * \brief Initialize the application
 *
 * This function initializes all system components including GPIO,
 * peripherals, and displays startup information.
 *
 * \return true if initialization was successful, false otherwise
 */
bool app_init(void);

/**
 * \brief Run the main application demo
 *
 * This function runs a demonstration of the LED control system,
 * showing various GPIO operations and LED patterns.
 */
void app_run_demo(void);

/**
 * \brief Display application information
 *
 * This function displays application version and system information.
 */
void app_display_info(void);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* MAIN_H */
