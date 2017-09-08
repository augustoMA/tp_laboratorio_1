#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
* \brief recibe dos flag y dos flotantes, muestra el menu de opciones
* \param flag1 variable para validar la existencia de un numero
* \param float numeroN1 primer numero ingresado
* \param flag2 variable para validar la existencia de un numero
* \param float numeroN2 segundo numero ingresado
* \return retorna void
*
*/
void menu(int flag1, float numeroN1, int flag2, float numeroN2);

/**
* \brief recibe un string y solicita al usuario ingresar un numero
* \param char letra[] es el string que recibe
* \return retorna el numero ingresado
*
*/
float pedirNumero(char letra[]);

/**
* \brief recibe dos flag y dos flotantes, realiza la suma de los flotantes
* \param flag1 variable para validar la existencia de un numero
* \param flag2 variable para validar la existencia de un numero
* \param float num1 primer numero ingresado
* \param float num2 segundo numero ingresado
* \return retorna void
*/
void suma(int flag1, int flag2, float num1, float num2);

/**
* \brief recibe dos flag y dos flotantes,realiza la resta de los flotantes
* \param flag1 variable para validar la existencia de un numero
* \param flag2 variable para validar la existencia de un numero
* \param float num1 primer numero ingresado
* \param float num2 segundo numero ingresado
* \return retorna void
*
*/
void resta(int flag1, int flag2, float num1, float num2);

/**
* \brief recibe dos flag y dos flotantes, realiza la division de los flotantes
* \param flag1 variable para validar la existencia de un numero
* \param flag2 variable para validar la existencia de un numero
* \param float num1 primer numero ingresado
* \param float num2 segundo numero ingresado
* \return retorna void
*
*/
void division(int flag1, int flag2, float num1, float num2);

/**
* \brief recibe dos flag y dos flotantes, realiza la multiplicacion de los flotantes
* \param flag1 variable para validar la existencia de un numero
* \param flag2 variable para validar la existencia de un numero
* \param float num1 primer numero ingresado
* \param float num2 segundo numero ingresado
* \return retorna void
*
*/
void multiplicacion(int flag1, int flag2, float num1, float num2);

/**
* \brief recibe un flotante y un flag, realiza el factorial del flotantes
* \param flag1 variable para validar la existencia de un numero
* \param float num1 primer numero ingresado
* \return retorna void
*
*/
void factorial(float num1, int flag1);

/**
* \brief recibe dos flag y dos flotantes, muestra el resultado de las operaciones
* \param flag1 variable para validar la existencia de un numero
* \param flag2 variable para validar la existencia de un numero
* \param float num1 primer numero ingresado
* \param float num2 segundo numero ingresado
* \return retorna void
*
*/
void mostrarTodo(int flag1, int flag2, float num1,float num2);


#endif // FUNCIONES_H_INCLUDED
