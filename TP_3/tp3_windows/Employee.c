#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new()
{
	Employee* pEmployee = NULL;
	pEmployee = malloc(sizeof(Employee));

	return pEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* empleado;
	empleado = employee_new();

	if(empleado!=NULL)
	{
		employee_setId(empleado,atoi(idStr));//
		employee_setNombre(empleado,nombreStr);
		employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr));
		employee_setSueldo(empleado,atoi(sueldoStr));
	}
	return empleado;
}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && id>-1)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && (horasTrabajadas>0 && horasTrabajadas<1000))
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && (sueldo>0 && sueldo<1000000))
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_buscarPorId(LinkedList* pArrayListEmployee, int id)
{
	int retorno;
	retorno = -1;
	int len;
	int auxId;
	Employee* auxEmpleado;
	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee,i);
			employee_getId(auxEmpleado,&auxId);
			if(id == auxId)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
