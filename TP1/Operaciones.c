#include <stdio.h>
#include "Operaciones.h"

float pedirNumero(void)
{
    float x;

        scanf("%f",&x);

    return x;
}

float sumarNumeros(float numeroUno, float numeroDos)
{
    float resultado;

    resultado=numeroUno+numeroDos;

    return resultado;
}

float restarNumeros(float numeroUno, float numeroDos)
{
    float resultado;

    resultado=numeroUno-numeroDos;

    return resultado;
}

float multiplicarNumeros(float numeroUno, float numeroDos)
{
    float resultado;

    resultado=numeroUno*numeroDos;

    return resultado;
}

float dividirNumeros(float numeroUno, float numeroDos)
{
    float resultado;

    resultado=numeroUno/numeroDos;

    return resultado;
}

float factorial(float numero)
{
    float resultado;
    if(numero==0 || numero ==1)
    {
        resultado=1;
    }
    else
    {
        resultado=numero * factorial(numero-1);
    }
    return resultado;
}

void mostrarResultados(float resultadoSuma, float resultadoResta, float resultadoMultiplicacion, float resultadoDivision, int flagDivision, float resultadoFactoreoA, int flagFactoreoA, float resultadoFactoreoB, int flagFactoreoB)
{
    printf("El resultado de la suma es: %.2f\n",resultadoSuma);

    printf("El resultado de la resta es: %.2f\n",resultadoResta);

    printf("El resultado de la multiplicacion es: %.2f\n",resultadoMultiplicacion);

    if(flagDivision==1)
    {
        printf("Error. No se puede dividir por cero\n");
    }
    else
    {
        printf("El resultado de la division es: %.2f\n",resultadoDivision);
    }

    if(flagFactoreoA==1)
    {
        printf("No se puede hacer el factorial de un numero negativo\n");
    }
    else
    {
        printf("El resultado del factoreo del primer numero es: %.2f\n",resultadoFactoreoA);
    }

    if(flagFactoreoB==1)
    {
        printf("No se puede hacer el factorial de un numero negativo\n");
    }
    else
    {
        printf("El resultado del factoreo del segundo numero es: %.2f\n",resultadoFactoreoB);
    }
}
