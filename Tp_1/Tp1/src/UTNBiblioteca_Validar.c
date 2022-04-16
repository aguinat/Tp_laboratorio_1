#include "UTNBiblioteca_Validar.h"
#include <stdio.h>


int ValidarIngresoEntero(int *refNumeroEntero) {
	int numeroIngresado;
	int validacion;

	validacion = scanf("%d", &numeroIngresado);

	*refNumeroEntero = numeroIngresado;

	return validacion;
}


int ValidarIngresoFlotante(float *refNumeroFloat) {
	float numeroIngresado;
	int validacion;

	validacion = scanf("%f", &numeroIngresado);

	*refNumeroFloat = numeroIngresado;

	return validacion;
}


int ValidarRango(float numero, int min, int max) {
	int validacion;

	validacion = 0;
	if (numero > min && numero < max) {
		validacion = 1;
	}

	return validacion;
}




