#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////
void controller_menu(void)
{
    printf("\n=================================================================================\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    printf("=================================================================================\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo;
    int retorno;
    archivo = fopen(path, "r");
    if(archivo!=NULL)
    {
        parser_EmployeeFromText(archivo, pArrayListEmployee);
        retorno = 0;
    }
    else
    {
        printf("Error con el archivo");
    }
    fclose(archivo);
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = - 1;
    int indice;
    int id;
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
    char idAux[128];
    Employee* aux;
    Employee* empleado;
    if(pArrayListEmployee!=NULL)
    {
        getNombre(nombre);
        getHorasTrabajadas(horasTrabajadas);
        getSueldo(sueldo);
        id = get_new_id(pArrayListEmployee);
        sprintf(idAux, "%u", id);
        empleado = employee_newParametros(idAux ,nombre,horasTrabajadas,sueldo);
        ll_add(pArrayListEmployee,empleado);
        retorno = 0;
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int aux;
    Employee* pAux;
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
    int indice;


    if(pArrayListEmployee!=NULL)
    {
        do{
            get_int(&id,"Ingrese el id: ","Ingrese numeros validos",0,10000,10);
            indice = employee_buscarPorId(pArrayListEmployee,ll_len(pArrayListEmployee),id);
        }while(indice==-1);

        getNombre(nombre);
        getHorasTrabajadas(horasTrabajadas);
        getSueldo(sueldo);
        pAux = (Employee*)ll_get(pArrayListEmployee,indice);
        employee_setNombre(pAux, nombre);
        employee_setHorasTrabajadas(pAux,atoi(horasTrabajadas));
        employee_setSueldo(pAux, atoi(sueldo));

    }
    return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int id;
    int nose = 999;
    int index;
    int indice;
    if(pArrayListEmployee!=NULL)
    {
        do{
            get_int(&id,"Ingrese el id: ","Ingrese numeros validos",0,10000,10);
            indice = employee_buscarPorId(pArrayListEmployee,ll_len(pArrayListEmployee),id);
            printf("el indice es: %d\n", indice);
        }while(indice==-1);
        if(indice!=-1)
        {
            printf("\n index : %d \n", indice);
            ll_remove(pArrayListEmployee, indice);
            retorno = 0;
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int retorno = -1;
    Employee* aux;
    if(pArrayListEmployee!=NULL)
    {
        printf("Lista de empleados");
        for (i = 0; i <  ll_len(pArrayListEmployee); i++)
        {
            aux =(Employee*) ll_get(pArrayListEmployee, i);
            printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
        }

    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo;
    int retorno;
    Employee* aux;
    int i;
    archivo = fopen(path, "w");
    if(archivo!=NULL)
    {
        fprintf(archivo,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux =(Employee*) ll_get(pArrayListEmployee, i);
            fprintf(archivo,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
        }
        fclose(archivo);
        retorno = 0;
    }
    else
    {
        printf("Error con el archivo");
    }
    fclose(archivo);
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int get_string(char* cadena, char* mensaje, char* mensaje_error)
{
    char auxString[128];
    int retorno = -1;

    if(cadena!=NULL && mensaje!=NULL && mensaje_error!=NULL)
    {
        do{
            printf("%s", mensaje);
            gets(auxString);
            if((validarNombre(auxString, sizeof(auxString))) == 1)
            {
                strcpy(cadena,auxString);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensaje_error);
            }

        }while(retorno!=0);
    }
    return retorno;
}

int employee_buscarPorId(LinkedList* pArrayListEmployee,int len, int id)
{
    int retorno = -1;
    int i;
    Employee* aux;
    if(pArrayListEmployee!=NULL && id>=0 && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            aux = /*(Employee*)*/ll_get(pArrayListEmployee,i);
            if(aux->id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int get_new_id(LinkedList* pArrayListEmployee)
{
    Employee* p;
    int i;
    int new_id;
    int ultimo_id;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        p = ll_get(pArrayListEmployee,i);
        ultimo_id = p->id;
    }
    new_id = ultimo_id + 1;
    return new_id;
}
