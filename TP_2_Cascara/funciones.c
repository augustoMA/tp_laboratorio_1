#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

void menu()
{
    printf("\n ___________________________________________\n");
     printf("|             MENU DE OPCIONES              |\n");
     printf("|___________________________________________|\n");
     printf("|1- Agregar persona                         |\n");
     printf("|2- Borrar persona                          |\n");
     printf("|3- Imprimir lista ordenada por  nombre     |\n");
     printf("|4- Imprimir grafico de edades              |\n");
     printf("|5- Salir                                   |\n");
     printf("|___________________________________________|\n");
     printf("\nSeleccione la operacion deseada: ");
}

void setearA0(ePersona persona[], int tam)
{
    int i;

    for (i=0; i<tam; i++)
    {
        persona[i].estado=0;
    }
}

int obtenerEspacioLibre(ePersona persona[], int tam)
{
    int i;
    int resultado;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==0)
        {
            resultado=i;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        resultado=-1;
    }
    return resultado;
}

int buscarPorDni(ePersona persona[], int tam)
{
    int i;
    int resultado;
    int flag=0;
    int dni;

    printf("Ingrese el dni a buscar: ");
    scanf("%d",&dni);

    for(i=0; i<tam; i++)
    {
        if(dni==persona[i].dni && persona[i].estado==1)
        {
            resultado=i;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        resultado=-1;
    }
    return resultado;
}

void alta(ePersona persona[], int tam)
{
    int i;
    char nombre[35];

    i=obtenerEspacioLibre(persona, tam);

    if(i==-1)
    {
        printf("Error. No hay mas espacio.\n");
    }
    else
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nombre);

        while(strlen(nombre)>34)
        {
            printf("\nError. Nombre muy extenso. Reingrese nombre: ");
            fflush(stdin);
            gets(nombre);
        }

        strcpy(persona[i].nombre, nombre);

        printf("\nIngrese edad: ");
        scanf("%d",&persona[i].edad);

        printf("Ingrese D.N.I: ");
        scanf("%d",&persona[i].dni);

        persona[i].estado=1;
    }
}

void ordenarYmostrar(ePersona persona[], int tam)
{
    int i;
    int j;
    ePersona aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre)>0)
            {
                aux=persona[i];
                persona[i]=persona[j];
                persona[j]=aux;
            }
        }
    }

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1)
        {
            printf("\nD.N.I: %d\tNombre: %s\t Edad: %d",persona[i].dni, persona[i].nombre, persona[i].edad);
        }
    }
    printf("\n");
}

void eliminar(ePersona persona[], int tam)
{
    int i;
    char respuesta;

    i=buscarPorDni(persona, tam);

    if(i==-1 || persona[i].estado==0)
    {
        printf("Error. El dni ingresado no existe\n");
    }
    else
    {
        printf("\nD.N.I: %d\tNombre: %s\t Edad: %d", persona[i].dni, persona[i].nombre, persona[i].edad);
        printf("\nDesea eliminar a la persona? s/n: ");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta=='s')
        {
            persona[i].estado=0;
            printf("Persona eliminada con exito\n");
        }
        else
        {
            printf("Accion cancelada con exito\n");
        }
    }
}

void grafico(ePersona persona[], int tam)
{
    int i;
   // int j;
    int cont18=0;
    int cont19_35=0;
    int cont35=0;
    int flag;
    int edadMayor;
    //char grafico[tam][3];
    //char x='*';

    for(i=0; i<tam; i++)
            {
                if(persona[i].edad < 19 && persona[i].estado == 1)
                {
                    cont18++;
                }
                else if(persona[i].edad > 35 && persona[i].estado == 1)
                {
                    cont35++;
                }
                else if(persona[i].edad > 18 && persona[i].edad < 36 && persona[i].estado == 1)
                {
                    cont19_35++;
                }
            }
            system("cls");

            if(cont18>=cont19_35 && cont18>=cont35)
            {
                edadMayor=cont18;
            }
            else
            {
                if(cont19_35>=cont18 && cont19_35>=cont35)
                {
                    edadMayor=cont19_35;
                }
                else
                {
                    edadMayor=cont35;
                }
            }
            for(i=edadMayor; i>0; i--)
            {
                if(i<=cont18)
                {
                    printf("[]");
                }
                if(i<=cont19_35)
                {
                    flag= 1;
                    printf("\t[]");
                }
                if(i<=cont35)
                {
                    if(flag== 0)
                    {
                        printf("\t\t[]");
                    }
                    if(flag=1)
                    {
                        printf("\t[]");
                    }
                }
                printf("\n");
            }
            printf("<18\t19-35\t>35\n");
            printf("\n\nPresione una tecla para regresar al menu principal...\n");

            getch();
            system("cls");
           // break;

    /*
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1)
        {
            if(persona[i].edad<18)
            {
                men18+=1;
            }
            else
            {
                if(persona[i].edad>17 && persona[i].edad<35)
                {
                    ent18y35+=1;
                }
                else
                {
                    may35+=1;
                }
            }
        }
    }

    for(i=0; i<men18; i++)
    {
        grafico[i][0]=x;
    }
    for(i=0; i<ent18y35; i++)
    {
        grafico[i][1]=x;
    }
    for(i=0; i<may35; i++)
    {
        grafico[i][2]=x;
    }

    for(i=tam-1; i>=0; i--)
    {
        for(j=0; j<3; j++)
        {
            if(grafico[i][0]+grafico[i][1]+grafico[i][2]==0)
            {
                break;
            }

            printf(" %c\t",grafico[i][j]);
        }
        if(grafico[i][0]+grafico[i][1]+grafico[i][2]!=0)
        {
            printf("\n");
        }
    }
    printf("-18\t18-35\t+35\n");*/
}
