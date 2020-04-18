/** \brief muestra el menu al usuario con los datos que cargo previamente
 *
 * \param a float valor que el usuario ingreso
 * \param b float valor que el usuario ingreso
 * \return
 */
void menu (float a, float b);

/** \brief le pide al usuario una opcion para continuar
 *
 * \param a float valor que el usuario ingreso para mostrarlo en el menu dentro de la funcion getOpcion
 * \param b float valor que el usuario ingreso para mostrarlo en el menu dentro de la funcion getOpcion
 * \return int retorna la opcion elegida por el usuario
 *
 */
int getOpcion(float a, float b);
/** \brief le pide al usuario que ingrese el numero deseado
 *
 * \param mensaje[] char mensaje para ingresar el numero
 * \return float el numero que el usuario eligio
 *
 */
float getFloat(char mensaje[]);
/** \brief calcula la suma de los valores ingresados por el usuario
 *
 * \param a float primer valor ingresado
 * \param b float segundo valor ingresado
 * \return float retorna la suma de ambos numeros
 *
 */
float calcularSuma(float a, float b);
/** \brief calcula la resta de los valores ingresados por el usuario
 *
 * \param a float primer valor ingresado
 * \param b float segundo valor ingresado
 * \return float retorna la resta de ambos numeros
 *
 */
float calcularResta(float a, float b);
/** \brief calcula la division de los valores ingresados por el usuario
 *
 * \param a float primer valor ingresado
 * \param b float segundo valor ingresado
 * \return float retorna la division de ambos numeros
 *
 */
float calcularDivision(float a, float b);
/** \brief calcula la multiplicacion de los valores ingresados por el usuario
 *
 * \param a float primer valor ingresado
 * \param b float segundo valor ingresado
 * \return float retorna la multiplicacion de ambos numeros
 *
 */
float calcularMultiplicacion(float a, float b);
/** \brief calcula el factorial del primer valor ingresado por el usuario
 *
 * \param a float valor ingresado
 * \return int retorna el valor del factorial del numero ingresado
 *
 */
int calcularFactorialA(float a);
/** \brief calcula el factorial del segundo valor ingresado por el usuario
 *
 * \param b float valor ingresado
 * \return int retorna el valor del factorial del numero ingresado
 *
 */
int calcularFactorialB(float b);
/** \brief calcula las operaciones mensionadas en el menu
 *
 * \param a float primer valor ingresado
 * \param b float segundo valor ingresado
 * \param flag bool bandera para saber si el usuario ingreso el primer numero
 * \param flag1 bool bandera para saber si el usuario ingreso el segundo numero
 * \return bool retorna 1 si los numero estabasn cargados y realizo las operaciones, 0 si no habia algun valor cargado
 *
 */
bool calcularOperaciones(float a, float b, bool flag, bool flag1);
/** \brief muestra los resultados de las operacionas mencionadas en el menu
 *
 * \param a float primer valor ingresado
 * \param b float segundo valor ingresado
 * \return void
 *
 */
void mostrarOperaciones(float a, float b);
