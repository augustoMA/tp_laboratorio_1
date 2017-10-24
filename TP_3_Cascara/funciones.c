#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

void menu(void)
{
    printf("\n ___________________________________________\n");
     printf("|             MENU DE OPCIONES              |\n");
     printf("|___________________________________________|\n");
     printf("|1- Agregar pelicula                        |\n");
     printf("|2- Borrar pelicula                         |\n");
     printf("|3- Modificar pelicula                      |\n");
     printf("|4- Generar pagina web                      |\n");
     printf("|5- Salir                                   |\n");
     printf("|___________________________________________|\n");
     printf("\nSeleccione la operacion deseada: ");
}

void auxMenu(void)
{
       printf("\n ___________________________________________\n");
        printf("|             DATOS A MODIFICAR             |\n");
        printf("|___________________________________________|\n");
        printf("|1- Titulo                                  |\n");
        printf("|2- Genero                                  |\n");
        printf("|3- Duracion(en minutos)                    |\n");
        printf("|4- Descripcion                             |\n");
        printf("|5- Puntaje                                 |\n");
        printf("|6- Link a imagen                           |\n");
        printf("|___________________________________________|\n");
        printf("\nSeleccione la operacion deseada: ");
}

int cargarPeliculas(EMovie *peliculas, int* puntero)
{
    FILE *f;
    int flag=0;

    f=fopen("moviesBin.dat", "rb");

    if(f==NULL)
    {
        f= fopen("moviesBin.dat", "wb");

        if(f==NULL)
        {
           return 1;
        }

        flag=1;
    }

    if(flag==0)
    {
        fread(puntero, sizeof(int), 1, f);

        while(!feof(f))
        {
            fread(peliculas,sizeof(EMovie),*puntero, f);
        }
    }
    fclose(f);

    return 0;
}

void mostrar(EMovie *peliculas)
{
    printf("Titulo :%s\nGenero: %s\nDuracion: %d Minutos\nDescripcion: %s\nPuntaje: %d\nLink de imagen: %s\n", peliculas->titulo, peliculas->genero, peliculas->duracion, peliculas->descripcion, peliculas->puntaje, peliculas->linkImagen);
}

void valCadena(char cadena[], int numero)
{
    int largo;

    largo=strlen(cadena);

    while(largo>numero)
    {
        printf("Nombre muy largo. Reingrese: ");
        cadena=gets(cadena);
        largo=strlen(cadena);
    }
}

int valNumero(int numero, int minimo, int maximo)
{
    int aux;
    aux=numero;

    while(aux<minimo || aux>maximo)
    {
        printf("Reingrese: ");
        fflush(stdin);
        scanf("%d", &aux);
    }
    return aux;
}

void agregarPelicula(EMovie *peliculas,int contPeliculas,int* puntero)
{
    char auxTitulo[50];
    char auxGenero[50];
    char auxDescripcion[100];
    char linkImagen[200];
    int lugar;
    int duracion;
    int puntaje;
    int titulo;
    int existe=0;
    int i;

    lugar=contPeliculas-1;

    printf("Ingrese el titulo: ");
    fflush(stdin);
    gets(auxTitulo);

    valCadena(auxTitulo, 49); //20
    titulo=strlen(auxTitulo);

    for(i=0; i<titulo; i++)
    {
        auxTitulo[i]=toupper(auxTitulo[i]);
    }
    for(i=0; i<contPeliculas; i++)//Se verifica que no haya un titulo igual ya ingresado
    {
        if(strcmp(auxTitulo,(peliculas+i)->titulo)==0 && (peliculas+i)->duracion!=0)
        {
            existe=1;
            break;
        }
    }
    if(!existe)//si existe==0 entonces entra
    {
        strcpy((peliculas+lugar)->titulo,auxTitulo);

        printf("Ingrese el genero: ");
        fflush(stdin);
        gets(auxGenero);
        valCadena(auxGenero, 49);//20
        strcpy((peliculas+lugar)->genero,auxGenero);

        printf("Ingrese la duracion(en minutos): ");
        fflush(stdin);
        scanf("%d", &duracion);
        duracion=valNumero(duracion, 0, 200);
        (peliculas+lugar)->duracion=duracion;

        printf("Ingrese la descripcion: ");
        fflush(stdin);
        gets(auxDescripcion);
        valCadena(auxDescripcion, 99); //50
        strcpy((peliculas+lugar)->descripcion,auxDescripcion);

        printf("Ingrese el puntaje: ");
        fflush(stdin);
        scanf("%d", &puntaje);
        puntaje=valNumero(puntaje, 1, 10);
        (peliculas+lugar)->puntaje=puntaje;

        printf("Ingrese el link de la imagen: ");
        fflush(stdin);
        gets(linkImagen);
        valCadena(linkImagen, 199);
        strcpy((peliculas+lugar)->linkImagen,linkImagen);
    }
    else
    {
        printf("ERROR. El titulo ya existe\n");
        *puntero-=1;
    }
}

