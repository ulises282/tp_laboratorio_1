void menu (float a, float b)
{
    system("cls");
    printf("1. Ingresar 1er operando (A=%.2f)", a);
    printf("\n2. Ingresar 2do operando (B=%.2f) ", b);
    printf("\n3. Calcular todas las operaciones ");
    printf("\n    a) Calcular la suma (%.2f+%.2f) ", a, b);
    printf("\n    b) Calcular la resta (%.2f-%.2f) ",a , b);
    printf("\n    c) Calcular la division (%.2f/%.2f) ",a , b);
    printf("\n    d) Calcular la multiplicacion (%.2f*%.2f) ",a , b);
    printf("\n    e) Calcular el factorial (%.2f!) (%2.f!) ",a , b);
    printf("\n4. Informar resultados ");
    printf("\n    a) El resultado de %.2f+%.2f  ",a , b);
    printf("\n    b) El resultado de %.2f-%.2f  ",a , b);
    printf("\n    c) El resultado de %.2f/%.2f  ",a , b);
    printf("\n    d) El resultado de %.2f*%.2f  ",a , b);
    printf("\n    e) El factorial de %.2f y El factorial de %.2f ",a , b);
    printf("\n5. Salir\n");
}
int getOpcion(float a, float b)
{
    int opcion;
    printf("Ingresar opcion: ");
    scanf("%d", &opcion);
    while (opcion > 5 || opcion < 1)
    {
        menu(a, b);
        printf("ERROR!!! Ingrese una opcion valida: ");
        scanf("%d", &opcion);
    }
    return opcion;
}
float getFloat(char mensaje[])
{
    float valorFlotante;
    printf("%s", mensaje);
    scanf("%f", &valorFlotante);
    return valorFlotante;
}
float calcularSuma(float a, float b)
{
    float rSuma;
    rSuma = a+b;
    return rSuma;
}
float calcularResta(float a, float b)
{
    float rResta;
    rResta = a-b;
    return rResta;
}
float calcularDivision(float a, float b)
{
    float rDivision;
    rDivision = a/b;
    return rDivision;
}
float calcularMultiplicacion(float a, float b)
{
    float rMultiplicacion;
    rMultiplicacion = a*b;
    return rMultiplicacion;
}
int calcularFactorialA(float a)
{
    int i;
    if (a==0)
    {
        a=1;
        return a;
    }
    for (i=a-1;i>0;i=i-1)
    {
        a=a*i;
    }
    return a;
}
int calcularFactorialB(float b)
{

    int i;
    if (b==0)
    {
        b=1;
        return b;
    }
    for (i=b-1;i>0;i=i-1)
    {
        b=b*i;
    }
    return b;
}
bool calcularOperaciones(float a, float b, bool flag, bool flag1)
{
    bool flag2;
    if (flag == 1 && flag1 == 1)
    {
        calcularSuma(a, b);
        calcularResta (a, b);
        calcularDivision (a, b);
        calcularMultiplicacion (a, b);
        calcularFactorialA(a);
        calcularFactorialB(b);

        flag2 = 1;
    }
    else
    {
        menu(a, b);
        printf("\nIngrese los operando primero\n");
    }
    return flag2;

}
void mostrarOperaciones(float a, float b)
{
    printf("El resultado de %.2f+%.2f es: %.2f \n", a, b, calcularSuma(a, b));
    printf("El resultado de %.2f-%.2f es: %.2f \n", a, b, calcularResta (a, b));
    if (b==0)
    {
        printf("no se puede dividir por 0\n");
    }
    else
    {
        printf("El resultado de %.2f/%.2f es: %.2f \n", a, b, calcularDivision (a, b));
    }
    printf("El resultado de %.2f*%.2f es: %.2f \n", a, b, calcularMultiplicacion (a, b));
    if (a < 0)
    {
        printf("no existen factoriales de numeros negativos\n");
    }
    else
    {
        printf("El factorial de %.0f es: %d \n", a, calcularFactorialA (a));
    }
    if (b < 0)
    {
        printf("no existen factoriales de numeros negativos\n");
    }
    else
    {
        printf("El factorial de %.0f es: %d \n", b, calcularFactorialB (b));
    }


}

