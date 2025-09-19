# C Style Guide (Embedded)

This guide summarizes the conventions enforced by `.clang-format` and complements it with rules that the formatter cannot enforce.

## 1) Naming
- **Functions:** `lower_snake_case`
- **Types (struct/enum/typedef):** `PascalCase`
- **Macros & constants:** `UPPER_SNAKE_CASE` (optionally add project prefix, e.g., `LOOP_`)

## 2) Files & includes
- One module per pair: `foo.h` / `foo.c`.
- Header guards: `#ifndef PROJECT_FOO_H` … `#define` … `#endif`.
- `#include` order (and alphabetic **within** each group):
  1. C standard headers (`<stdint.h>`, `<stdbool.h>`, …)
  2. External/system/SDK headers (`<stm32f4xx_hal.h>`, etc.)
  3. Project headers (`"foo.h"`)
- `clang-format` will sort and regroup automatically.

## 3) Braces & layout
- **Functions:** Allman (opening brace on a new line).
- **Control statements:** K&R (brace on the same line).
- **No** one-line `if/for/while` or functions.
- Max line length **100**. Avoid horizontal scrolling.

## 4) Spacing & pointers
- `if (cond)` and `for (...)` (space before parens in control). Calls as `foo(x)`.
- Pointers: `int *p;` (asterisk binds to the type).

## 5) Macros
- Prefer `static inline` functions for complex behavior. For simple constants use `#define NAME VALUE`.
- Consecutive macros are **aligned**: names and values on the same column.

```c
#define FOO_MAX_COUNT    16
#define FOO_TIMEOUT_MS   250
#define LOOP_ENABLE_LOG  1
```

## 6) Types & portability
- Always include `<stdint.h>` and `<stdbool.h>`.
- Prefer fixed-width integer types (`uint32_t`).
- Endianness: be explicit in conversions; use helper functions where possible.

## 7) Errors & control flow
- Use an `enum` of error codes and **return** them; avoid `assert` in production paths.
- Common pattern with single `cleanup` label:

```c
typedef enum {
    ERR_OK = 0,
    ERR_BAD_ARG,
    ERR_TIMEOUT,
    ERR_IO,
} ErrorCode;

ErrorCode driver_init(Device *dev)
{
    ErrorCode err = ERR_OK;

    if (dev == NULL) {
        err = ERR_BAD_ARG;
        goto cleanup;
    }

    // work...
    // if (something_failed) { err = ERR_IO; goto cleanup; }

cleanup:
    return err;
}
```

## 8) Concurrency & ISRs
- ISRs: mínimos, no bloqueantes, sin asignar memoria, sin printf.
- Protege datos compartidos (secciones críticas, atomics, o deshabilitar IRQs brevemente).

## 9) `const` y `volatile` (resumen práctico)
- **`const`**: marca datos solo-lectura; úsalo para parámetros que no se modifican.
- **`volatile`**: para **registros de hardware** y datos modificados por **ISRs/DMA**.
  - Ej.: `volatile uint32_t * const UART_DR = (uint32_t*)0x40011004;`

## 10) Documentación (Doxygen)
- Estilo preferido: `/** ... */` **en todas** las funciones (API pública e internas).
- Plantilla:

```c
/**
 * @brief  Initializes foo with the given configuration.
 * @param  foo   Pointer to foo instance (must be non-NULL).
 * @param  cfg   Configuration parameters.
 * @return ERR_OK on success, error code otherwise.
 */
ErrorCode foo_init(Foo *foo, const FooConfig *cfg);
```

## 11) Memory usage
- En embebidos, evitar `malloc/free` en tiempo de ejecución **cuando sea posible**.
- Si se usan, define límites claros y revisa fallos de asignación.
