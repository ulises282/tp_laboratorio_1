#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIBRE 0
#define OCUPADO 1
#define BAJA 2
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

/*************************************************************/

/** \brief Valida un numero entre 1 y 5
 *
 * \param opcion[] char la opcion que se ingresa para ser validada
 * \return bool  la funcion retorna false si el numero no coincide con una opcion y true si coincide
 *
 */
bool validarNumero(char opcion[]);


 /** \brief muestra el menu de opciones
 *
 * \param void
 * \return void
 *
 */
void menu (void);


/** \brief muestra el submenu en la opcion 4
 *
 * \param void
 * \return void
 *
 */
void menuSecundario(void);


/** \brief Valida un numero entre 1 y 5 y no deja entrar a las opciones 2, 3 y 4 si no hay datos ingresados
 *
 * \param flag int bandera para saber si ya hay datos cargados
 * \return char retorna el numero ya validado
 *
 */
char getOpcion(int flag);


/** \brief Valida un numero entre 1 y 3
 *
 * \param void
 * \return char retorna el numero ya validado
 *
 */
char getOpcionS(void);


/** \brief inicializa el array dejando el estado en libre y el id en 0
 *
 * \param listado[] Employee el array que se va a inicializar
 * \param tam int el tamaño del array que se va a inicializar
 * \return void
 *
 */
void initEmployees(Employee listado[], int tam);


/** \brief Carga los datos de un empleado si hay espacio
 *
 * \param listado[] Employee lista de los datos que se van a cargar
 * \param tam int el tamaño del array
 * \return int retorna 1 si pudo cargar los datos y 0 si no
 *
 */
int addEmployee(Employee listado[], int tam);


/** \brief encuentra un espacio vacio/libre
 *
 * \param listado[] Employee lista de los empleados
 * \param tam int tamaño maximo de empleados
 * \return int retorna indice del lugar libre
 *
 */
int findEmployeeById(Employee listado[], int tam);


/** \brief Ordena el array de empleados por apellido y sector
 *
 * \param listado[] Employee lista de empleados que van a ser ordenados
 * \param tam int cantidad maxima de empleados
 * \return void
 *
 */
void sortEmployees(Employee listado[], int tam);



/** \brief Imprime el array de empleados de forma encolumnada
 *
 * \param listado[] Employee lista de empleados que van a ser listados
 * \param tam int cantidad maxima de empleados
 * \return void
 *
 */
void printEmployees(Employee listado[], int tam);


/** \brief Imprime la informacion de un solo empleado
 *
 * \param Employee miEmpleado  empleado que va a ser impreso
 *
 * \return
 *
 */
void mostrarUnEmpleado (Employee miEmpleado);


/** \brief crea un empleado dentro del array
 *
 * \param
 * \param
 * \return el empleado ya creado
 *
 */
Employee crearEmpleado (void);


/** \brief  elimina los datos de un empleado ingresando su ID
 *
 * \param listado[] Employee lista de empleados
 * \param tam int tamaño maximo de empleados
 * \return int retorna -1 si elimino al empleado y 0 si no
 *
 */
int removeEmployee(Employee listado[], int tam);


/** \brief Modifica los datos de un empleado ingreasndo su ID
 *
 * \param listado[] Employee lista de empleados
 * \param tam int tamaño maximo de empleados
 * \return void
 *
 */
void modificarEmpleado(Employee listado[], int tam);


/** \brief submenu dentro de modificar empleado que muestra opciones para cambiar diferentes datos del empleado
 *
 * \param Employee listado[]
 * \param
 * \return retorna la opcion elegida validada
 *
 */
char menuModificacion (void);


/** \brief informa Total y promedio de los salarios, y cuántos empleados superan el salario promedio
 *
 * \param listado[] Employee lista de empleados con su salario
 * \param tam int tamaño maximo del array
 * \return void
 *
 */
void TotalPromedioSalarios(Employee listado[], int tam);


