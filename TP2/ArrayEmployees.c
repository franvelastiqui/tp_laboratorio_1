#include "ArrayEmployees.h"

void inicializarEmpleados(eEmpleados listado[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        listado[i].estaVacio = 1;
        listado[i].id = -1;
    }
}

//__________________________________________________

void aniadirEmpleados(eEmpleados listado[],int tam)
{
    int i;

    i=buscarVacio(listado,tam);

    if(i!=-1)
    {
        listado[i].id=i+1;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(listado[i].nombre);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(listado[i].apellido);

        printf("Ingrese sueldo: ");
        scanf("%f", &listado[i].sueldo);

        printf("Ingrese sector: ");
        scanf("%d", &listado[i].sector);

        listado[i].estaVacio=0;
    }
    else
    {
        printf("No hay lugar disponible\n");
    }
}

//__________________________________________________

int buscarVacio(eEmpleados listado[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estaVacio == 1)
        {
            return i;
        }
    }

    return -1;
}

//__________________________________________________

void modificarEmpleados(eEmpleados listado[],int tam)
{

    int i;
    int flag=0;
    int opcion;
    int id;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estaVacio!=1)
        {
            id=pedirEntero("Ingrese el id del empleado a modificar: ");

            for(i=0; i<tam; i++)
            {
                if (id==listado[i].id && listado[i].estaVacio==0)
                {
                    printf("Se modificara al siguiente empleado:\n");
                    mostrarEmpleado(listado[i]);

                    opcion=pedirEntero("Escoja el campo a modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\nElija una opcion: ");
                    switch(opcion)
                    {
                    case 1:
                        printf("Ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(listado[i].nombre);
                        flag=1;
                        break;
                    case 2:
                        printf("Ingrese el nuevo apellido: ");
                        fflush(stdin);
                        gets(listado[i].apellido);
                        flag=1;
                        break;
                    case 3:
                        printf("Ingrese el nuevo salario: ");
                        scanf("%f", &listado[i].sueldo);
                        flag=1;
                        break;
                    case 4:
                        printf("Ingrese el nuevo sector: ");
                        scanf("%d", &listado[i].sector);
                        flag=1;
                        break;
                    case 5:
                        flag=1;
                        break;
                    }

                }

            }

            if(flag==0)
            {
                printf("No ingreso un legajo valido\n");
            }
        }
        else
        {
            printf("No hay empleados cargados en el sistema\n");
        }
        break;
    }




}

//__________________________________________________

void bajarEmpleados(eEmpleados listado[], int tam)
{
    int i;
    int id;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estaVacio!=1)
        {
            id=pedirEntero("Ingrese el legajo del empleado a dar de baja: ");

            for(i=0; i<tam; i++)
            {
                if (id==listado[i].id)
                {
                    printf("Se ha dado de baja al siguiente empleado:\n");
                    mostrarEmpleado(listado[i]);
                    listado[i].estaVacio = 1;
                    flag=1;
                }
            }

            if(flag==0)
            {
                printf("No ingreso un legajo valido\n");
            }
        }
        else
        {
            printf("No hay empleados cargados en el sistema\n");
        }
        break;
    }


}

//__________________________________________________

void ordenarEmpleados(eEmpleados listado[], int tam, eEmpleados auxiliar)
{
    int i;
    int j;

    for(i=0; i<tam-1; i++)
    {
        if(listado[i].estaVacio==0)
        {
            for(j=i+1; j<tam; j++)
            {
                if(listado[j].estaVacio==0)
                {
                    if(listado[i].sector>listado[j].sector)
                    {
                        auxiliar=listado[i];
                        listado[i]=listado[j];
                        listado[j]=auxiliar;
                    }
                    else if(listado[i].sector==listado[j].sector)
                    {
                        if(stricmp(listado[i].apellido, listado[j].apellido)>0)
                        {
                            auxiliar=listado[i];
                            listado[i]=listado[j];
                            listado[j]=auxiliar;
                        }
                        else if(stricmp(listado[i].apellido, listado[j].apellido)==0)
                        {
                            if(stricmp(listado[i].nombre, listado[i].nombre)>1)
                            {
                                auxiliar=listado[i];
                                listado[i]=listado[j];
                                listado[j]=auxiliar;
                            }
                        }
                    }
                }
            }
        }
    }
}

//__________________________________________________

void mostrarEmpleado(eEmpleados unEmpleado)
{
    printf("%d\t%s\t\t%s\t\t%.2f\t\t%d\n", unEmpleado.id,unEmpleado.nombre, unEmpleado.apellido, unEmpleado.sueldo,unEmpleado.sector);
}

//__________________________________________________

void mostrarListaEmpleados(eEmpleados listado[], int tam)
{
    int i;
    eEmpleados auxiliar;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estaVacio!=1)
        {
            ordenarEmpleados(listado,tam,auxiliar);
            for(i=0; i<tam; i++)
            {
                if(listado[i].estaVacio!=1)
                {
                    mostrarEmpleado(listado[i]);
                }

            }
        }
        else
        {
            printf("No hay empleados cargados en el sistema\n");
        }
        break;
    }

}

//__________________________________________________

void calcularSueldos(eEmpleados listado[],int tam)
{
    float acumulador=0;
    int i;
    float promedio;
    int contador=0;
    int contadorPersonasQueSuperanPromedio=0;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estaVacio!=1)
        {

            for(i=0; i<tam; i++)
            {
                if(listado[i].estaVacio==0)
                {
                    acumulador+=listado[i].sueldo;
                    contador++;
                }
            }

            promedio=acumulador/contador;

            contadorPersonasQueSuperanPromedio=contarEmpleadosQueSuperanPromedio(listado,tam,promedio);

            printf("Total de los salarios:%.2f\t\tPromedio de los salarios:%.2f\nLa cantidad de empleados que superan el salario promedio es %d\n",acumulador,promedio,contadorPersonasQueSuperanPromedio);


        }
        else
        {
            printf("No hay empleados cargados en el sistema\n");
        }
        break;
    }
}

//__________________________________________________

int contarEmpleadosQueSuperanPromedio(eEmpleados listado[], int tam, int promedio)
{
    int i;
    int contadorPersonas=0;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estaVacio==0)
        {
            if(listado[i].sueldo>promedio)
            {
                contadorPersonas++;
            }
        }
    }

    return contadorPersonas;
}

//__________________________________________________

int pedirEntero(char mensaje[])
{
    int numero;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &numero);

    return numero;
}
