# Repositorio de Ingeniería de Software y Testing de Software (cohorte 2025)

[![CI/CD Pipeline](https://github.com/Nacholazabal/IdS-Ignacio-Olazabal/actions/workflows/ci.yml/badge.svg)](https://github.com/Nacholazabal/IdS-Ignacio-Olazabal/actions/workflows/ci.yml)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

> **Materia:** Ingeniería de Software (2025) y Testing de Software (2025)
> **Alumno:** Ignacio Olazabal
> **Propósito:** Este repositorio fue creado para la materia de Ingeniería de Software y está siendo reutilizado para la materia de Testing de Software del cohorte 2025.

---

## Requisitos y Dependencias

Para poder clonar, compilar y ejecutar los tests de este proyecto necesitas instalar:

- **Git**
- **Ruby** (>= 3.1)
- **Ceedling** (`gem install ceedling`)
- **gcc** (compilador C)
- **lcov** (para reportes de cobertura)
- **gcovr** (para reportes de cobertura)
- **clang-format** (formateo de código)
- **clang-tidy** (análisis estático)
- **cppcheck** (análisis estático)
- **pre-commit** (`pip install pre-commit`)
- **VS Code** (opcional, recomendado)
- **Extensiones VS Code:**
  - C/C++ Extension Pack
  - clang-format

### Instalación rápida en Ubuntu

```bash
sudo apt update
sudo apt install -y build-essential ruby gcc lcov clang-format clang-tidy cppcheck git
sudo gem install ceedling
pip install pre-commit gcovr
```

---

## Testing y Cobertura de Código

Este proyecto utiliza **TDD (Test-Driven Development)** con las siguientes herramientas:

- **Framework de testing:** Unity + CMock + Ceedling
- **Cobertura:** gcov + gcovr + lcov
- **Total de tests:** 17 tests unitarios
- **Cobertura actual:** 100% líneas y funciones

### Scripts disponibles

#### `./scripts/test.sh` - Ejecutar solo tests

Este script ejecuta únicamente los tests unitarios sin generar reportes de cobertura:

```bash
./scripts/test.sh
```

**¿Qué hace?**

- Limpia artefactos de builds anteriores
- Compila el código fuente y tests
- Ejecuta todos los tests unitarios
- Muestra el resultado (PASS/FAIL) de cada test
- **Uso:** Desarrollo rápido, verificación básica

#### `./scripts/coverage.sh` - Tests + Cobertura completa

Este script ejecuta los tests Y genera reportes detallados de cobertura:

```bash
./scripts/coverage.sh
```

**¿Qué hace?**

- Ejecuta todos los tests unitarios
- Compila con flags de cobertura (`--coverage`)
- Genera múltiples formatos de reporte:
  - **Texto:** `build/artifacts/gcov/gcovr/coverage.txt`
  - **HTML Ceedling:** `build/artifacts/gcov/gcovr/GcovCoverageResults.html`
  - **HTML lcov:** `coverage/html/index.html`
- Muestra resumen en terminal con porcentajes
- **Uso:** Análisis detallado, CI/CD, verificación de cobertura

#### Ver reportes HTML localmente

Después de ejecutar `./scripts/coverage.sh`:

```bash
# Opción 1: Reporte lcov (más detallado)
firefox coverage/html/index.html

# Opción 2: Reporte Ceedling
firefox build/artifacts/gcov/gcovr/GcovCoverageResults.html
```

---

## CI/CD y Artifacts

### Ejecución automática en GitHub Actions

El pipeline de CI/CD ejecuta automáticamente:

1. **Tests unitarios** usando `./scripts/coverage.sh`
2. **Análisis de cobertura** con reportes completos
3. **Análisis estático** (clang-format, clang-tidy, cppcheck)
4. **Comentarios automáticos** en Pull Requests

### Descargar reportes de cobertura desde GitHub

Los reportes de cobertura se generan en cada ejecución del CI/CD y están disponibles como **artifacts**:

#### Cómo descargar artifacts

1. **Ve a tu repositorio en GitHub**
2. **Click en el tab "Actions"**
3. **Selecciona un workflow run** (ej: el último commit)
4. **Scroll hacia abajo** hasta la sección **"Artifacts"**
5. **Descarga los ZIPs disponibles:**
   - `coverage-reports.zip` - Reportes HTML completos
   - `test-and-coverage-results.zip` - Archivos de texto y logs

#### Ver los reportes

1. **Descomprime** el ZIP descargado
2. **Abre** `coverage/html/index.html` en tu navegador
3. **Navega** por la cobertura línea por línea
4. **Identifica** qué código falta testear (líneas en rojo)
