#include "Employee.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

Employee* employee_new()
{
    Employee* empleado;

    empleado = (Employee*)malloc(sizeof(Employee));

    return empleado;
}

//_______________________________________________________________

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* empleado=employee_new();

    employee_setId(empleado, atoi(idStr));
    employee_setNombre(empleado, nombreStr);
    employee_setHorasTrabajadas(empleado, atoi (horasTrabajadasStr));
    employee_setSueldo(empleado, atoi(sueldoStr));

    return empleado;
}

//_______________________________________________________________

void employee_delete(Employee* this)
{
    free(this);
}

//_______________________________________________________________

int employee_setId(Employee* this, int id)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        this->id=id;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int employee_getId(Employee* this,int* id)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        *id=this->id;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int employee_setNombre(Employee* this, char nombre[])
{
    int verificacion=-1;
    if(this!=NULL)
    {
        strcpy(this->nombre, nombre);
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int employee_getNombre(Employee* this,char* nombre)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int employee_setSueldo(Employee* this, int sueldo)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int employee_getSueldo(Employee* this,int* sueldo)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

void employee_printEmpleado(Employee* this)
{
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;

    employee_getId(this, &id);
    employee_getHorasTrabajadas(this, &horasTrabajadas);
    employee_getSueldo(this, &sueldo);
    employee_getNombre(this, nombre);

    printf("%d\t\t%s\t\t%d\t\t%d\n", id, nombre, horasTrabajadas, sueldo);
}

//_______________________________________________________________

int employee_compareById(void* empleadoUno, void* empleadoDos)
{
    int estado;

    Employee* emp1=(Employee*)empleadoUno;
    Employee* emp2=(Employee*)empleadoDos;

    if(emp1->id > emp2->id )
    {
        estado=1;
    }
    else if(emp1->id < emp2->id)
    {
        estado=-1;
    }
    else
    {
        estado= 0;
    }
    return estado;
}

//_______________________________________________________________

int employee_compareByName(void* empleadoUno, void* empleadoDos)
{
    int estado;

    Employee* emp1=(Employee*)empleadoUno;
    Employee* emp2=(Employee*)empleadoDos;

    estado=stricmp(emp1->nombre,emp2->nombre);

    return estado;
}

//_______________________________________________________________

int employee_compareByHorasTrabajadas(void* empleadoUno, void* empleadoDos)
{
    int estado;

    Employee* emp1=(Employee*)empleadoUno;
    Employee* emp2=(Employee*)empleadoDos;

    if(emp1->horasTrabajadas>emp2->horasTrabajadas)
    {
        estado=1;
    }
    else if(emp1->horasTrabajadas < emp2->horasTrabajadas )
    {
        estado=-1;
    }
    else
    {
        estado=0;
    }
    return estado;
}

//_______________________________________________________________

int employee_compareBySueldo(void* empleadoUno, void* empleadoDos)
{
    int estado;

    Employee* emp1=(Employee*)empleadoUno;
    Employee* emp2=(Employee*)empleadoDos;

    if(emp1->sueldo>emp2->sueldo)
    {
        estado=1;
    }
    else if(emp1->sueldo<emp2->sueldo)
    {
        estado=-1;
    }
    else
    {
        estado=0;
    }
    return estado;
}

//_______________________________________________________________
