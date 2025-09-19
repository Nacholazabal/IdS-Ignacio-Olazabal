# Repositorio de Ingeniería de Software y Testing de Software (cohorte 2025)

[![CI/CD Pipeline](https://github.com/Nacholazabal/IdS-Ignacio-Olazabal/actions/workflows/ci.yml/badge.svg)](https://github.com/Nacholazabal/IdS-Ignacio-Olazabal/actions/workflows/ci.yml)
[![codecov](https://codecov.io/gh/Nacholazabal/IdS-Ignacio-Olazabal/branch/main/graph/badge.svg)](https://codecov.io/gh/Nacholazabal/IdS-Ignacio-Olazabal)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

> **Materia:** Ingeniería de Software (2024) y Testing de Software (2025)
> **Alumno:** Ignacio Olazabal
> **Propósito:** Este repositorio fue creado para la materia de Ingeniería de Software y está siendo reutilizado para la materia de Testing de Software del cohorte 2025.

---

## 🚀 Requisitos y Dependencias

Para poder clonar, compilar y ejecutar los tests de este proyecto necesitas instalar:

- **Git**
- **Ruby** (>= 3.1)
- **Ceedling** (`gem install ceedling`)
- **gcc** (compilador C)
- **lcov** (para reportes de cobertura)
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
pip install pre-commit
```

## 📊 Cobertura actual

El estado de cobertura se actualiza automáticamente:

![codecov](https://codecov.io/gh/Nacholazabal/IdS-Ignacio-Olazabal/branch/main/graph/badge.svg)

---

## 🤖 Comentarios automáticos en Pull Requests

Cada vez que se abre un Pull Request, el pipeline de CI/CD ejecuta los tests y genera un comentario automático en el PR indicando:
- El impacto del PR sobre la cobertura de código
- El porcentaje de cobertura antes y después
- Si la cobertura subió, bajó o se mantuvo
- Enlaces a los reportes completos

Esto se realiza mediante la integración de [Codecov](https://codecov.io/) y GitHub Actions. No requiere configuración adicional, solo tener el workflow y el archivo `codecov.yml` presentes.
