#include <stdio.h>
#include <stdlib.h>
#include "LibrarieImput.h"
#include "LibrarieValidar.h"

#define REINTENTOS 5

int main(void) {
	setbuf(stdout, NULL);
	float numeroA;
	float numeroB;
	int opcion;
	int operacionValida;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFatorialA;
	int resultadoFatorialB;
	int flagNumeroA;
	int flagNumeroB;
	int flagOpcion3;


	//inicializacion de variables
	flagOpcion3 = 0;
	flagNumeroA = 0;
	flagNumeroB = 0;

	printf("¡Bienvenido!\n");

	do {
		printf("\n1. Ingresar Primer operador \n2. Ingresar Segundo operador \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir");
		opcion = PedirEntero("\nIngrese una opcion:", "\nOpcion ingresada erronea!", REINTENTOS, &operacionValida);

		if(operacionValida == 1){
			switch (opcion) {
			case 1:
				numeroA = PedirNumero("\nIngrese el primer numero: ", "Error.", REINTENTOS);
				flagNumeroA = 1;
				if(flagNumeroA==1){
					printf("\nA = %.2f", numeroA);
					if(flagNumeroB == 0){
						numeroB = 0;
						printf("\nB = %.2f\n", numeroB);
					}else{
						printf("\nB = %.2f\n", numeroB);
					}
				}

				break;
			case 2:
				numeroB = PedirNumero("\nIngrese el segundo numero: ", "Error.", REINTENTOS);
				flagNumeroB = 1;
				if(flagNumeroB ==1){
					printf("\nB = %.2f", numeroB);
					if(flagNumeroA == 0){
						numeroA = 0;
						printf("\nA = %.2f\n", numeroA);
					}else{
						printf("\nA = %.2f\n", numeroA);
					}
				}

				break;
			case 3:
				if(flagNumeroA == 1 && flagNumeroB == 1 ){
					resultadoSuma = SumarNumeros(numeroA, numeroB);
					resultadoResta = RestarNumeros(numeroA, numeroB);
					operacionValida = DivisionNumeros(numeroA, numeroB, &resultadoDivision);
					resultadoMultiplicacion = MultiplicarNumeros(numeroA, numeroB);
					resultadoFatorialA = FactorialDeUnNumeroFloat(numeroA);
					resultadoFatorialB = FactorialDeUnNumeroFloat(numeroB);

					flagOpcion3 = 1;
				}else{
					printf("\nPara realizar las operaciones debe ingresar ambos numeros.");
				}

				break;
			case 4:
				if(flagOpcion3 == 1){
					printf("\nEl resultado de %.2f + %.2f es: %.2f\n", numeroA, numeroB, resultadoSuma);

					printf("\nEl resultado de %.2f - %.2f es: %.2f\n", numeroA, numeroB, resultadoResta);

					if (operacionValida == 1) {
						printf("\nEl resultado de %.2f / %.2f es: %.2f\n", numeroA, numeroB, resultadoDivision);
					} else {
						printf("\nError, no se puede dividir por cero.\n");
					}

					printf("\nEl resultado de %.2f x %.2f es: %.2f\n", numeroA, numeroB, resultadoMultiplicacion);

					//Resultado Factorial A
					if (resultadoFatorialA == -1) {
						printf("\nError, no se puede realizar factoral de un numero negativo.\n");
					} else {
					printf("\nEl factorial de %.2f es: %d\n", numeroA, resultadoFatorialA);
					}

					//Resultado Factorial B
					if (resultadoFatorialB == -1) {
						printf("\nError, no se puede realizar factoral de un numero negativo.\n");
					} else {
						printf("\nEl factorial de %.2f es: %d\n", numeroB, resultadoFatorialB);
					}
				}else{
					printf("\nNo hay resultados que informar, usted no realizo ninguna operacion.\n");
				}
				break;
			}
		}else{
			opcion = 5;
			printf("\nEl programa finalizo debido a que no se ingreso ninguna opcion valida\n");
		}
	} while (opcion != 5);
	printf("\nUsted salio del programa :(  \n¡Que tenga un buen dia!");

	return EXIT_SUCCESS;
}
