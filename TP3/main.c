#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* miLista = ll_newLinkedList();
    int opcion;
    int valido;

    do{
        controller_menu();
        valido = get_int(&opcion,"Ingresar opcion: ", "Error! opcion invalida\n", 1, 10, 3);
        if(valido == 0)
        {
            switch(opcion)
            {
            case 1:
                controller_loadFromText("data.csv", miLista);
                break;

            case 2:
                //controller_loadFromBinary("data.bin", miLista);
                break;

            case 3:
                controller_addEmployee(miLista);
                break;

            case 4:
                controller_editEmployee(miLista);
                break;

            case 5:
                controller_removeEmployee(miLista);
                break;

            case 6:
                controller_ListEmployee(miLista);
                break;

            case 7:
                //controller_sortEmployee();
                break;

            case 8:
                controller_saveAsText("data.csv",miLista);
                break;

            case 9:
                //controller_saveAsBinary();
                break;

            case 10:
                break;
            }
        }

    }while(opcion!= 10 );
    return 0;
}
