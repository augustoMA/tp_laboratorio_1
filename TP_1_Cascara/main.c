#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroN1;
    float numeroN2;
    int flag1=0;
    int flag2=0;

    do
    {
        menu(flag1, numeroN1, flag2, numeroN2);

        fflush(stdin);

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            numeroN1= pedirNumero("N1");
            flag1=1;
            system("cls");
            break;
        case 2:
            numeroN2= pedirNumero("N2");
            flag2=1;
            system("cls");
            break;
        case 3:
            suma(flag1,flag2, numeroN1, numeroN2);
            system("pause");
            system("cls");
            break;
        case 4:
            resta(flag1,flag2, numeroN1, numeroN2);
            system("pause");
            system("cls");
            break;
        case 5:
            division(flag1,flag2, numeroN1, numeroN2);
            system("pause");
            system("cls");
            break;
        case 6:
            multiplicacion(flag1,flag2, numeroN1, numeroN2);
            system("pause");
            system("cls");
            break;
        case 7:
            factorial(numeroN1, flag1);
            system("pause");
            system("cls");
            break;
        case 8:
            mostrarTodo(flag1,flag2, numeroN1, numeroN2);
            system("pause");
            system("cls");
            break;
        case 9:
            seguir = 'n';
            break;
        default:
            printf("Error. Reingrese una opcion valida (1-9)\n\n");
            system("pause");
            system("cls");
            break;
        }
    } while(seguir=='s');

    return 0;
}
