#ifndef ERRORES_H
#define ERRORES_H

typedef enum gravedad_e { ERROR, ALERTA, INFORMACION, DEPURACION } gravedad_t;

void registrar_error(gravedad_t gravedad, const char* funcion, int linea, const char* mensaje);

#endif  // ERRORES_H
