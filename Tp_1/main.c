#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funciones.h"
#include "funciones.c"
int main()
{
    int opcion;
    float a;
    float b;
    float rSuma;
    float rResta;
    float rDivision;
    float rMultiplicacion;
    bool flag=0;
    bool flag1=0;
    bool flag2=0;
    do
    {
        menu(a, b);
        opcion = getOpcion(a, b);
        switch(opcion)
        {
        case 1:
            a = getFloat("\nIngrese el operando 1: ");
            menu(a, b);
            flag = 1;
            flag2 = 0;
            break;

        case 2:
            b = getFloat("\nIngrese el operando 2: ");
            menu(a, b);
            flag1 = 1;
            flag2 = 0;
            break;

        case 3:
             flag2 = calcularOperaciones(a, b, flag, flag1);
            break;

        case 4:
            if (flag2 == 1)
            {
                mostrarOperaciones(a, b);
            }
            else
            {
                printf("Primero calcule los resultados\n");
            }

            break;

        case 5:
            break;
        }
        system("pause");
        system("cls");
    }while(opcion!=5);

    return 0;
}
