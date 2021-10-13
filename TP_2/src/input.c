/*
 * input.c
 *
 *  Created on: 13 oct. 2021
 *      Author: ulise
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"
/******************************************************************************/
int IngresarNumero(int* pResultado, char* mensaje, char* mensajeError,
    int minimo, int maximo, int reintentos)
{
    int retorno;
    int numero;

    while(reintentos>0)
    {
        printf("%s",mensaje);
        if (getInt(&numero) == 0)
        {
            if(numero<=maximo && numero >= minimo)
            {
                *pResultado = numero;
                retorno = 0;
                break;
            }
        }
        reintentos --;
        printf("%s",mensajeError);
    }
    if(reintentos == 0)
    {
        retorno = -1;
    }
    return retorno;
}
/******************************************************************************/
int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[64];
    if(pResultado!=NULL)
    {
        if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
        retorno = 0;
        }
    }
    return retorno;
}
/******************************************************************************/
int esNumerica(char* cadena)
{
    int i = 0;
    int retorno = 1;
    if (cadena != NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i]> '9')
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
/******************************************************************************/
int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;
}
/******************************************************************************/
int IngresarFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo,
    float maximo, int reintentos)
{
    int retorno;
    float numero;
    while(reintentos>0)
    {
        printf("%s",mensaje);
        if (getFloat(&numero) == 0)
        {
            if(numero<=maximo && numero >= minimo)
            {
                *pResultado = numero;
                retorno = 0;
                break;
            }
        }
        reintentos --;
        printf("%s",mensajeError);
    }
    if(reintentos == 0)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
        *pResultado = numero;
    }
    return retorno;
}
/******************************************************************************/
int getFloat(float* pResultado)
{
    int retorno = -1;
    char buffer[64];
    if(pResultado!=NULL)
    {
        if(myGets(buffer, sizeof(buffer)) == 0 && esFlotante(buffer))
        {

            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
    return retorno;
}
/******************************************************************************/
int esFlotante(char* cadena)
{
    int i = 0;
    int retorno = 1;
    if (cadena != NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] != '.' && (cadena[i] < '0' || cadena[i]> '9'))
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
/******************************************************************************/
int IngresarCaracter(char* pResultado, char* mensaje, char* mensajeError,
int reintentos, char parametros[], int tam)
{
    int retorno;
    char caracter = '.';
    while(reintentos>0)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c", &caracter);
        if (caracter != '.')
        {
            if(CaracterValido(caracter,parametros,tam)==0)
            {
                *pResultado = caracter;
                retorno = 0;
                break;
            }
        }
        reintentos --;
        printf("%s",mensajeError);
    }
    if(reintentos == 0)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
        *pResultado = caracter;
    }
    return retorno;
}
/******************************************************************************/
int CaracterValido(char caracter, char parametros[], int tam)
{
    int i;
    int retorno = 1;
    for(i=0;i<tam;i++)
    {
        if(caracter==parametros[i])
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
/******************************************************************************/
int IngresarCadena(char* pResultado, char* mensaje, char* mensajeError,
int reintentos, int tam)
{
    int retorno;
    char cadena[tam];
    while(reintentos>0)
    {
        printf("%s",mensaje);
        if (GetCadena(cadena,tam)==0)
        {
            strcpy(pResultado,cadena);
            retorno = 0;
            break;
        }
        reintentos --;
        printf("%s",mensajeError);
    }
    if(reintentos == 0)
    {
        retorno = -1;
    }
    return retorno;
}
/******************************************************************************/
int GetCadena(char pResultado[], int tam)
{
    int retorno = -1;
    int longitudCadena;
    char cadena[tam];
    fflush(stdin);
    fgets(cadena, tam, stdin);
    longitudCadena = strlen(cadena);
    if(cadena != NULL)
    {
        cadena[longitudCadena-1] = '\0';
        strcpy(pResultado,cadena);
        retorno = 0;
    }

    return retorno;
}
