#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "input.h"

int controller_loadIdFromBinary(char* path, int* ultimoId)
{
	int retorno;
	retorno = -1;
	FILE* archivo;
	int aux;
	archivo = fopen(path,"rb");
	if(archivo!=NULL)
	{
		fread(&aux,sizeof(int),1,archivo);
		*ultimoId = aux;
		retorno = 0;
	}
	fclose(archivo);
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
// void controller_menu()
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;
	int retorno;
	retorno = -1;
	archivo = fopen(path, "r");
	if(archivo!=NULL)
	{
		if(parser_EmployeeFromText(archivo, pArrayListEmployee)==1)
		{
			retorno = 1;
		}
	}
	fclose(archivo);
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;
	int retorno;
	retorno = -1;
	archivo = fopen(path, "rb");
	if(archivo!=NULL)
	{
		if(parser_EmployeeFromBinary(archivo, pArrayListEmployee)==1)
		{
			retorno = 1;
		}
	}
	fclose(archivo);
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* ultimoId)
{
	int retorno;
	retorno = -1;
	int auxIdInt;
	char auxId[10];
	char auxNombre[128];
	char auxHorasTrabajadas[10];
	char auxSueldo[10];
	int IntHorasTrabajadas;
	int IntSueldo;
	Employee* auxEmpleado;
	if(pArrayListEmployee!=NULL)
	{
		auxIdInt = *ultimoId + 1;
		*ultimoId = auxIdInt;
		IngresarCadena(auxNombre,"Ingresar nombre: ","Error, Reingrese nombre: ",128);
		Get_Int(&IntHorasTrabajadas,"Ingrese la cantidad de horas trabajadas: ","Error, Reingrese la cantidad de horas trabajdas (entre 1 y 10000): ",1,10000);
		Get_Int(&IntSueldo,"Ingrese sueldo: ","Error, Reingrese sueldo (entre 1 y 1000000): ",1,1000000);
		sprintf(auxHorasTrabajadas,"%d",IntHorasTrabajadas);
		sprintf(auxSueldo,"%d",IntSueldo);
		sprintf(auxId,"%d",auxIdInt);
		auxEmpleado = employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
		ll_add(pArrayListEmployee,auxEmpleado);
		retorno = 0;
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee,int* ultimoId)
{
	int retorno;
	retorno = -1;
	int auxId;
	int index;
	Employee* auxEmpleado;
	char auxNombre[128];
	int IntHorasTrabajadas;
	int IntSueldo;
	if(pArrayListEmployee!=NULL)
	{
		Get_Int(&auxId,"Ingrese el id del empleado a editar: ","Error, reingrese el id del empleado a editar: ",1,*ultimoId);
		index = employee_buscarPorId(pArrayListEmployee,auxId);

		if(index != -1)
		{
			IngresarCadena(auxNombre,"Ingresar nombre: ","Error, Reingrese nombre: ",128);
			Get_Int(&IntHorasTrabajadas,"Ingrese la cantidad de horas trabajadas: ","Error, Reingrese la cantidad de horas trabajdas (entre 1 y 10000): ",1,10000);
			Get_Int(&IntSueldo,"Ingrese sueldo: ","Error, Reingrese sueldo (entre 1 y 1000000): ",1,1000000);
			auxEmpleado = (Employee*)ll_get(pArrayListEmployee,index);
			employee_setNombre(auxEmpleado,auxNombre);
			employee_setHorasTrabajadas(auxEmpleado,IntHorasTrabajadas);
			employee_setSueldo(auxEmpleado,IntSueldo);
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee,int* ultimoId)
{
	int retorno;
	retorno = -1;
	int auxId;
	int index;
	if(pArrayListEmployee!=NULL)
	{
		Get_Int(&auxId,"Ingrese el id del empleado a eliminar: ","Error, reingrese el id del empleado a eliminar: ",1,*ultimoId);
		index = employee_buscarPorId(pArrayListEmployee,auxId);
		if(index!=-1)
		{
			employee_delete(pArrayListEmployee[index]);
			ll_remove(pArrayListEmployee,index);
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int retorno = -1;
	Employee* aux;
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	if(pArrayListEmployee!=NULL)
	{
		retorno = 1;
		printf("%-6s %-20s %-15s %8s\n","ID","Nombre","Hs trabajadas","Sueldo");
		for (i = 0; i <  ll_len(pArrayListEmployee); i++)
		{
			aux =(Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(aux,&auxId);//---------------------------------------------------------------------------------------------------------------------
			employee_getNombre(aux,auxNombre);
			employee_getHorasTrabajadas(aux,&auxHorasTrabajadas);
			employee_getSueldo(aux,&auxSueldo);
			printf("%-6d %-20s %-15d %8d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = -1;




    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = -1;
	FILE* archivo;
	Employee* aux;
	int i;
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	archivo = fopen(path,"w");
	if(archivo!=NULL)
	{
		fprintf(archivo,"id,nombre,horasTrabajadas,sueldo\n");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux =(Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(aux,&auxId);////---------------------------------------------------------------------------------------------------------------------
			employee_getNombre(aux,auxNombre);
			employee_getHorasTrabajadas(aux,&auxHorasTrabajadas);
			employee_getSueldo(aux,&auxSueldo);
			fprintf(archivo,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
		}
		fclose(archivo);
		retorno = 0;
	}
	fclose(archivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = -1;
	FILE* archivo;
	Employee* auxEmpleado;
	int i;
	archivo = fopen(path,"wb");
	if(archivo!=NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmpleado =(Employee*) ll_get(pArrayListEmployee, i);
			fwrite(auxEmpleado,sizeof(Employee),1,archivo);
		}
		fclose(archivo);
		retorno = 0;
	}
	fclose(archivo);
	return retorno;
}

int controller_saveIdAsBinary(char* path , int* ultimoId)
{
	int retorno;
	retorno = -1;
	FILE* archivo;
	int aux;
	archivo = fopen(path,"wb");
	if(archivo!=NULL)
	{
		aux = *ultimoId;
		fwrite(&aux,sizeof(int),1,archivo);
		retorno = 0;
	}
	fclose(archivo);
	return retorno;
}
