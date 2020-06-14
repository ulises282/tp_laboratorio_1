#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* pEmployee = NULL;
    pEmployee = malloc(sizeof(Employee));
    if(pEmployee==NULL)
    {
        printf("Error! no hay espacio en memoria");
        return 0;
    }
    return pEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* empleado;
    empleado = employee_new();

    empleado->id = atoi(idStr);
    empleado->horasTrabajadas = atoi(horasTrabajadasStr);
    empleado->sueldo = atoi(sueldoStr);
    strcpy(empleado->nombre, nombreStr);

    return empleado;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!= NULL && nombre!=NULL && validarNombre(nombre,TN))
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!= NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this!= NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this!= NULL && sueldo!=NULL)
    {
        sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this!= NULL)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this!= NULL && id!=NULL)
    {
        id=this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this!= NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int retorno = -1;
    if(this!= NULL && horasTrabajdas!=NULL)
    {
        horasTrabajdas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    //verificar nulidad

    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{

}



