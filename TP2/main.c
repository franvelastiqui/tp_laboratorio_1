#include <stdlib.h>
#include "ArrayEmployees.h"

#define T 1000

int main()
{
    int opcion;

    eEmpleados listado[T];

    inicializarEmpleados(listado,T);

    do
    {
        opcion=pedirEntero("1.Alta\n2.Modificar\n3.Baja\n4.Informar lista de empleados\n5.Informar total y promedio de los salarios\n6.Salir\nElija una opcion: ");
        switch(opcion)
        {
        case 1:
            aniadirEmpleados(listado,T);
            break;
        case 2:
            modificarEmpleados(listado,T);
            break;
        case 3:
            bajarEmpleados(listado,T);
            break;
        case 4:
            mostrarListaEmpleados(listado,T);
            break;
        case 5:
            calcularSueldos(listado,T);
            break;
        }

        system("pause");
        system("cls");
    }
    while(opcion!=6);

    return 0;
}
