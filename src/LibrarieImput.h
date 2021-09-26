#ifndef LIBRARIEIMPUT_H_
#define LIBRARIEIMPUT_H_

#include <stdio.h>

/// \fn int PedirEntero(char[], char[], int, int*)
/// \brief Pide un numero de entero, validando que se haya ingresado un numero
/// \param Mensaje el mensaje que se mostrar para pedir el numero entero
/// \param MensajeError el mensaje de error en caso de que no se ingrese un numero
/// \param Reintentos la cantidad de reintentos para volver a ingresar un numero
/// \param refValidacion la direccion en memoria de la variable "validacion"
/// \return El numero entero ingresado
int PedirEntero(char mensaje[], char mensajeError[],int reintentos, int* refValidacion);

/// \fn float PedirNumero(char[], char[], int)
/// \brief Pide un numero cualquiera, validando que ingresen unicamente numeros
/// \param Mensaje el mensaje que se mostrara al pedir un numero
/// \param MensajeError el mensaje de error que se mostrara en caso de no ingresar un numero
/// \param Reintentos la cantidad de reintentos para volver a ingresar un numero
/// \return El numero (con decimales) ingresado
float PedirNumero(char mensaje[], char mensajeError[], int reintentos);

/// \fn float SumarNumeros(float, float)
/// \brief Suma dos numeros de tipo flotante
/// \param numero1 El primer numero que sumara
/// \param numero2 El segundo numero que sumara
/// \return El resultado de la suma
float SumarNumeros(float numero1, float numero2);

/// \fn float RestarNumeros(float, float)
/// \brief Resta dos numeros de tipo flotante
/// \param numero1 El primer numero que se que se restara
/// \param numero2 El segundo numero que se que se restara
/// \return El resultado
float RestarNumeros(float numero1, float numero2);

/// \fn int DivisionNumeros(float, float, float*)
/// \brief Realiza la division entre dos numeros flotantes siempre que el divisor no sea 0
/// \param numero1 El dividendo
/// \param numero2 El divisor
/// \param refResultado El resultado de la division
/// \return Informa si se pudo realizar la division o no.
int DivisionNumeros(float numero1, float numero2, float* refResultado);

/// \fn float MultiplicarNumeros(float, float)
/// \brief Multiplica dos numeros de tipo flotante
/// \param numero1 El primer numero a multiplicar
/// \param numero2 El segundo numero que se va a multiplicar con el primero
/// \return El resultado de la multiplicacion
float MultiplicarNumeros(float numero1, float numero2);

/// \fn float FactorialDeUnNumeroFloat(float)
/// \brief Realiza el factorial de un numero positivo
/// \param numero El numero que se va a buscar el factorial
/// \return El resultado del factorial o -1 en caso de que sea un numero negativo
int FactorialDeUnNumeroFloat(float numero);

/// \fn int FactorialDeUnNumero(int)
/// \brief Realiza el factorial de un numero positivo
/// \param numero El numero que se va a buscar el factorial
/// \return El resultado del factorial o -1 en caso de que sea un numero negativo
int FactorialDeUnNumero(int numero);

/// \fn int PedirNumConRango(char[], int, int)
/// \brief Pide un numero en un rango determinado por el usuario
/// \param mensaje El mensaje que se mostrara al pedir el numero
/// \param desdeElNumero El numero minimo del rango
/// \param hastaElNumero El numero maximo del rango
/// \return El numero ingresado
int PedirNumConRango(char mensaje[], int desdeElNumero, int hastaElNumero);


/// \fn int SumaAntecesores(int)
/// \brief Suma los numeros antecesores hasta 0 de un numero
/// \param numero El numero del cual se sumaran los antecesores
/// \return El resultado de la suma
int SumaAntecesores(int numero);

/// \fn void Swap(int, int, int*, int*)
/// \brief Intercambia los valores de dos variables de tipo de int
/// \param numero1 El valor de la variable int 1
/// \param numero2 El valor de la variable int 2
/// \param refNumero1 La direccion en memoria de la variable int 1
/// \param refNumero2 La direccion en memoria de la variable int 2
void Swap(int numero1, int numero2, int* refNumero1, int* refNumero2);


#endif /* LIBRARIEIMPUT_H_ */
