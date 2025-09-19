#!/bin/bash

# Script para generar reportes de cobertura localmente
# Uso: ./scripts/coverage.sh

set -e

echo "🧪 Ejecutando tests con cobertura..."
ceedling clean
ceedling test:all
ceedling gcov:all

echo ""
echo "📊 Generando reportes adicionales con lcov..."

# Crear directorio de cobertura
mkdir -p coverage

# Buscar archivos de cobertura
echo "🔍 Buscando archivos de cobertura..."
find build -name "*.gcno" -exec cp {} coverage/ \; 2>/dev/null || true
find build -name "*.gcda" -exec cp {} coverage/ \; 2>/dev/null || true

# Verificar si encontramos archivos
if [ ! "$(ls -A coverage/*.gc* 2>/dev/null)" ]; then
    echo "⚠️  No se encontraron archivos de cobertura. Verificando directorio build..."
    ls -la build/
    find build -name "*.gc*" -ls
    
    # Intentar con una ruta más específica
    find build -name "*.gcno" -o -name "*.gcda" | while read file; do
        echo "Copiando: $file"
        cp "$file" coverage/
    done
fi

# Generar reporte lcov si tenemos archivos
if [ "$(ls -A coverage/*.gc* 2>/dev/null)" ]; then
    echo "📈 Generando reporte lcov..."
    
    # Capturar datos de cobertura
    lcov --capture --directory . --output-file coverage/coverage.info --ignore-errors source,unused
    
    # Filtrar archivos no deseados
    lcov --remove coverage/coverage.info '/usr/*' '*/test/*' '*/build/*' '*_runner.c' 'mock_*' '*unity*' '*cmock*' --output-file coverage/coverage_filtered.info --ignore-errors unused
    
    # Generar reporte HTML
    genhtml coverage/coverage_filtered.info --output-directory coverage/html --title "Cobertura de Código - LEDs Driver" --show-details --legend
    
    # Mostrar resumen
    echo ""
    echo "📋 RESUMEN DE COBERTURA:"
    echo "========================"
    lcov --list coverage/coverage_filtered.info
    
    echo ""
    echo "✅ Reportes generados:"
    echo "  📄 Texto: build/artifacts/gcov/gcovr/coverage.txt"
    echo "  🌐 HTML Ceedling: build/artifacts/gcov/gcovr/GcovCoverageResults.html"
    echo "  🌐 HTML lcov: coverage/html/index.html"
    echo ""
    echo "🚀 Para ver el reporte HTML:"
    echo "  firefox coverage/html/index.html"
else
    echo "❌ No se encontraron archivos de cobertura"
    echo "   Asegúrate de que los tests se ejecutaron correctamente"
fi

echo ""
echo "🎉 ¡Análisis de cobertura completado!"