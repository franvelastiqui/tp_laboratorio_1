#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    int verificacion;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int idMaximo=1001;

    do
    {
        printf("1.Cargar los datos desde el archivo data.csv (modo texto)\n2.Cargar los datos desde el archivo data.csv (modo binario)\n3.Alta de empleado\n4.Modificar datos de empleado\n5.Baja de empleado\n6.Listar empleados\n7.Ordenar empleados\n8.Guardar los datos en el archivo data.csv (modo texto)\n9.Guardar los datos en el archivo data.csv (modo binario)\n10.Salir\nElija una opcion: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            verificacion=controller_loadFromText("data.csv",listaEmpleados);
            if(verificacion==0)
            {
                printf("Proceso realizado con exito\n");
            }
            else
            {
                printf("Hubo un error\n");
            }
            break;
        case 2:
            verificacion=controller_loadFromBinary("data.csv",listaEmpleados);
            if(verificacion==0)
            {
                printf("Proceso realizado con exito\n");
            }
            else
            {
                printf("Hubo un error\n");
            }
            break;
        case 3:
            verificacion=controller_addEmployee(listaEmpleados, &idMaximo);
            if(verificacion==0)
            {
                printf("Proceso realizado con exito\n");
                idMaximo++;
            }
            else
            {
                printf("Hubo un error\n");
            }
            break;
        case 4:
            verificacion=controller_editEmployee(listaEmpleados);
            if(verificacion==0)
            {
                printf("Proceso realizado con exito\n");
            }
            else
            {
                printf("Hubo un error\n");
            }
            break;
        case 5:
            verificacion=controller_removeEmployee(listaEmpleados);
            if(verificacion==0)
            {
                printf("Proceso realizado con exito\n");
            }
            else
            {
                printf("Hubo un error\n");
            }
            break;
        case 6:
            verificacion=controller_ListEmployee(listaEmpleados);
            if(verificacion==0)
            {
                printf("Proceso realizado con exito\n");
            }
            else
            {
                printf("Hubo un error\n");
            }
            break;
        case 7:
            verificacion=controller_sortEmployee(listaEmpleados);
            if(verificacion==0)
            {
                printf("Proceso realizado con exito\n");
            }
            else
            {
                printf("Hubo un error\n");
            }
            break;
        case 8:
            verificacion=controller_saveAsText("data.csv", listaEmpleados);
            if(verificacion==0)
            {
                printf("Proceso realizado con exito\n");
            }
            else
            {
                printf("Hubo un error\n");
            }
            break;
        case 9:
            verificacion=controller_saveAsBinary("data.csv", listaEmpleados);
            if(verificacion==0)
            {
                printf("Proceso realizado con exito\n");
            }
            else
            {
                printf("Hubo un error\n");
            }
            break;
        }

        system("pause");
        system("cls");

    }while(option!=10);

    return 0;
}
