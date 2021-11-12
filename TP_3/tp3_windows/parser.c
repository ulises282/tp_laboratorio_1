#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];
	int retorno;
	retorno = -1;
	Employee* aux;
	if(pFile!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo) == 4)
			{
				aux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				if(aux != NULL)
				{
					ll_add(pArrayListEmployee, aux);//
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = -1;
	Employee* aux;
	Employee* aux2;
	if(pFile!=NULL)
	{
		while(!feof(pFile))
		{
			fread(&aux,sizeof(Employee),1,pFile);
			if(aux!=NULL)
			{
				aux2 = employee_new();
				aux2 = &aux;
				if(aux2 != NULL)
				{
					ll_add(pArrayListEmployee, aux2);
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}
