#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char id[128];
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
    int retorno = -1;
    int i = 0;
    Employee* aux;
    if(pFile!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
        printf("%4s  %16s  %15s  %10s", id, nombre, horasTrabajadas, sueldo);
        while(!feof(pFile))
        {
            i++;
            if(feof(pFile))
            {
                break;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
            if(aux!=NULL && atoi(id)==i)
            {
                printf("%4s  %16s  %15s  %10s", id, nombre, horasTrabajadas, sueldo);
            }
            aux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
            if(aux!=NULL && atoi(id)==i)
            {
                ll_add(pArrayListEmployee, aux);
                retorno = 0;
            }
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
