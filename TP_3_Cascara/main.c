#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int main()
{
    system("color 2B");
    EMovie* peliculas;
    int contPeliculas=0;
    int* puntero=&contPeliculas;
    char html[50]={"listaPeliculas"};
    char seguir='s';
    int opcion=0;
    int i;

    peliculas=(EMovie*)malloc(sizeof(EMovie)*100);

    if(peliculas==NULL)
    {
        printf("\nError. No hay espacio disponible.\n");
        exit(0);
    }

    for(i=0; i<contPeliculas; i++)
    {
        peliculas->duracion=0;
        peliculas->puntaje=0;
    }

    if(cargarPeliculas(peliculas, puntero))
    {
        printf("Error. El fichero no se puede abrir.");
    }

    while(seguir=='s')
    {
        menu();
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(contPeliculas%100==0)
                {
                    contPeliculas++;
                    EMovie* auxPeliculas;
                    auxPeliculas=(EMovie*)realloc(peliculas,100*sizeof(EMovie));

                    if(auxPeliculas==NULL)
                    {
                        exit(1);
                    }
                    else
                    {
                        peliculas=auxPeliculas;
                        agregarPelicula(peliculas, contPeliculas, puntero);
                    }
                }
                else
                {
                    contPeliculas++;
                    agregarPelicula(peliculas, contPeliculas, puntero);
                }
                system("pause");
                system("cls");
                break;
            case 2:
                borrarPelicula(peliculas, contPeliculas);
                system("pause");
                system("cls");
                break;
            case 3:
                modificarPelicula(peliculas, contPeliculas);
                system("pause");
                system("cls");
               break;
            case 4:
                paginaWeb(peliculas, contPeliculas, html);
                printf("Se creo un archivo html llamado: %s", html);
                if(guardardatos(peliculas, contPeliculas, puntero));
                {
                    printf("\nERROR. El fichero no se pudo abrir.\n");
                }
                system("pause");
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error. Ingrese una opcion valida(1-6)");
                system("pause");
                system("cls");
        }
    }
    return 0;
}
