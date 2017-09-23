#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

#define TAM 20

int main()
{
    char seguir='s';
    char set='s';
    int opcion=0;
    ePersona persona[TAM];

    setearA0(persona, TAM);

    do
    {
        menu();

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                alta(persona, TAM);
                system("pause");
                system("cls");
                break;
            case 2:
                eliminar(persona, TAM);
                system("pause");
                system("cls");
                break;
            case 3:
                ordenarYmostrar(persona, TAM);
                system("pause");
                system("cls");
                break;
            case 4:
                grafico(persona, TAM);
                system("pause");
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error. Ingrese una opcion valida(1-5)");
                system("pause");
                system("cls");
        }

    }while(seguir=='s');

    return 0;
}
