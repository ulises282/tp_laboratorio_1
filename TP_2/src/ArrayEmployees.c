/*
 * ArrayEmployees.c
 *
 *  Created on: 13 oct. 2021
 *      Author: ulise
 */
#include "ArrayEmployees.h"


/******************************************************************************/
int initEmployees(Employee* list, int len)
{
    int retorno;
    retorno = 0;
    if(list == NULL)
    {
        retorno = -1;
    }
    else
    {
        for(int i = 0;i<len;i++)
        {
            list[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}
/******************************************************************************/
int GenerarId(int ultimoId)
{
    int retorno = ultimoId + 1;

    return retorno;
}
/******************************************************************************/
int BuscarLibreaArray(Employee* list, int len)
{
    int i;
    int index;
    index = -1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/******************************************************************************/
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int index;
    int retorno = -1;
    index = BuscarLibreaArray(list, len);
    if(index != -1)
    {
        list[index].id = id;
        strcpy(list[index].name,name);
        strcpy(list[index].lastName,lastName);
        list[index].salary = salary;
        list[index].sector = sector;
        list[index].isEmpty = OCUPADO;
        retorno = 0;
    }
    return retorno;
}
/******************************************************************************/
int AgregarEmployee(Employee* list, int len,int ultimoId)
{
    int retorno;
    retorno = -1;
    int auxId;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    if(list!=NULL)
    {
        if(IngresarCadena(auxName,"Ingrese nombre: ","ERROR!!!",5,51) == 0)
        {
            if(IngresarCadena(auxLastName,"Ingrese apellido: ","ERROR!!!",5,51) == 0)
            {
                if(IngresarFlotante(&auxSalary,"Ingresar salario: ","ERROR!!!",0,1000000,5) == 0)
                {
                    if(IngresarNumero(&auxSector,"Ingresar sector: ","ERROR!!!",0,100,5) == 0)
                    {
                        auxId = GenerarId(ultimoId);
                        addEmployee(list,len,auxId,auxName,auxLastName,auxSalary,auxSector);
                        retorno = 0;
                        printf("Carga de empleado exitosa\n");
                    }
                    else
                    {
                        printf("Error al ingresar sector\n");
                    }
                }
                else
                {
                    printf("Error al iongresar salario\n");
                }
            }
            else
            {
                printf("Error al ingresar apellido\n");
            }
        }
        else
        {
            printf("Error al ingresar nombre\n");
        }
    }
    return retorno;
}
/******************************************************************************/
int findEmployeeById(Employee* list, int len,int id)
{
    int retorno;
    retorno = -1;
    int i;
    if(list != NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/******************************************************************************/
int removeEmployee(Employee* list, int len, int id)
{
    int retorno;
    retorno = -1;
    int index;
    index = findEmployeeById(list,len,id);
    if(index != -1)
    {
        list[index].isEmpty = LIBRE;
        retorno = 0;
        printf("Empleado eliminado con exito\n");
    }
    return retorno;
}
/******************************************************************************/
int modificarEmployee(Employee* list, int len, int id)
{
    int retorno;
    int opcion;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    retorno = -1;
    int index;
    index = findEmployeeById(list,len,id);
    if(index != -1)
    {
        printf("Que desea modicar: \n1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n");
        if(IngresarNumero(&opcion,"Ingresar opcion: ","ERROR!!!",1,4,5) == 0)
        {
            switch(opcion)
            {
                case 1:
                    if(IngresarCadena(auxName,"Reingresar nombre: ","ERROR!!!",5,51) == 0)
                    {
                        strcpy(list[index].name,auxName);
                        printf("Modificacion exitosa\n");
                        retorno = 0;
                    }
                    else
                    {
                        printf("Error al modificar nombre\n");
                    }
                break;
                case 2:
                    if(IngresarCadena(auxLastName,"Reingresar apellido: ","ERROR!!!",5,51) == 0)
                    {
                        strcpy(list[index].lastName,auxLastName);
                        printf("Modificacion exitosa\n");
                        retorno = 0;
                    }
                    else
                    {
                        printf("Error al modificar apellido\n");
                    }
                break;
                case 3:
                    if(IngresarFlotante(&auxSalary,"Reingresar salario: ","ERROR!!!",0,1000000,5) == 0)
                    {
                        list[index].salary = auxSalary;
                        printf("Modificacion exitosa\n");
                        retorno = 0;
                    }
                    else
                    {
                        printf("Error al modificar salario\n");
                    }
                break;
                case 4:
                    if(IngresarNumero(&auxSector,"Reingresar sector: ","ERROR!!!",0,100,5) == 0)
                    {
                        list[index].sector = auxSector;
                        printf("Modificacion exitosa\n");
                        retorno = 0;
                    }
                    else
                    {
                        printf("Error al modificar sector\n");
                    }
                break;
            }
        }

    }
    return retorno;
}
/******************************************************************************/
int sortEmployees(Employee* list, int len, int order)
{
    int retorno;
    retorno = -1;
    Employee auxEmployee;
    if(order == 1)
    {
        for(int i = 0; i < len-1; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
                {
                    if(strcmp(list[i].lastName,list[j].lastName)>0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                        retorno = 0;
                    }
                    else
                    {
                        if(strcmp(list[i].lastName,list[j].lastName)==0)
                        {
                            sortEmployeesSector(list,len);
                        }
                    }

                }
            }
        }
    }
    else
    {
        for(int i = 0; i < len-1; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
                {
                    if(strcmp(list[i].lastName,list[j].lastName)<0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                        retorno = 0;
                    }
                    else
                    {
                        if(strcmp(list[i].lastName,list[j].lastName)==0)
                        {
                            sortEmployeesSector(list,len);
                        }
                    }
                }
            }
        }
    }

    return retorno;
}
/******************************************************************************/
int sortEmployeesSector(Employee* list, int len)
{
    int retorno;
    retorno = -1;
    Employee auxEmployee;
    for(int i = 0; i < len-1; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
            {
                if(list[i].sector<list[j].sector)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}
/******************************************************************************/
int printEmployees(Employee* list, int len)
{
    int i;
    printf("%-4s %-20s %-20s %-15s %-6s\n","ID","NOMBRE","APELLIDO", "SALARIO","SECTOR");
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
           printf("%-4d %-20s %-20s %-15.2f %-6d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    return 0;
}
/******************************************************************************/
//Total y promedio de los salarios, y cuántos empleados superan el salario promedio
int promedioSalarios(Employee* list, int len,int contador)
{
    int retorno;
    retorno = -1;
    int i;
    float promedioSalarios;
    promedioSalarios = 0;
    int sumaSalarios;
    sumaSalarios = 0;
    int SalariosMayorAlPromedio;
    SalariosMayorAlPromedio = 0;
    if(list!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {
                sumaSalarios = sumaSalarios+list[i].salary;
            }
        }
        promedioSalarios = (float)sumaSalarios/contador;

        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==OCUPADO && list[i].salary>promedioSalarios)
            {
                SalariosMayorAlPromedio++;
            }
        }
        retorno = 0;
        printf("\n\nTotal de salarios: %d\n",contador);
        printf("Promedio de salarios:%.2f \n",promedioSalarios);
        printf("La cantidad de empleados que superan el salario promedio es de: %d\n\n",SalariosMayorAlPromedio);
    }
    return retorno;
}

