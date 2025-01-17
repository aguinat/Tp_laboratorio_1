#include "UTNBiblioteca_Input.h"
#include <stdlib.h>
#include <stdio.h>

#define REINTENTOS 3
#define DESCUENTO 10
#define INTERES 25
#define BTC 4621005.13

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcionAerolinea;
	int operacionValida;
	float kilometrosIngresados;
	float precioAerolineas;
	float precioLatam;

	float precioUnitarioAerolineas;
	float precioConDescuentoAerolineas;
	float precioConInteresAerolineas;
	float resultadoBitcoinAerolineas;

	float precioUnitarioLatam;
	float precioConDescuentoLatam;
	float precioConInteresLatam;
	float resultadoBitcoinLatam;

	float diferenciaDePrecios;

	int flagKilometrosCargados;
	int flagPrecioAerolineas;
	int flagPrecioLatam;
	int flagOpcion3;

	//inicializacion de variables
	flagKilometrosCargados = 0;
	flagPrecioAerolineas = 0;
	flagPrecioLatam = 0;
	flagOpcion3 = 0;

	printf("�Bienvenido a la agencia UTN!\n");

	do {
		puts("\n1. Ingresar Kil�metros"
				"\n2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)"
				"\n3. Calcular todos los costos:"
				"\n4. Informar Resultados"
				"\n5. Carga forzada de datos"
				"\n6. Salir");
		operacionValida = PedirEntero("\nIngrese una opcion:",
				"\nOpcion ingresada erronea!", REINTENTOS, &opcion);

		if (operacionValida == 1) {
			switch (opcion) {
			case 1:
				operacionValida = PedirNumConRango("\nIngrese los kilometros: ",
						10, 14000, &kilometrosIngresados);
				if (operacionValida == 1) {
					flagKilometrosCargados = 1;
				}
				break;

			case 2:
				do {
					puts("\n1. Ingresar Precio Aerol�neas"
							"\n2. Ingresar Precio Latam"
							"\n3. Volver");
					operacionValida = PedirEntero("\nElija una aerolinea:",
							"\nOpcion ingresada erronea!", REINTENTOS,
							&opcionAerolinea);
					if (operacionValida == 1) {
						switch (opcionAerolinea) {
						case 1:
							operacionValida = PedirNumConRango(
									"\nIngresar Precio para Aerolineas: ", 10,
									10000, &precioAerolineas);
							if (operacionValida == 1) {
								flagPrecioAerolineas = 1;
							}
							break;
						case 2:
							operacionValida = PedirNumConRango(
									"\nIngresar Precio para Latam: ", 10, 10000,
									&precioLatam);
							if (operacionValida == 1) {
								flagPrecioLatam = 1;
							}
							break;
						}
					}
				} while (opcionAerolinea != 3);
				break;

			case 3:
				if (flagPrecioLatam == 1 && flagPrecioAerolineas == 1
						&& flagKilometrosCargados == 1) {
					flagOpcion3 = 1;
					//Precios Aerolineas
					DivisionNumeros(kilometrosIngresados, precioAerolineas,
							&precioUnitarioAerolineas);
					precioConDescuentoAerolineas = CalcularPorcentaje(
							precioAerolineas, DESCUENTO, 0);
					precioConInteresAerolineas = CalcularPorcentaje(
							precioAerolineas, INTERES, 1);
					resultadoBitcoinAerolineas = CalcularBTC(precioAerolineas,
							BTC);
					//Precios Latam
					DivisionNumeros(kilometrosIngresados, precioLatam,
							&precioUnitarioLatam);
					precioConDescuentoLatam = CalcularPorcentaje(precioLatam,
							DESCUENTO, 0);
					precioConInteresLatam = CalcularPorcentaje(precioLatam,
							INTERES, 1);
					resultadoBitcoinLatam = CalcularBTC(precioLatam, BTC);

					//Diferencia de precios
					diferenciaDePrecios = RestarNumeros(precioLatam,
							precioAerolineas);

				} else {
					printf(
							"\nPara realizar las operaciones debe ingresar todos los datos requeridos (Kilometros, precios Latam y Aerolineas)\n");
				}
				break;
			case 4:
				if (flagOpcion3 == 1) {
					printf("\nKilometros ingresados: %.2f km"
							"\n\nLatam:"
							"\na) Precio con tarjeta de d�bito: $ %.2f"
							"\nb) Precio con tarjeta de cr�dito: $ %.2f"
							"\nc) Precio pagando con bitcoin: BTC %f"
							"\nd) Precio unitario:  %.2f"

							"\n\nAerol�neas:"
							"\na) Precio con tarjeta de d�bito: $ %.2f"
							"\nb) Precio con tarjeta de cr�dito: $ %.2f"
							"\nc) Precio pagando con bitcoin: BTC %f"
							"\nd) Precio unitario: $ %.2f"

							"\n\nLa diferencia de precio es: $ %.2f\n",
							kilometrosIngresados, precioConDescuentoAerolineas,
							precioConInteresAerolineas,
							resultadoBitcoinAerolineas,
							precioUnitarioAerolineas, precioConDescuentoLatam,
							precioConInteresLatam, resultadoBitcoinLatam,
							precioUnitarioLatam, diferenciaDePrecios);

				} else {
					printf(
							"\nNo hay resultados que informar, usted no realizo ninguna operacion.\n");
				}
				break;
			case 5:
				if (flagKilometrosCargados == 0 && flagPrecioAerolineas == 0
						&& flagPrecioLatam == 0) {
					kilometrosIngresados = 7090;
					precioAerolineas = 162965;
					precioLatam = 159339;

					//Precios Aerolineas
					DivisionNumeros(kilometrosIngresados, precioAerolineas,
							&precioUnitarioAerolineas);
					precioConDescuentoAerolineas = CalcularPorcentaje(
							precioAerolineas, DESCUENTO, 0);
					precioConInteresAerolineas = CalcularPorcentaje(
							precioAerolineas, INTERES, 1);
					resultadoBitcoinAerolineas = CalcularBTC(precioAerolineas,
							BTC);
					//Precios Latam
					DivisionNumeros(kilometrosIngresados, precioLatam,
							&precioUnitarioLatam);
					precioConDescuentoLatam = CalcularPorcentaje(precioLatam,
							DESCUENTO, 0);
					precioConInteresLatam = CalcularPorcentaje(precioLatam,
							INTERES, 1);
					resultadoBitcoinLatam = CalcularBTC(precioLatam, BTC);

					//Diferencia de precios
					diferenciaDePrecios = RestarNumeros(precioLatam,
							precioAerolineas);

					printf("\nKilometros ingresados: %.2f km"
							"\n\nLatam:"
							"\na) Precio con tarjeta de d�bito: $ %.2f"
							"\nb) Precio con tarjeta de cr�dito: $ %.2f"
							"\nc) Precio pagando con bitcoin: BTC %f"
							"\nd) Precio unitario: $ %.2f"

							"\n\nAerol�neas:"
							"\na) Precio con tarjeta de d�bito: $ %.2f"
							"\nb) Precio con tarjeta de cr�dito: $ %.2f"
							"\nc) Precio pagando con bitcoin: BTC %f"
							"\nd) Precio unitario: $ %.2f"

							"\n\nLa diferencia de precio es: $ %.2f\n",
							kilometrosIngresados, precioConDescuentoAerolineas,
							precioConInteresAerolineas,
							resultadoBitcoinAerolineas,
							precioUnitarioAerolineas, precioConDescuentoLatam,
							precioConInteresLatam, resultadoBitcoinLatam,
							precioUnitarioLatam, diferenciaDePrecios);
				}

				break;
			}
		} else {
			opcion = 6;
			printf(
					"\nEl programa finalizo debido a que no se ingreso ninguna opcion valida\n");
		}
	} while (opcion != 6);
	printf("\nUsted salio del programa :(  \n�Que tenga un buen dia!");

	return EXIT_SUCCESS;
}
