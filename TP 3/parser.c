#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int verificacion=-1;

    char id[500], nombre[500], horasTrabajadas[500], sueldo[500];

    if(pFile!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

            empleado=employee_newParametros(id, nombre, horasTrabajadas, sueldo);

            ll_add(pArrayListEmployee, empleado);
        }
        verificacion=0;
    }

    return verificacion;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int verificacion = -1;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!(feof(pFile)))
        {
            empleado=employee_new();

            fread(empleado, sizeof(Employee), 1, pFile);
            if (feof(pFile))
            {
                verificacion = 0;
                break;
            }

            ll_add(pArrayListEmployee, empleado);
        }
    }

    return verificacion;
}
