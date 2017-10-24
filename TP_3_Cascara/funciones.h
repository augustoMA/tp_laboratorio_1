#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[150];
} EMovie;


/** \brief muestra al usuario el menu de opciones.
 * \return void.
 *
 */
void menu(void);


/** \brief muestra al usuario el menu de opciones.
 * \return void.
 */
 void auxMenu(void);

/** \brief Carga las peliculas y recibe la cantidad de peliculas guardadas.
 * \param EMovie* peliculas.
 * \return retorna 0 si leyo o creo el archivo, 1 si no pudo.
 */
int cargarPeliculas(EMovie *peliculas, int*);

/** \brief recibe un string para validarlo.
 * \param cadena de caracteres.
 * \param entero maximo length.
 * \return void.
 */
void valCadena(char cadena[], int);

/** \brief recibe un numero para validarlo.
 * \param numero a validar.
 * \param entero minimo.
 * \param entero maximo.
 * \return retorna el numero.
 */
int valNumero(int, int, int );

/** \brief crea una pelicula.
 * \param EMovie* peliculas.
 * \param entero contador.
 * \param puntero a contador.
 * \return void.
 */
void agregarPelicula(EMovie *peliculas, int, int*);

/** \brief busca una pelicula por su titulo.
 * \param EMovie* peliculas.
 * \return void.
 */
void borrarPelicula(EMovie *peliculas, int);

/** \brief crea un archivo html a con las peliculas cargadas.
 *  \param lista de peliculas para agregar al archivo.
 *  \param contador.
 *  \param nombre del archivo.
 *  \return void.
 */
void paginaWeb(EMovie* peliculas, int, char html[]);

/** \brief muestra las peliculas y permite modificar sus datos.
 * \param EMovie* peliculas.
 * \param entero contador.
 * \return void.
 */
void modificarPelicula(EMovie* peliculas, int);

/** \brief guarda los datos ingresados.
 * \param EMovie* peliculas.
 * \param entero contador.
 * \param puntero al contador.
 * \return entero.
 */
int guardardatos(EMovie* peliculas, int, int*);

#endif // FUNCIONES_H_INCLUDED

