/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "ArrayEmployees.h"
#define LEN 1000

int main()
{
    Employee listaEmpleados[LEN];
    int opcion;
    int opcionSecundaria;
    int auxId;
    int orden;
    int contador;
    contador = 0;
    int ultimoId;
    ultimoId = 0;
    setbuf(stdout, NULL);

    if(initEmployees(listaEmpleados,LEN) == 0)
    {
        do{
            printf("1)Alta de empleados\n2)Modificar empleados\n3)Baja de empleados\n4)Informar\n5)salir\n");
            if(IngresarNumero(&opcion,"Ingresar opcion: ","ERROR! ",1,5,5) == 0)
            {
                switch(opcion)
                {
                    case 1:
                        AgregarEmployee(listaEmpleados,LEN,ultimoId);
                        contador++;
                        ultimoId++;
                    break;

                    case 2:
                        if(contador != 0)
                        {
                            printEmployees(listaEmpleados,LEN);
                            if(IngresarNumero(&auxId,"Ingrese el id del empleado a modificar: ","ERROR!!!",0,ultimoId,5)==0)
                            {
                                modificarEmployee(listaEmpleados,LEN,auxId);
                            }
                            else
                            {
                                printf("Error al ingresar id empleado\n");
                            }
                        }
                        else
                        {
                            printf("Primero Ingrese un empleado\n");
                        }
                        printf("Presione 'Enter' para continuar: ... ");
                        while ( getchar() != '\n');
                    break;

                    case 3:
                        if(contador != 0)
                        {
                            printEmployees(listaEmpleados,LEN);
                            if(IngresarNumero(&auxId,"Ingrese el id del empleado a eliminar: ","ERROR!!!",0,ultimoId,5)==0)
                            {
                                removeEmployee(listaEmpleados,LEN,auxId);
                            }
                            else
                            {
                                printf("Error al eliminar empleado\n");
                            }
                        }
                        else
                        {
                            printf("Primero Ingrese un empleado\n");
                        }
                        printf("Presione 'Enter' para continuar: ... ");
                        while ( getchar() != '\n');
                    break;

                    case 4:
                        if(contador != 0)
                        {
                            printf("1)Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n");
                            printf("2)Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n");
                            if(IngresarNumero(&opcionSecundaria,"Ingrese una opcion: ","ERROR!!!",1,2,5)==0)
                            {
                                switch(opcionSecundaria)
                                {
                                    case 1:
                                        printf("Desea ordenar de forma: \n1)ascendente\n2)descendente\n");
                                        if(IngresarNumero(&orden,"Ingresar orden: ","ERROR!!!",1,2,5) == 0)
                                        {
                                            sortEmployees(listaEmpleados,LEN,orden);
                                        }
                                        else
                                        {
                                            printf("Error al ingresar orden\n");
                                        }
                                    break;

                                    case 2:
                                    break;
                                }
                                printEmployees(listaEmpleados,LEN);
                            }
                            else
                            {
                                printf("Error al ingresar opcion\n");
                            }
                        }
                        else
                        {
                            printf("Primero Ingrese un empleado\n");
                        }
                        printf("Presione 'Enter' para continuar: ... ");
                        while ( getchar() != '\n');
                    break;

                    case 5:
                    break;
                }
            }
            else
            {
                opcion=5;
            }
        }while(opcion!=5);
    }
    return 0;
}
