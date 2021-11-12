#include "input.h"
/******************************************************************************/
int Get_Int(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno;
    retorno = -1;
    int numero;
    printf("%s",mensaje);
    do{
        if(IngresarNumero(&numero) == 0 && numero<=maximo && numero >= minimo)
        {
            *pResultado = numero;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s",mensajeError);
        }
    }while(retorno!=0);
    return retorno;
}
/******************************************************************************/
int IngresarNumero(int* pResultado)
{
    int retorno;
    retorno = -1;
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
    int i;
    i = 0;
    int retorno = -1;
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
    int retorno;
    retorno = -1;
    if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin); // LINUX-> __fpurge o WIN-> fflush
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
            retorno = 0;
        }
    }
    return retorno;
}
/******************************************************************************/
int IngresarCadena(char* pResultado, char* mensaje, char* mensajeError, int tam)
{
    int retorno;
    retorno = -1;
    char cadena[tam];
    printf("%s",mensaje);
    while(retorno!=0)
    {
        if (GetCadena(cadena,tam)==0)
        {
            TransformarCadena(cadena,strlen(cadena));
            strcpy(pResultado,cadena);
            retorno = 0;
            break;
        }
        printf("%s",mensajeError);
    }
    return retorno;
}
/******************************************************************************/
int GetCadena(char pResultado[], int tam)
{
    int retorno;
    retorno = -1;
    char cadena[tam];

    fflush(stdin);
    fgets(cadena, tam, stdin);
    if(esAlfabetico(cadena,strlen(cadena)) == 0)
    {
    	cadena[strlen(cadena)-1] = '\0';
        strcpy(pResultado,cadena);
        retorno = 0;
    }
    return retorno;
}
/******************************************************************************/
int esAlfabetico (char cadena[],int tam)
{
    int retorno;
    retorno = 0;
    for(int i=0;i<tam-1;i++)
    {
        if(isalpha(cadena[i]) == 0)
        {
            retorno = -1;
            break;
        }
    }
    return retorno;
}
/******************************************************************************/
int TransformarCadena(char cadena[],int len)
{
    int retorno;
    retorno = -1;
    int i;
    if(cadena != NULL)
    {
        cadena[0] = toupper(cadena[0]);
        for(i=1;i<len-1;i++)
        {
            cadena[i] = tolower(cadena[i]);
        }
        retorno = 0;
    }
    return retorno;
}
