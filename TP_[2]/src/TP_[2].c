#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "LibrarieInt.h"

#define LEN 10
#define REIN 5


int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcionCorrecta;
	int idPasajero;
	Passengers passager[LEN];
	int existenPasajeros;

	idPasajero = 0;
	initPassengers(passager, LEN);
	existenPasajeros = 0;

	do {
		opcionCorrecta = GetNumberWithRange("***********************\n"
							"BIENVENIDO\n\n"
							"1.Alta de Pasajero\n"
							"2.Modificar Pasajero\n"
							"3.Baja .de Pasajero\n"
							"4.Informar\n"
							"5.Carga forzada\n"
							"6.Salir\n"
							"***********************\n"
							"Ingrese una opcion: ",

							"\n***********************\n"
							"BIENVENIDO\n\n"
							"1.Alta de Pasajero\n"
							"2.Modificar Pasajero\n"
							"3.Baja de Pasajero\n"
							"4.Informar\n"
							"5.Carga forzada\n"
							"6.Salir\n"
							"***********************\n"
							"\nOpcion invalida, vuelva a intentarlo.\n\n", REIN, 1, 5, &opcion);
							printf("\n");
				if (opcionCorrecta == 1) {
					switch (opcion) {
					case 1:
						existenPasajeros = requestPassengers(passager, LEN, &idPasajero, REIN);
						break;
					case 2:
						if(existenPasajeros == 1){
							modifyPassengerData(passager, LEN, REIN);
						}else{
							printf("NO EXISTEN DATOS CARGADOS. \n\n");
						}
						break;
					case 3:
						if(existenPasajeros == 1){
							passengerDischarge(passager, LEN, REIN);
						}else{
							printf("NO EXISTEN DATOS CARGADOS. \n\n");
						}
						break;
					case 4:
						if(existenPasajeros == 1){
							printSubMenuReport(passager, LEN, 3);
						}else{
							printf("NO EXISTEN DATOS CARGADOS. \n\n");
						}
						break;
					case 5:
						existenPasajeros = cargaForzada(passager, LEN, &idPasajero);
						printPassenger(passager, LEN);
						break;
					}
				}else{
					opcion = 6;
					printf("\nEl programa finalizo debido a que no se ingreso ninguna opcion valida.\n");
				}

			} while (opcion != 6);

	return EXIT_SUCCESS;
}
