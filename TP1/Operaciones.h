/** \brief Pide al usuario que introduzca un numero
 *
 * \param void
 * \return float El numero ingresado por el usuario
 *
 */
float pedirNumero(void);


/** \brief Suma los numeros ingresados por el usuario
 *
 * \param float El primer numero ingresado por el usuario
 * \param float El segundo numero ingresado por el usuario
 * \return float El resultado de la suma de los dos numeros
 *
 */
float sumarNumeros(float, float);


/** \brief Resta los numeros ingresados por el usuario
 *
 * \param float El primer numero ingresado por el usuario
 * \param float El segundo numero ingresado por el usuario
 * \return float El resultado de la resta de los numeros
 *
 */
float restarNumeros(float, float);


/** \brief Multiplica los numeros ingresados por el usuario
 *
 * \param float El primer numero ingresado por el usuario
 * \param float El segundo numero ingresado por el usuario
 * \return float El resultado de la multiplicacion de los numeros
 *
 */
float multiplicarNumeros(float, float);


/** \brief Divide los numeros ingresados por el usuario
 *
 * \param float El primer numero ingresado por el usuario
 * \param float El segundo numero ingresado por el usuario
 * \return float El resultado de la division de los numeros
 *
 */

float dividirNumeros(float, float);


/** \brief Factorear el numero ingresado por el usuario
 *
 * \param float El numero ingresado por el usuario
 * \return float El resultado del factoreo del numero
 *
 */
float factorial(float);


/** \brief Muestra los resultados de las operaciones matematicas realizadas
 *
 * \param float El resultado de la suma
 * \param float El resultado de la resta
 * \param float El resultado de la multiplicacion
 * \param float El resultado de la division
 * \param int Flag, por si el divisor es o
 * \param float El resultado del factoreo del primer numero
 * \param int Flag, por si el numero es negativo
 * \param float El resultado del factoreo del segundo numero
 * \param int Flag, por si el numero es negativo
 * \return void
 *
 */
void mostrarResultados(float, float, float, float, int, float, int, float, int);
