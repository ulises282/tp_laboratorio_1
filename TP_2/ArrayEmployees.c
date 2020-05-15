/*********************************************************************************/
void menu(void)
{
    system("cls");
    printf("1. ALTAS");
    printf("\n2. MODIFICAR");
    printf("\n3. BAJA ");
    printf("\n4. INFORMAR");
    printf("\n5. SALIR\n");
}
/*********************************************************************************/
void menuSecundario(void)
{
    system("cls");
    printf("4. INFORMAR");
    printf("\n\t1 Lista de empleados");
    printf("\n\t2 Total y promedio de los salarios");
    printf("\n\t3 VOLVER\n");
}
/*********************************************************************************/
char getOpcion(int contadorAltas)
{
    bool valido=false;
    char opcion[51];
    char opcionValida;
    int longitud;
    printf("Ingresar una opcion: ");
    scanf("%s", opcion);
    longitud = strlen(opcion);
    valido = validarNumero(opcion);
    while((valido==false || longitud != 1) || (opcion[0] > 53 || opcion[0] < 49) || (contadorAltas==0 && opcion[0]>49 && opcion[0]<53))
    {
        if (contadorAltas==0 && (opcion[0]>49 && opcion[0]<53))
        {
            printf("\nERROR!!! Primero cargue a un empleado: \n");
            printf("Ingresar una opcion valida: ");
            scanf("%s", opcion);
            longitud = strlen(opcion);
            valido = validarNumero(opcion);
        }
        else
        {
            printf("Ingresar una opcion valida: ");
            scanf("%s", opcion);
            longitud = strlen(opcion);
            valido = validarNumero(opcion);
        }
    }
    opcionValida=opcion[0];
    return opcionValida;
}
/*********************************************************************************/
char getOpcionS()
{
    bool valido=false;
    char opcion[51];
    char opcionS;
    int longitud;
    printf("Ingresar una opcion: ");
    scanf("%s", opcion);
    longitud = strlen(opcion);
    valido = validarNumero(opcion);
    while((valido==false || longitud != 1) || (opcion[0] >  51 || opcion[0] < 49))
    {
        printf("Ingresar una opcion valida: ");
        scanf("%s", opcion);
        longitud = strlen(opcion);
        valido = validarNumero(opcion);
    }
    opcionS=opcion[0];

    return opcionS;
}
/*********************************************************************************/
void initEmployees(Employee listado[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        listado[i].isEmpty = LIBRE;
        listado[i].id = 0;
    }
}
/*********************************************************************************/
int addEmployee(Employee listado[], int tam)
{
    int index;
    index=findEmployeeById(listado, tam);
    if(index!=-1)
    {
        listado[index] = crearEmpleado();
        listado[index].id = index+100;
        printf("Carga exitosa\n");
        return 1;
    }
    printf("No hay espacio para mas empleados");
    return 0;

}
/*********************************************************************************/
int findEmployeeById(Employee listado[], int tam)
{
    int i;
    int index = -1;

    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==LIBRE)
        {
            index =  i;
            return index;
        }
    }
    return -1;
}
/*********************************************************************************/
int removeEmployee(Employee listado[], int tam)
{
    int idE;
    printf("Ingrese el id del empleado a eliminar: ");
    scanf("%d", &idE);
    int i;
    for(i=0; i<tam; i++)
    {
        if(idE!=0)
        {
            if(idE == listado[i].id)
            {
                listado[i].isEmpty=LIBRE;
                printf("Empleado eliminado\n");
                return -1;
                break;
            }
        }
    }
    printf("Empleado no encontrado\n");
    return 0;
}
/*********************************************************************************/
Employee crearEmpleado (void)
{
    Employee miEmpleado;

    printf ("Ingrese nombre: ");
    fflush (stdin);
    fgets(miEmpleado.name,50,stdin);
    miEmpleado.name[strlen(miEmpleado.name)-1]='\0';
    while(miEmpleado.name== NULL)
    {
        printf ("Ingrese nombre: ");
        fflush (stdin);
        fgets(miEmpleado.name,50,stdin);
        miEmpleado.name[strlen(miEmpleado.name)-1]='\0';
    }

    printf ("Ingrese apellido: ");
    fflush (stdin);
    fgets(miEmpleado.lastName,50,stdin);
    miEmpleado.lastName[strlen(miEmpleado.lastName)-1]='\0';

    printf ("Ingrese salario: ");
    scanf ("%f", &miEmpleado.salary);

    printf ("Ingrese  sector: ");
    scanf ("%d", &miEmpleado.sector);

    miEmpleado.isEmpty = OCUPADO;

    return miEmpleado;
}
/*********************************************************************************/
void sortEmployees(Employee listado[], int tam)
{
    int i;
    int j;
    Employee auxEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].lastName,listado[j].lastName)>0)
            {
                auxEmpleado = listado[i];
                listado[i] = listado[j];
                listado[j] = auxEmpleado;
            }
            else
            {
               if(listado[i].lastName==listado[j].lastName)
               {

                    if(listado[i].sector>listado[j].sector)
                    {
                        auxEmpleado = listado[i];
                        listado[i] = listado[j];
                        listado[j] = auxEmpleado;
                    }


               }
            }
        }

    }
}
/*********************************************************************************/
void printEmployees(Employee listado[], int tam)
{
    int i;
    printf("-----------------------------EMPLEADOS------------------------------------------\n");
    printf(" ID         Apellido          Nombre      Salario     Sector \n");
    printf("--------------------------------------------------------------------------------\n");
    for(i=0; i<tam; i++)
    {
       if(listado[i].isEmpty==OCUPADO)
       {
           mostrarUnEmpleado(listado[i]);
       }

    }
    printf("--------------------------------------------------------------------------------\n");

}
/*********************************************************************************/
void mostrarUnEmpleado (Employee miEmpleado)
{
  printf ("%4d %15s %15s \t %8.2f %8d\n",     miEmpleado.id,
                                            miEmpleado.lastName,
                                            miEmpleado.name,
                                            miEmpleado.salary,
                                            miEmpleado.sector);
}
/*********************************************************************************/
void modificarEmpleado(Employee listado[], int tam)
{
    int acumulador =0;
    int id;
    int i;
    char opcion;
    printf("Ingrese el id del empleado a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == listado[i].id)
        {
            opcion = menuModificacion();
            switch(opcion)
            {
                case 49:
                    printf ("Reingrese el nombre: \n");
                    fflush (stdin);
                    fgets(listado[i].name,51,stdin);
                    listado[i].name[strlen(listado[i].name)-1]='\0';
                    printf ("Carga exitosa \n");
                    acumulador++;
                    break;
                case 50:
                    printf ("Reingrese el apellido: \n");
                    fflush (stdin);
                    fgets(listado[i].lastName,51,stdin);
                    listado[i].lastName[strlen(listado[i].lastName)-1]='\0';
                    printf ("Carga exitosa \n");
                    acumulador++;
                    break;
                case 51:
                    printf ("Reingrese el salario: \n");
                    scanf ("%f", &listado[i].salary);
                    printf ("Carga exitosa \n");
                    acumulador++;
                    break;
                case 52:
                    printf ("Reingrese el sector: \n");
                    scanf ("%d", &listado[i].sector);
                    printf ("Carga exitosa \n");
                    acumulador++;
                    break;
                case 53:
                    printf("Volviendo...\n");
                    acumulador++;
                    break;
            }
        }
    }
    if (acumulador==0)
    {
        printf("empleado no encotrado\n");
    }
}
/*********************************************************************************/
char menuModificacion (void)
{
    printf("que desea modificar?\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Apellido\n");
    printf("3. Modificar Salario\n");
    printf("4. Modificar Sector\n");
    printf("5. Volver\n");

    bool valido=false;
    char opcion[51];
    char opcionModificar;
    int longitud;
    printf("Ingresar una opcion: ");
    scanf("%s", opcion);
    longitud = strlen(opcion);
    valido = validarNumero(opcion);
    while((valido==false || longitud != 1) || (opcion[0] >  53 || opcion[0] < 49))
    {
        printf("Ingresar una opcion valida: ");
        scanf("%s", opcion);
        longitud = strlen(opcion);
        valido = validarNumero(opcion);
    }
    opcionModificar=opcion[0];
    return opcionModificar;
}
/*********************************************************************************/
bool validarNumero(char opcion[])
{
    if(!(opcion[0]>=49 && opcion[0]<=53))
    {
        return false;
    }
    return true;
}
/*********************************************************************************/
void TotalPromedioSalarios(Employee listado[], int tam)
{
    int i;
    int contadorMayorPromedio = 0;
    float salarioTotal;
    float salarioPromedio;
    int contador = 0;
    for (i=0;i<tam;i++)
    {
        if (listado[i].isEmpty==OCUPADO)
        {
            salarioTotal=salarioTotal+listado[i].salary;
            contador++;
        }
    }
    salarioPromedio=salarioTotal/contador;

    for (i=0;i<tam;i++)
    {
        if (listado[i].isEmpty==OCUPADO)
        {
            if(listado[i].salary > salarioPromedio)
            {
                contadorMayorPromedio++;
            }
        }
    }

    printf("El saldo total es: %.2f\n", salarioTotal);
    printf("El saldo promedio es: %.2f\n", salarioPromedio);
    printf("El numero de empleados que superan el saldo promedio es de: %d\n", contadorMayorPromedio);
}
/*********************************************************************************/
