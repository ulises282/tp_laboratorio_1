#include "funciones.c"
int get_int(int* Numero, char* mensaje, char* mensaje_error, int min, int max, int reintentos);
int getInt (int* resultado);
int esNumero(char* num);
////////////////////////////////////////////////////////////////////////////////
int get_float(float* Numero, char* mensaje, char* mensaje_error, float min, float max, int reintentos);
////////////////////////////////////////////////////////////////////////////////
int getChar(char* resultado, char* mensaje, char* mensaje_error, char min, char max, int reintentos);
////////////////////////////////////////////////////////////////////////////////
int getString(char* cadena, int longitud);
////////////////////////////////////////////////////////////////////////////////
int validarNombre (char* cadena, int len);
int getNombre (char* cadena);
int getHorasTrabajadas (char* cadena);
int getSueldo (char* cadena);
