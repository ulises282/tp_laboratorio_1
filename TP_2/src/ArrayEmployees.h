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

/** \brief inicializa el array pasado como parametro cambiando el campo isEmpty a LIBRE
 *
 * \param Employee* list  Puntero al array a modificar
 * \param int len  Tamaño del array
 * \return int  Retorna -1 en caso de que el puntero pasado como parametro sea nulo o
 * retorna 0 si se inicializo el array sin problemas.
 *
 */
int initEmployees(Employee* list, int len);

/** \brief  Recibe el ultimo id utilizado y retorna el proximo id a utilizar
 *
 * \param int ultimoId  El ultimo id utilizado
 * \return int   Retorna el proximo id a utilizar
 *
 */
int GenerarId(int ultimoId);

/** \brief  Busca en el array una posicion con el valor isEmpty en LIBRE
 *
 * \param Employee* list  El puntero al array en donde se buscara la posicion LIBRE
 * \param int len  El tamaño del array
 * \return int  Retorna -1 si no encotro lugar libre en el array. Si encontro lugar
 * en el array devuelve la posicion que ocupa en el array dicho lugar libre
 *
 */
int BuscarLibreaArray(Employee* list, int len);

/** \brief Recibe como parametreo los valores para un nuevo empleado y los carga en un lugar libre en el array
 *
 * \param Employee* list  El puntero al array en donde se cargaran los valores
 * \param int len  El tamaño del array donde se cargaran los valores
 * \param int id  El numero de id asiganado para el nuevo empleado
 * \param char name[]  El nombre del nuevo empleado
 * \param char lastName[] El apellido del nuevo empleado
 * \param float salary  El salario del nuevo empleado
 * \param int sector  El sector del nuevo empleado
 * \return int  Retorna -1 si no hay lugar en el array para cargar al empleado, o retorna 0 si
 * pudo caragar al nuevo empleado
 *
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief Pide al usuario que cargue los datos que tendra el nuevo empleado asignandole un id
 *
 * \param Employee* list  El puntero al array donde posteriormente se cargara el empleado
 * \param int len  El tamaño del array donde posteriormente se cargaran los valores
 * \param int ultimoId  El ultimo id ingresado
 * \return int  Retorna -1 si no se pudo cargar los datos o 0 si se cargaros los datos
 *
 */
int AgregarEmployee(Employee* list, int len,int ultimoId);

/** \brief  Busca el indice en el array donde se encuentra el empleado con el id ingresado como parametro
 *
 * \param Employee* list  El puntero al array en donde se buscara el empleado
 * \param int len  El tamaño del array en donde se buscara el empleado
 * \param int id  El id que tiene el empleado a buscar
 * \return int  Retorna -1 si la lista es nulo o no encontro al empleado, y si
 * encontro al empleado
 * retorna el indice del array donde se encuentra
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief  Elimina el empleado (con el id pasado como parametro) de forma logica
 * cambiando el valor de isEmpty a LIBRE
 *
 * \param Employee* list  El puntero al array a modificar
 * \param int len  El tamaño del array a modificar
 * \param int id  El id del empleado a eliminar
 * \return int  retorna -1 si el puntero es nulo o no encontro al empleado,
 * y retorna 0 si pudo eliminar al empleado
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief  Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
 * o Salario o Sector
 *
 * \param Employee* list  Puntero al array a modificar
 * \param int len  Tamaño del array a modificar
 * \param int id  Id del empleado a modifacar
 * \return int  Retorna -1 si el puntero es nulo o si no se pudo moficar el empleado,
 * retorna 0 si el empleado se modifico con exito
 *
 */
int modificarEmployee(Employee* list, int len, int id);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente
 *
 * \param Employee* list  Puntero al array que se ordenara
 * \param int len  Tamaño del array que se ordenara
 * \param int order  Se ingresa 1 si se desea ordenar de forma ascendente o 2 si se desea
 * ordenar de forma descendente
 * \return int  Retorna -1 si el puntero es nulo o si hubo problemas al ordenar el array,
 * retorna 0 si ordeno el array exitosamente
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief Ordena el array de empleados por sector
 *
 * \param  Employee* list  Puntero al array que se ordenara
 * \param  int len  Tamaño del array que se ordenara
 * \return int  Retorna -1 si el puntero es nulo o si hubo problemas al ordenar el array,
 * retorna 0 si ordeno el array exitosamente
 *
 */
int sortEmployeesSector(Employee* list, int len);

/** \brief Imprime el array de empleados de forma encolumnada
 *
 * \param Employee* list  Puntero al array con los datos a imprimir
 * \param int len  Tamaño del array con los datos a imprimir
 * \return int  retorna -1 si el puntero es nulo , o retorna 0 si imprimio los datos exitosamente
 *
 */
int printEmployees(Employee* list, int len);

/** \brief  Calcula e imprime el total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 *
 * \param Employee* list  Puntero al array con los datos a calcular
 * \param int len  Tamaño del array con los datos a calcular
 * \param int contador  Cantidad de empleados cargados
 * \return int  Retorna -1 si el puntero es nulo o hubo problemas al calcular,
 * retorna 0 si calculo e imprimio exitosamente
 *
 */
int promedioSalarios(Employee* list, int len,int contador);


#endif /* ARRAYEMPLOYEES_H_ */
