#include <stdio.h>
#include <stdlib.h>

#include "Operaciones.h"

int main()
{
    float numeroUno;
    float numeroDos;
    int opcion;
    char seguir='s';
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    float resultadoFactoreoA;
    float resultadoFactoreoB;
    int divisionPorCero;
    int factoreoNegativoA;
    int factoreoNegativoB;

    do
    {

        printf("1. Ingrese el primer numero - A=%.2f.\n2. Ingrese el segundo numero - B=%.2f.\n3. Calcule las operaciones.\n4. Informar resultados.\n5. Salir.\nElija una opcion: ",numeroUno,numeroDos);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese el primer numero: ");
            numeroUno=pedirNumero();

        break;
        case 2:
                printf("Ingrese el segundo numero: ");
                numeroDos=pedirNumero();

        break;
        case 3:
            resultadoSuma=sumarNumeros(numeroUno,numeroDos);
            resultadoResta=restarNumeros(numeroUno,numeroDos);
            resultadoMultiplicacion=multiplicarNumeros(numeroUno,numeroDos);
            if(numeroDos==0)
                divisionPorCero=1;
            else
            {
                resultadoDivision=dividirNumeros(numeroUno,numeroDos);
                divisionPorCero=0;
            }
            if(numeroUno<0)
                factoreoNegativoA=1;
            else
            {
                resultadoFactoreoA=factorial(numeroUno);
                factoreoNegativoA=0;
            }
            if(numeroDos<0)
                factoreoNegativoB=1;
            else
            {
                resultadoFactoreoB=factorial(numeroDos);
                factoreoNegativoB=0;
            }
        break;
        case 4:
            mostrarResultados(resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, divisionPorCero, resultadoFactoreoA, factoreoNegativoA, resultadoFactoreoB, factoreoNegativoB);
        break;
        case 5:
            printf("Estoy saliendo del programa\n");
            seguir='n';
        break;
        default:
            printf("No ingreso una ocion valida\n");
        break;
        }

        system("pause");
        system("cls");
    }while(seguir=='s');

    return 0;
}
