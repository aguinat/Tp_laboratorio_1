#include "UTNBiblioteca_Input.h"
#include "UTNBiblioteca_Validar.h"
#include <stdio.h>

int PedirEntero(char mensaje[], char mensajeError[],int reintentos, int* numeroEntero) {
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
			*numeroEntero = numeroIngresado;
			reintentos = 0;
		}

	} while (reintentos > 0);


	return validacion;
}


int PedirNumero(char mensaje[], char mensajeError[], int reintentos, float* numeroFloat) {
	float numeroIngresado;
	int validacion;

	do {
		printf("%s", mensaje);
		validacion = ValidarIngresoFlotante(&numeroIngresado);
		if (validacion != 1) {
			printf("%s ", mensajeError);
			fflush(stdin);
			reintentos--;
		} else {
			*numeroFloat = numeroIngresado;
			reintentos = 0;
		}

	} while (reintentos > 0);

	return validacion;
}


int PedirNumConRango(char mensaje[], int min, int max, float* numeroFloat) {
	float numeroIngresado;
	int validacion;

	do {
		printf("%s", mensaje);
		scanf("%f", &numeroIngresado);
		validacion = ValidarRango(numeroIngresado, min, max);
		if(validacion!=0){
			*numeroFloat = numeroIngresado;
		}
	} while (validacion == 0);

	return validacion;
}



float RestarNumeros(float numero1, float numero2){
	float resultado;

	if(numero1 > numero2){
		resultado = numero1 - numero2;
	}else{
		resultado = numero2 - numero1;
	}

	return resultado;
}


int DivisionNumeros(float divisor, float dividendo, float* refResultado){
	int operacionValida;
	float resDivision;
	if(divisor == 0 ){
		operacionValida = 0;
	}else{
		resDivision = dividendo/divisor;
		*refResultado = resDivision;
		operacionValida = 1;
	}

	return operacionValida;
}


float MultiplicarNumeros(float numero1, float numero2){
	float resultado;
	resultado = numero1 * numero2;

	return resultado;
}

float CalcularPorcentaje(float numero, float porcentaje, int sumarPorcentaje){
	float resultadoPorcentaje;
	float agregarPorcentaje;
	float descontarPorcentaje;

	resultadoPorcentaje = (numero * porcentaje)/100;
	if(sumarPorcentaje == 1){
		agregarPorcentaje = numero + resultadoPorcentaje;
		return agregarPorcentaje;
	}else{
		descontarPorcentaje = numero - resultadoPorcentaje;
		return descontarPorcentaje;
	}


}

float CalcularBTC(float numero, float precioBTC){
	int i;
	float resultado;
	i = 1;

	resultado = (i*numero)/precioBTC;

	return resultado;

}

