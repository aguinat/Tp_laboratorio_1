#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "LibrarieInt.h"

#define LEN 7
#define REIN 3


int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcionCorrecta;
	int idPasajero;
	Passengers passager[LEN];

	idPasajero = 0;
	initPassengers(passager, LEN);

	//Passengers passager[LEN]={{1,"Nathy","Aguila",12.2, "12AS" ,1, 1, 0},{2,"Andrea","Luizaga",256.2, "BJ189AS" ,1, 1, 0},{3,"Sabrina","Soto",12897.2, "182AS" ,3, 3, 0}, {5,"Lorena","Abelino",12.2, "B3526AS" ,2, 3, 0},{7
		//,"Mariano","Casas",256.2, "CD189AS" ,1, 1, 0},{6,"Brian","Solano",12897.2, "182AS" ,1, 3, 0}};

	do {
		opcionCorrecta = PedirNumConRango("***********************\n"
							"BIENVENIDO\n\n"
							"1.Alta de Pasajero\n"
							"2.Modificar Pasajero\n"
							"3.Baja de Pasajero\n"
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
							"\nOpcion invalida, vuelva a intentarlo: ", REIN, 1, 5, &opcion);
							printf("\n");
				if (opcionCorrecta == 1) {
					switch (opcion) {
					case 1:
						requestPassengers(passager, LEN, &idPasajero, REIN);
						break;
					case 2:
						modifyPassengerData(passager, LEN, REIN);
						break;
					case 3:
						passengerDischarge(passager, LEN, REIN);
						break;
					case 4:
						printSubMenuReport(passager, LEN, REIN);
						break;
					case 5:
						cargaForzada(passager, LEN, &idPasajero);
						printPassenger(passager, LEN);
						break;
					}
				}else{
					opcion = 6;
					printf("\nEl programa finalizo debido a que no se ingreso ninguna opcion valida\n");
				}

			} while (opcion != 6);

	return EXIT_SUCCESS;
}
