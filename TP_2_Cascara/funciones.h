#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/** \brief muestra al usuario el menu de opciones.
 *
 * \return void.
 *
 */
void menu(void);


/** \brief Obtiene el primer indice libre del array.
 *
 * \param persona el array se pasa como parametro.
 * \param cantidad de usuarios.
 * \return el primer indice disponible.
 *
 */
int obtenerEspacioLibre(ePersona[], int);


/** \brief Busca el dni y obtiene el indice que coincide.
 *
 * \param persona el array se pasa como parametro.
 * \param cantidad de usuarios.
 * \return el indice en donde se encuentra el elemento que coincide con el dni.
 *
 */
int buscarPorDni(ePersona[], int);


/** \brief Inicializa todos los estados en 0.
 *
 *  \param persona anida el estado del usuario, 1 para su alta y 0 para su baja.
 *  \param cantidad de usuarios.
 *  \return void.
 *
 */
void setearA0(ePersona[], int);


/** \brief toma los datos y los guarda o advierte falta de espacio.
 *
 * \param estructura "persona"
 * \return void.
 *
 */
 void alta(ePersona[], int tam);


/** \brief muestra en pantalla los datos de la estructura.
 *
 * \param estructura "persona".
 * \param cantidad de usuarios.
 * \return void.
 *
 */
 void ordenarYmostrar(ePersona[], int);


 /** \brief elimina al usuario deseado.
 *
 * \param estructura "persona".
 * \return void.
 *
 */
 void eliminar(ePersona[], int);


 /** \brief genera una matriz y luego la grafica.
 *
 * \param estructura "persona"
 * \param cantidad de usuarios.
 * \return void.
 *
 */
 void grafico(ePersona persona[], int);

#endif // FUNCIONES_H_INCLUDED