void borrarPelicula(EMovie *peliculas, int contPeliculas)
{
    char auxtitulo[50];
    char opcion;
    int titulo;
    int flag=0;
    int i;

    printf("\nLista de peliculas\n\n");

    for(i=0; i<contPeliculas; i++)
    {
        if((peliculas+i)->duracion!=0)
        {
            printf("%s\n",(peliculas+i)->titulo);
        }
    }

    printf("Ingrese el titulo de la pelicula a eliminar: ");
    fflush(stdin);
    gets(auxtitulo);
    valCadena(auxtitulo, 49);//20
    titulo=strlen(auxtitulo);

    for(i=0; i<titulo; i++)
    {
        auxtitulo[i]= toupper(auxtitulo[i]); //auxtitulo()titulo
    }
    for(i=0; i<contPeliculas; i++)
    {
        if(strcmp(auxtitulo,(peliculas+i)->titulo)==0 && (peliculas+i)->duracion!=0) //auxtitulo(titulo)
        {
            printf("Pelicula a eliminar:\n");

            mostrar((peliculas + i));

            printf("\nSeguro desea eliminar la pelcula s/n?: ");
            opcion=getche();
            if(opcion=='s')
            {
                (peliculas+i)->duracion=0;
                 printf("\nLa pelicula fue eliminada.\n");
            }
            else
            {
                printf("\nAccion cancelada.\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("La pelicula no esta cargada.\n");
    }
}

void modificarPelicula(EMovie *peliculas, int contPeliculas)
{
    int duracion;
    int puntaje;
    int titulo;
    int existe=0;
    int opcion;
    int lugar;
    int flag=0;
    int i;
    char auxTitulo[50];
    char auxGenero[50];
    char auxDescripcion[100];
    char linkImagen[200];


    printf("Lista de peliculas\n\n");

    for(i=0; i<contPeliculas; i++)
    {
        if((peliculas+i)->duracion!=0)
        {
            printf("%s\n",(peliculas+i)->titulo);
        }
    }

    printf("Ingrese la pelicula a modificar: ");
    fflush(stdin);
    gets(auxTitulo);
    valCadena(auxTitulo, 49);//20
    titulo=strlen(auxTitulo);

    for(i=0; i<titulo; i++)
    {
        auxTitulo[i]=toupper(auxTitulo[i]);
    }
    for(i=0; i<contPeliculas; i++)
    {
        if(strcmp(auxTitulo,(peliculas+i)->titulo)==0 && (peliculas+i)->duracion!=0)
        {
            printf("Pelicula a modificar:\n");

            mostrar((peliculas + i));
            lugar=i;
            auxMenu();
            fflush(stdin);
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese el titulo: ");
                fflush(stdin);
                gets(auxTitulo); //scanf
                valCadena(auxTitulo, 49); //20
                titulo=strlen(auxTitulo);

                for(i=0; i<titulo; i++) //Se verifica que no haya un titulo igual ya ingresado
                {
                    auxTitulo[i]=toupper(auxTitulo[i]);
                }
                for(i=0; i<contPeliculas; i++)
                {
                    if(strcmp(auxTitulo,(peliculas+i)->titulo)==0 && (peliculas+i)->duracion!=0)
                    {
                        existe=1;
                        break;
                    }
                }
                if(!existe)//si existe==0 entonces entra
                {
                    strcpy((peliculas+lugar)->titulo,auxTitulo);
                    printf("Titulo modificado.\n");
                }
                else
                {
                    printf("Titulo existente.\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Ingrese el genero: ");
                fflush(stdin);
                gets(auxGenero);
                valCadena(auxGenero, 49); //20
                strcpy((peliculas+lugar)->genero,auxGenero);
                printf("\nGenero modificado.\n");
                system("pause");
                system("cls");
                break;
            case 3:
                printf("Ingrese la duracion(en minutos): ");
                fflush(stdin);
                scanf("%d", &duracion);
                duracion=valNumero(duracion, 0, 400);
                (peliculas+lugar)->duracion=duracion;
                printf("\nDuracion modificada.\n");
                system("pause");
                system("cls");
                break;
            case 4:
                printf("Ingrese la descripcion: ");
                fflush(stdin);
                gets(auxDescripcion);
                valCadena(auxDescripcion, 99);//50
                strcpy((peliculas+lugar)->descripcion,auxDescripcion);
                printf("\nDescripcion modificada.\n");
                system("pause");
                system("cls");
                break;
            case 5:
                printf("Ingrese el puntaje: ");
                fflush(stdin);
                scanf("%d", &puntaje);
                puntaje=valNumero(puntaje, 1, 10);
                (peliculas+lugar)->puntaje=puntaje;
                printf("\nPuntaje modificado.\n");
                system("pause");
                system("cls");
                break;
            case 6:
                printf("Ingrese el link de la imagen: ");
                fflush(stdin);
                gets(linkImagen);
                valCadena(linkImagen, 199);//50
                strcpy((peliculas+lugar)->linkImagen, linkImagen);
                printf("\nLink modificado.\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("Error. Ingrese una opcion valida(1-6).");
                system("pause");
                system("cls");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("ERROR. La pelicula no esta cargada.\n");
    }
}

int guardardatos(EMovie* peliculas, int contPeliculas, int* puntero)
{
    FILE *f;

    f=fopen("moviesBin.dat","wb");

    if(f == NULL)
    {
        return 1;
    }
    fwrite(puntero,sizeof(int), 1, f);
    fwrite(peliculas,sizeof(EMovie), contPeliculas, f);
    fclose(f);

    return 0;
}

void paginaWeb(EMovie* peliculas, int contPeliculas, char html[])
{
    FILE *f;
    int i;

    strcat(html,".html");
    f=fopen(html,"w");

    if(f == NULL)
    {
        printf("El archivo no se pudo crear.");
        exit(1);
    }

    fprintf(f, "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

    for(i=0; i<contPeliculas; i++)
    {
        if((peliculas+i)->duracion!=0)
        {
            fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a>\n",(peliculas+i)->linkImagen);
            fprintf(f,"<h3><a href='#'>%s</a></h3>\n",(peliculas+i)->titulo);
            fprintf(f,"<ul><li>Genero:%s</li>\n<li>Puntaje:%d</li>\n<li>Duracion:%d</li></ul>\n",(peliculas+i)->genero,(peliculas+i)->puntaje,(peliculas+i)->duracion);
            fprintf(f,"<p>%s</p></article>",(peliculas+i)->descripcion);
        }
    }
    fprintf(f, "</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(f);
}
