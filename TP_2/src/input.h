/*
 * input.h
 *
 *  Created on: 13 oct. 2021
 *      Author: ulise
 */

#ifndef INPUT_H_
#define INPUT_H_

int IngresarNumero(int* pResultado, char* mensaje, char* mensajeError,
int minimo, int maximo, int reintentos);

int getInt(int* pResultado);

int esNumerica(char* cadena);

int myGets(char* cadena, int longitud);

int IngresarFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo,
float maximo, int reintentos);

int getFloat(float* pResultado);

int esFlotante(char* cadena);

int IngresarCaracter(char* pResultado, char* mensaje, char* mensajeError,
int reintentos, char parametros[], int tam);

int CaracterValido(char caracter, char parametros[], int tam);

int IngresarCadena(char* pResultado, char* mensaje, char* mensajeError,
int reintentos, int tam);

int GetCadena(char* pResultado, int tam);

#endif /* INPUT_H_ */
