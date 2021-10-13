/*
 * ArrayEmployees.h
 *
 *  Created on: 13 oct. 2021
 *      Author: ulise
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"
#define LIBRE 0
#define OCUPADO 1
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;
int initEmployees(Employee* list, int len);
int GenerarId(int ultimoId);
int BuscarLibreaArray(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int AgregarEmployee(Employee* list, int len,int ultimoId);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int modificarEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);

int printEmployees(Employee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */
