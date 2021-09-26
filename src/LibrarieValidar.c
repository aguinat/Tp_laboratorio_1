#include "LibrarieImput.h"

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


int ValidarRango(int numero, int min, int max) {
	int respuesta;

	respuesta = 0;
	if (numero > min && numero < max) {
		respuesta = 1;
	}

	return respuesta;
}


int ValidarSigno(int numero) {
	int respuesta;
	if (numero > 0) {
		respuesta = 1;
	} else {
		if (numero < 0) {
			respuesta = 0;
		}
	}

	return respuesta;
}


int ValidarEsPar(int numero) {
	int respuesta;

	if (numero % 2 == 0) {
		respuesta = 1;
	} else {
		respuesta = 0;
	}

	return respuesta;
}


