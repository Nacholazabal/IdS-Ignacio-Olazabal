#!/bin/bash
# Script para correr tests con Ceedling y mostrar resumen minimalista

set -e

LOGDIR=".test_logs"
mkdir -p "$LOGDIR"
BUILD_LOG="$LOGDIR/build.log"
TEST_LOG="$LOGDIR/test.log"
SUMMARY="$LOGDIR/summary.log"

# Colores ANSI
GREEN='\033[0;32m'
NC='\033[0m' # Sin color

# Limpiar logs previos
rm -f "$BUILD_LOG" "$TEST_LOG" "$SUMMARY"

# Ejecutar build y tests, guardar output
ceedling test:all > "$TEST_LOG" 2>&1 || true

# Extraer resumen de resultados
awk '/^Running test_.*\.out\./ {print $0} /PASS|FAIL/ {print $0}' "$TEST_LOG" > "$SUMMARY"

# Mostrar resumen con colores
echo "\nResumen de tests:"
while read -r line; do
    if [[ "$line" == *PASS* ]]; then
        echo -e "${GREEN}$line${NC}"
    else
        echo "$line"
    fi
done < "$SUMMARY"

# Mostrar ubicación de logs
if grep -q FAIL "$SUMMARY"; then
    echo -e "\nAlgunos tests fallaron. Ver detalles en $TEST_LOG"
else
    echo -e "\nTodos los tests pasaron. Ver detalles en $TEST_LOG"
fi

# Si se pasa -c, correr coverage
if [[ "$1" == "-c" ]]; then
    echo -e "\nEjecutando cobertura..."
    ./scripts/coverage.sh
fi
