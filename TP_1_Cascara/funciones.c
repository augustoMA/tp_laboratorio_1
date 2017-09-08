#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

void menu(int flag1, float numeroN1, int flag2, float numeroN2)
{
    printf("\n __________________________________________\n");
      printf("|          MENU DE CALCULADORA             |\n");
      printf("|__________________________________________|\n");

        if(flag1 == 0)
        {
        printf("|1- Ingresar primer valor numerico para N1 |\n");
        }
        else
        {
        printf("|1- El valor numerico ingresado es:(N1=%.1f)|\n", numeroN1);
        }
        if(flag2 == 0)
        {
            printf("|2- Ingresar segundo valor numerico para N2|\n");
        }
        else
        {
            printf("|2- El valor numerico ingresado es:(N2=%.1f)|\n",numeroN2);
        }

      printf("|3- Calcular la suma (N1+N2)               |\n");
    printf("|4- Calcular la resta (N1-N2)              |\n");
    printf("|5- Calcular la division (N1/N2)           |\n");
    printf("|6- Calcular la multiplicacion (N1*N2)     |\n");
     printf("|7- Calcular el factorial (N1!)            |\n");
      printf("|8- Calcular todas las operaciones         |\n");
      printf("|9- Salir                                  |\n");
      printf("|__________________________________________|\n");
      printf("\nSeleccione la operacion deseada: ");
}

float pedirNumero(char letra[])
{
    float numero;
    printf("\nIngrese un numero para %s: ", letra);
    scanf("%f", &numero);

    return numero;
}

void suma(int flag1, int flag2, float num1, float num2)
{
    float resultdo;

     if(flag1 == 0 || flag2 == 0)
                {
                    printf("\nLa suma no puede realizarse, debe cargar valores.\n\n");
                }
                else
                {
                    resultdo= num1+num2;
                    printf("\nEl resultado de la suma es: %.1f\n\n", resultdo);
                }
}

void resta(int flag1, int flag2, float num1, float num2)
{
    float resultado;

     if(flag1 == 0 || flag2 == 0)
                {
                    printf("\nLa resta no puede realizarse, debe cargar valores.\n\n");
                }
                else
                {
                    resultado= num1-num2;
                    printf("\nEl resultado de la resta es: %.1f\n\n", resultado);
                }
}

void division(int flag1, int flag2, float num1, float num2)
{
    float resultado;

     if(flag1 == 0 || flag2 == 0)
                {
                    printf("\nLa division no puede realizarse, debe cargar valores.\n\n");
                }
                else
                {
                    resultado= num1/num2;
                    printf("\nEl resultado de la division es: %.1f\n\n", resultado);
                }
}

void multiplicacion(int flag1, int flag2, float num1, float num2)
{
    float resultado;

     if(flag1 == 0 || flag2 == 0)
                {
                    printf("\nLa multiplicacion no puede realizarse, debe cargar valores.\n\n");
                }
                else
                {
                    resultado= num1*num2;
                    printf("\nEl resultado de la multiplicacion es: %.1f\n\n", resultado);
                }
}

void factorial(float num1, int flag1)
{
    int Aux=(int)num1;
    int factorial=1;
    int i;

     if(flag1 == 0)
                {
                    printf("\nEl factorial no puede realizarse, debe cargar valores.\n\n");
                }
                else
                {
                    if(num1<0)
                    {
                        printf("\nNo puede obtenerse el factorial de un numero negativo.\n\n");
                    }
                    else if(num1!=Aux)
                    {
                        printf("\nNo puede obtenerse el factorial de un numero flotante.\n\n");
                    }
                    else
                    {
                        for(i=1; i<=num1; i++)
                        {
                            factorial = factorial*i;
                        }
                        printf("\nEl factorial de N1 es: %d\n\n",factorial);
                    }
                }
}

void mostrarTodo(int flag1, int flag2, float num1,float num2)
{
    suma(flag1, flag2, num1, num2);
    resta(flag1, flag2, num1, num2);
    division(flag1, flag2, num1, num2);
    multiplicacion(flag1, flag2, num1, num2);
    factorial(num1, flag1);
}


