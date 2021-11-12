#ifndef INPUT_H_
#define INPUT_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int Get_Int(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);

int IngresarNumero(int* pResultado);

int esNumerica(char* cadena);

int myGets(char* cadena, int longitud);

int IngresarCadena(char* pResultado, char* mensaje, char* mensajeError, int tam);

int GetCadena(char pResultado[], int tam);

int esAlfabetico (char cadena[],int tam);

int TransformarCadena(char cadena[],int len);

#endif /* INPUT_H_ */
