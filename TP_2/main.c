#include "ArrayEmployees.h"
#include "ArrayEmployees.c"
#define T 1000
int main()
{
    Employee listado[T];
    int contadorAltas = 0;
    char opcion;
    char opcionS;

    initEmployees(listado,T);
    do
    {
        menu();
        opcion = getOpcion(contadorAltas);
        switch(opcion)
        {
        case 49:
            contadorAltas=contadorAltas+addEmployee(listado,T);
            break;
        case 50:
            printEmployees(listado, T);
            modificarEmpleado(listado,T);
            break;

        case 51:
            printEmployees(listado, T);
            contadorAltas =contadorAltas + removeEmployee(listado,T);
            break;

        case 52:
            menuSecundario();
            opcionS = getOpcionS();
            switch (opcionS)
            {
                case 49:
                    sortEmployees(listado, T);
                    printEmployees(listado, T);
                    break;
                case 50:
                    TotalPromedioSalarios(listado, T);
                    break;

                case 51:
                    break;

            }
            break;

        case 53:
            break;
        }
        system("pause");
        system("cls");
    }while(opcion!=53);

    return 0;
}
