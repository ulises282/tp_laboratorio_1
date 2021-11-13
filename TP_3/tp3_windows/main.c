#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
	setbuf(stdout,NULL);
	LinkedList* listaEmpleados = ll_newLinkedList();
    int option;
    int ultimoId;
    int estadoMenu;
    estadoMenu = 0;
    option = 10;
	do{
		controller_menu();
		Get_Int(&option,"Ingrese una opcion: ","Error, Reingrese opcion (entre 1 y 10): ",1,10);
		switch(option)
		{
			case 1:
				if(estadoMenu==0)
				{
					if(controller_loadFromText("data.csv",listaEmpleados) == 1 && controller_loadIdFromBinary("idText.dat",&ultimoId)==0)
					{
						printf("Carga de datos exitosa...\n");
						estadoMenu = 1;
					}
					else
					{
						printf("Error al cargar los datos de empleados...\n");
					}
				}
				else
				{
					printf("Guarde los datos antes de cargar denuevo\n");
				}
				break;

			case 2:
				if(estadoMenu == 0)
				{
					if(controller_loadFromBinary("data.dat",listaEmpleados) == 1 && controller_loadIdFromBinary("id.dat",&ultimoId)==0)
					{
						printf("Carga de datos exitosa...\n");
						estadoMenu = 1;
					}
					else
					{
						printf("Error al cargar los datos de empleados...\n");
					}
				}
				else
				{
					printf("Guarde los datos antes de cargar denuevo\n");
				}

				break;

			case 3:
				if(estadoMenu == 1)
				{
					if(controller_addEmployee(listaEmpleados,&ultimoId) == 0)
					{
						printf("Empleado cargado con exito\n");
					}
					else
					{
						printf("Error al cargar empleado\n");
					}
				}
				else
				{
					printf("Cargue los datos antes de modificar la lista\n");
				}

				break;

			case 4:
				if(estadoMenu == 1)
				{
					if(controller_editEmployee(listaEmpleados,&ultimoId)==0)
					{
						printf("Empleado editado con exito\n");
					}
					else
					{
						printf("Error al editar empleado");
					}
				}
				else
				{
					printf("Cargue los datos antes de modificar la lista\n");
				}

				break;

			case 5:
				if(estadoMenu == 1)
				{
					if(controller_removeEmployee(listaEmpleados,&ultimoId) == 0)
					{
						printf("Empleado eliminado con exito\n");
					}
					else
					{
						printf("Error al eliminar empleado\n");
					}
				}
				else
				{
					printf("Cargue los datos antes de modificar la lista\n");
				}

				break;

			case 6:
				if(estadoMenu == 1)
				{
					if(controller_ListEmployee(listaEmpleados) != 1)
					{
						printf("Error al mostrar los emplados\n");
					}
				}
				else
				{
					printf("Cargue los daotos antes de listar\n");
				}

				break;

			case 7:
				if(estadoMenu == 1)
				{
					if(controller_sortEmployee(listaEmpleados) == 0)
					{
						printf("Empleados ordenados con exito\n");
					}
					else
					{
						printf("Error al ordenar empleados\n");
					}
				}
				else
				{
					printf("Cargue los daotos antes de ordenar\n");
				}
				break;

			case 8:
				if(estadoMenu == 1)
				{
					if(controller_saveAsText("data.csv",listaEmpleados)==0)
					{
						printf("Guardado de datos exitoso\n");
						estadoMenu = 0;
					}
					else
					{
						printf("Error al guardar datos\n");
					}
				}
				else
				{
					printf("Primero Cargue los datos antes de guardar\n");
				}

				break;

			case 9:
				if(estadoMenu == 1)
				{
					if(controller_saveAsBinary("data.dat",listaEmpleados)==0)
					{
						printf("Guardado de datos exitoso\n");
						estadoMenu = 0;
					}
					else
					{
						printf("Error al guardar datos\n");
					}
				}
				else
				{
					printf("Primero Cargue los datos antes de guardar\n");
				}

				break;

			case 10:
				break;
		}
	}while(option != 10);
    return 0;
}

