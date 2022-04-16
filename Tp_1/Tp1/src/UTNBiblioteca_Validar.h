#ifndef UTNBIBLIOTECA_VALIDAR_H_
#define UTNBIBLIOTECA_VALIDAR_H_

/// \fn int ValidarIngresoEntero(int*)
/// \brief Valida que el numero ingresado sea un numero y no una letra, etc
/// \param refNumeroEntero La direccion en memoria de la variable donde se va a guardar el numero ingresado
/// \return Informa 1 en caso de que pudo guardar el valor y 0 en caso de no poder por no ser un numero
int ValidarIngresoEntero(int* refNumeroEntero);

/// \fn int ValidarIngresoFlotante(float*)
/// \brief Valida que el numero ingresado sea un numero y no una letra, etc
/// \param refNumeroFloat La direccion en memoria de la variable donde se va a guardar el numero ingresado
/// \return Informa 1 en caso de que pudo guardar el valor y 0 en caso de no poder por no ser un numero
int ValidarIngresoFlotante(float *refNumeroFloat);

/// \fn int ValidarRango(int, int, int)
/// \brief Valida el rango en el que debe encontrarse un numero determinado
/// \param numero El numero ue debe ser validado
/// \param min El valor minimo del rango
/// \param max El valor maximo del rango
/// \return Devuelve 1 si esta en el rango, y 0 en caso de que este fuera de rango
int ValidarRango(float numero, int min, int max);


#endif /* UTNBIBLIOTECA_VALIDAR_H_ */
