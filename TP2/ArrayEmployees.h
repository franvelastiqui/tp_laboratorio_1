#include <stdio.h>
#include "string.h"

typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float sueldo;
 int sector;
 int estaVacio;
} eEmpleados;

typedef struct
{
    int idSector;
    int nombreSector;
} eSector;

//__________________________________________________

/** \brief Inicializa el campo estaVacio en 1 en todas las posiciones del array
 *
 * \param eEmpleados[] El array a ser inicializado
 * \param int Indica la longitud del array
 * \return void
 *
 */
void inicializarEmpleados(eEmpleados[],int);

//__________________________________________________

/** \brief Añade valores en una existente lista de empleados en la primera posicion vacia
 *
 * \param eEmpleados[] El array en el cual se van a añadir los valores
 * \param int Indica la longitud del array
 * \return void
 *
 */
void aniadirEmpleados(eEmpleados[],int);

//__________________________________________________

/** \brief Busca la primera posicion vacia en una lista de empleados
 *
 * \param eEmpleados[] El array en el cual se va a buscar la posicion vacia
 * \param int Indica la longitud del array
 * \return int Se devuelve la posicion si se encuentra un lugar vacio, o -1 si no se encuentra ninguna
 *
 */
int buscarVacio(eEmpleados[],int);

//__________________________________________________

/** \brief Modifica los valores seleccionados en una existente lista de empleados
 *
 * \param eEmpleados[] El array en el cual se van a modificar los valores
 * \param int Indica la longitud del array
 * \return void
 *
 */
void modificarEmpleados(eEmpleados[],int);

//__________________________________________________

/** \brief Da de baja a un empleado en una existente lista de empleados
 *
 * \param eEmpleados[] El array en el cual se dara de baja al empleado
 * \param int Indica la longitud del array
 * \return void
 *
 */
void bajarEmpleados(eEmpleados[],int);

//__________________________________________________

/** \brief Ordena a los empleados de una lista de empleados por apellido y sector
 *
 * \param eEmpleados[] El array a ser ordenado
 * \param int Indica la longitud del array
 * \param eEmpleados Auxiliar donde guardar los valores de la estructura al aplicar el metodo de burbujeo
 * \return void
 *
 */
void ordenarEmpleados(eEmpleados[],int,eEmpleados);

//__________________________________________________

/** \brief Imprime los valores de un empleado
 *
 * \param eEmpleados El array con los valores a ser mostrados
 * \return void
 *
 */
void mostrarEmpleado(eEmpleados);

//__________________________________________________

/** \brief Muestra la lista de los empleados que fueron dados de alta
 *
 * \param eEmpleados[] El array con el que trabajar
 * \param int Indica la longitud del array
 * \return void
 *
 */
void mostrarListaEmpleados(eEmpleados[],int);

//__________________________________________________

/** \brief Informa el total de los salarios y su promedio, asi como la cantidad de empleados que superan el salario promedio
 *
 * \param eEmpleados[] El array con los valores a trabajar
 * \param int Indica la longitud del array
 * \return void
 *
 */
void calcularSueldos(eEmpleados[],int);

//__________________________________________________

/** \brief Cuenta la cantidad de empleados que superan el salario promedio
 *
 * \param eEmpleados[] El array donde buscar las personas
 * \param int Indica la longitud del array
 * \param int El promedio de los salarios
 * \return int La cantidad de personas que superan el salario promedio
 *
 */
int contarEmpleadosQueSuperanPromedio(eEmpleados[],int,int);

//__________________________________________________

/** \brief Pide al usuario que ingrese un numero
 *
 * \param char[] El mensaje a ser mostrado
 * \return int El entero ingresado por el usuario
 *
 */
int pedirEntero(char[]);
