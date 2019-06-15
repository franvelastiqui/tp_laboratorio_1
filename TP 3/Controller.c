#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int verificacion=-1;

    FILE* miArchivo;

    miArchivo=fopen(path, "r");

    if(miArchivo!=NULL);
    {
        verificacion=parser_EmployeeFromText(miArchivo, pArrayListEmployee);
    }

    fclose(miArchivo);

    return verificacion;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int verificacion=-1;

    FILE* miArchivo;

    miArchivo=fopen(path, "rb");

    if(miArchivo!=NULL);
    {
        verificacion=parser_EmployeeFromBinary(miArchivo, pArrayListEmployee);
    }

    fclose(miArchivo);

    return verificacion;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* idMaximo)
{
    Employee* empleado;

    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];

    int verificacion=-1;

    if(pArrayListEmployee!=NULL)
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese las horas trabajadas: ");
        fflush(stdin);
        gets(horasTrabajadas);

        printf("Ingrese el sueldo: ");
        fflush(stdin);
        gets(sueldo);

        itoa(*idMaximo, id, 10);

        empleado= employee_newParametros(id,nombre,horasTrabajadas,sueldo);

        ll_add(pArrayListEmployee, empleado);

        verificacion=0;
    }

    return verificacion;
}


/** \brief Modificar datos de empleado
*
* \param path char*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;

    int i;
    int id;
    int index=-1;
    int opcion;
    char nombre[50];
    int horas;
    int sueldo;
    int verificacion=-1;

    if(pArrayListEmployee!=NULL)
    {
        printf("Ingrese el id del empleado a modificar: ");
        scanf("%d", &id);

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado= (Employee*)ll_get(pArrayListEmployee, i);

            if(empleado->id==id)
            {
                index=i;
                break;
            }
        }

        if(index!=-1)
        {
            do
            {
                printf("1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\nElija una opcion: ");
                scanf("%d",&opcion);
                while(opcion<1 || opcion>4)
                {
                    printf("Opcion invalida. Elija un opcion valida: ");
                    scanf("%d",&opcion);
                }
                switch(opcion)
                {
                case 1:
                    printf("Ingrese el nuevo nombre: ");
                    fflush(stdin);
                    gets(nombre);
                    employee_setNombre(empleado,nombre);
                    break;
                case 2:
                    printf("Ingrese las nuevas horas: ");
                    scanf("%d",&horas);
                    employee_setHorasTrabajadas(empleado,horas);
                    break;
                case 3:
                    printf("Ingrese el nuevo sueldo: ");
                    scanf("%d",&sueldo);
                    employee_setSueldo(empleado,sueldo);
                    break;
                }

            }while(opcion!=4);
            verificacion=0;
        }
    }

    return verificacion;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;

    int i;
    int id;
    int index=-1;
    char confirmacion;
    int verificacion=-1;

    if(pArrayListEmployee!=NULL)
    {
        printf("Ingrese el id del empleado a remover: ");
        scanf("%d", &id);

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado= (Employee*)ll_get(pArrayListEmployee, i);

            if(empleado->id==id)
            {
                index=i;
                break;
            }
        }

        if(index!=1)
        {
            printf("Presione s para confirmar la operacion: ");
            fflush(stdin);
            scanf("%c",&confirmacion);

            if(confirmacion=='s' || confirmacion=='S')
            {
                ll_remove(pArrayListEmployee, index);
                printf("Operacion realizada con exito\n");
            }
            else
            {
                printf("Ha cancelado la operacion\n");
            }
        }
        verificacion=0;
    }
    return verificacion;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int verificacion=-1;
    int i;

    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            if(i%200==0)
            {
                system("pause");
            }

            empleado=(Employee*)ll_get(pArrayListEmployee, i);
            employee_printEmpleado(empleado);
        }
        verificacion=0;
    }

    return verificacion;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int verificacion= -1;
    int opcion;
    int (*pFunc)(Employee*,Employee*);

    pFunc = employee_compareByName;
    if(pArrayListEmployee != NULL)
    {
        do
        {
            printf("1.Id\n2.Nombre\n3.Sueldo\n4.Horas trabajadas\n5.Salir\nElija un metodo de ordenamiento: ");
            scanf("%d",&opcion);
            while(opcion<1 || opcion>5)
            {
                printf("Opcion invalida. Elija un opcion valida: ");
                scanf("%d",&opcion);
            }

            switch(opcion)
            {
            case 1:
                ll_sort(pArrayListEmployee, employee_compareById, 1);
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_compareByName, 1);
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_compareBySueldo, 1);
                break;
            case 4:
                ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, 1);
            }
        }while(opcion!=5);

        verificacion=0;
    }
    return verificacion;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int i;
    int estado=-1;

    FILE* pFile;

    pFile = fopen (path, "w");

    if (pFile != NULL)
    {
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

        for (i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado=ll_get(pArrayListEmployee, i);

            fprintf(pFile,"%d,%s,%d,%d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);

            estado=0;
        }
    }

    fclose(pFile);

    return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int i;
    int estado=-1;

    FILE* pFile;

    pFile=fopen(path,"wb");

    if(pFile!= NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado= ll_get(pArrayListEmployee, i);

            fwrite(empleado, sizeof(Employee),1,pFile);
        }

        fclose(pFile);

        estado=0;
    }
    return estado;
}

