#include "LibrarieImput.h"

#include "LibrarieValidar.h"

int PedirEntero(char mensaje[], char mensajeError[],int reintentos, int* refValidacion) {
	int numeroIngresado;
	int validacion;

	do {
		printf("%s ", mensaje);
		validacion = ValidarIngresoEntero(&numeroIngresado);
		if (validacion != 1) {
			printf("%s ", mensajeError);
			fflush(stdin);
			reintentos--;
		} else {
			reintentos = 0;
		}

	} while (reintentos > 0);

	*refValidacion = validacion;

	return numeroIngresado;
}


float PedirNumero(char mensaje[], char mensajeError[], int reintentos) {
	float numeroIngresado;

	do {
		printf("%s", mensaje);
		if (ValidarIngresoFlotante(&numeroIngresado) != 1) {
			printf("%s ", mensajeError);
			fflush(stdin);
			reintentos--;
		} else {
			reintentos = 0;
		}

	} while (reintentos > 0);

	return numeroIngresado;
}


int PedirNumConRango(char mensaje[], int min, int max) {
	int numeroIngresado;

	do {
		printf("%s", mensaje);
		scanf("%d", &numeroIngresado);
	} while (ValidarRango(numeroIngresado, min, max) == 0);

	return numeroIngresado;
}


float SumarNumeros(float numero1, float numero2) {
	float resultado;
	resultado = numero1 + numero2;
	return resultado;
}


float RestarNumeros(float numero1, float numero2){
	float resultado;
	resultado = numero1 - numero2;
	return resultado;
}


int DivisionNumeros(float numero1, float numero2, float* refResultado){
	int operacionValida;
	float resDivision;
	if(numero2 == 0 ){
		operacionValida = 0;
	}else{
		resDivision = numero1/numero2;
		operacionValida = 1;
	}
	*refResultado = resDivision;

	return operacionValida;
}


float MultiplicarNumeros(float numero1, float numero2){
	float resultado;
	resultado = numero1 * numero2;

	return resultado;
}


int FactorialDeUnNumeroFloat(float numeroIngresado) {
	int resultado;

	if ((int)numeroIngresado == 0) {
		resultado = 1;
	} else {
		if((int)numeroIngresado>0){
		resultado = (int)numeroIngresado * FactorialDeUnNumeroFloat((int)numeroIngresado - 1);
		}else{
			resultado = -1;
		}
	}

	return resultado;
}


int FactorialDeUnNumero(int numeroIngresado) {
	int resultado;

	if (numeroIngresado == 0) {
		resultado = 1;
	} else {
		if(numeroIngresado>0){
		resultado = numeroIngresado * FactorialDeUnNumero(numeroIngresado - 1);
		}else{
			resultado = -1;
		}
	}

	return resultado;
}


int SumaAntecesores(int numero) {
	int acumulador;
	acumulador = 0;

	do {
		acumulador = numero + acumulador;

		if (numero < 0) {
			numero = numero + 1;
		} else {
			numero = numero - 1;
		}

	} while (numero != 0);

	return acumulador;
}


void Swap(int numero1, int numero2, int *refNumero1, int *refNumero2) {
	int aux;
	aux = numero1;
	*refNumero1 = numero2;
	*refNumero2 = aux;
}

