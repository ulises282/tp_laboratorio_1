#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
////////////////////////////////////////////////////////////////////////////////
int getString(char* cadena, int longitud)
{
    int retorno = -1 ;
    char aux[longitud];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        if(fgets(aux,sizeof(aux),stdin) != NULL)
        {
            if(aux[strnlen(aux,sizeof(aux))-1] == '\n')
            {
                aux[strnlen(aux,sizeof(aux))-1] == '\0';
            }
            if(strnlen(aux,sizeof(aux)) <= longitud)
            {
                strncpy(cadena,aux,longitud);
                retorno = 0;
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int esNumero(char* num)
{
    int i;
    for(i = 1; i < strlen(num); i++)
    {
        if(!isdigit(num[i-1]))
        {
            return -1;
        }
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
int getInt (int* resultado)
{
    int retorno = -1;
    char aux[128];
    if(getString(aux,sizeof(aux)) == 0)
    {
        if (esNumero(aux)==0)
        {
            retorno = 0;
            *resultado = atoi(aux);
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int get_int(int* Numero, char* mensaje, char* mensaje_error, int min, int max, int reintentos)
{
    int auxInt;
    int retorno = -1;

    if(Numero!=NULL && mensaje!=NULL && mensaje_error!=NULL && min <= max && reintentos >= 0)
    {
        do{
            printf("%s", mensaje);
            if((getInt(&auxInt)) == 0 && auxInt >= min && auxInt <=max)
            {
                *Numero = auxInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensaje_error);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int get_float(float* Numero, char* mensaje, char* mensaje_error, float min, float max, int reintentos)
{
    float auxFloat;
    int retorno = -1;

    if(Numero!=NULL && mensaje!=NULL && mensaje_error!=NULL && min <= max && reintentos >= 0)
    {
        do{
            printf("%s", mensaje);
            scanf("%f", &auxFloat);
            if(auxFloat >= min && auxFloat <=max)
            {
                *Numero = auxFloat;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensaje_error);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int getChar(char* resultado, char* mensaje, char* mensaje_error, char min, char max, int reintentos)
{
    int retorno = -1 ;
    char aux;
    if(resultado!=NULL && mensaje!=NULL && mensaje_error!=NULL && min<=max && reintentos>=0)
    {
        do{
            printf("%s", mensaje);
            scanf("%c", &aux);
            if(aux>=min && aux<=max)
            {
                *resultado = aux;
                retorno = 0;
                break;
            }
            printf("%s", mensaje_error);
            reintentos--;
        }while(reintentos>=0);
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////
int validarNombre (char* cadena, int len)
{
    int i;
    int retorno = 1;
    if(cadena!=NULL && len>0)
    {
        for(i=0;cadena[i]!='\0' && i<len;i++)
        {
            if((cadena[i]<'A' || cadena[i]<'Z') && (cadena[i]<'a' || cadena[i]<'z'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////
int getNombre (char* cadena)
{
    int retorno = -1;
    char aux[128];

    if(cadena != NULL)
    {
        if(get_string(aux,"Ingrese nombre: \n","Error nombre invalido\n")==0)
        {
            strcpy(cadena, aux);
            retorno = 0;
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////
int getHorasTrabajadas (char* cadena)
{
    int retorno = -1;
    int aux;

    if(cadena != NULL)
    {
        if(get_int(&aux,"Ingrese horas trabajadas: \n","Error numero invalido\n",1,9999,10)==0)
        {
            sprintf(cadena,"%u",aux);
            retorno = 0;
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////
int getSueldo (char* cadena)
{
    int retorno = -1;
    int aux;

    if(cadena != NULL)
    {
        if(get_int(&aux,"Ingrese sueldo: \n","Error numero invalido\n",1,999999,10)==0)
        {
            sprintf(cadena,"%u",aux);
            retorno = 0;
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////

