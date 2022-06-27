#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "LibrarieInt.h"


#define LEN 7
#define REIN 3
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{	setbuf(stdout,NULL);
    int opcion;
    int opcionCorrecta;
    //int idPasajero;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do {
    		opcionCorrecta = GetNumberWithRange("***********************\n"
    							"BIENVENIDO\n\n"
    							"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    							"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
    							"3. Alta de pasajero\n"
    							"4. Modificar datos de pasajero\n"
    							"5. Baja de pasajero\n"
    							"6. Listar pasajeros\n"
    							"7. Ordenar pasajeros\n"
    							"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    							"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
    							"10. Salir\n"
    							"***********************\n"
    							"Ingrese una opcion: ",

    							"\n***********************\n"
    							"BIENVENIDO\n\n"
    							"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    							"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
    							"3. Alta de pasajero\n"
    							"4. Modificar datos de pasajero\n"
    							"5. Baja de pasajero\n"
    							"6. Listar pasajeros\n"
								"7. Ordenar pasajeros\n"
								"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
								"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
								"10. Salir\n"
    							"***********************\n"
    							"\nOpcion invalida, vuelva a intentarlo: ", REIN, 1, 9, &opcion);
    							printf("\n");
    				if (opcionCorrecta == 1) {
    					switch (opcion) {
    					case 1:
    						controller_loadFromText("data.csv",listaPasajeros);
    						break;
    					case 2:
    						controller_loadFromBinary("data.bin", listaPasajeros);
    						break;
    					case 3:
    						controller_addPassenger(listaPasajeros);
    						break;
    					case 4:
    						controller_editPassenger(listaPasajeros);
    						break;
    					case 5:

    						break;
    					case 6:
    						controller_ListPassenger(listaPasajeros);
    						break;
    					case 7:

    						break;
    					case 8:
    						break;
    					case 9:
    						controller_saveAsBinary("data.bin", listaPasajeros);
    					    break;
    					}
    				}else{
    					opcion = 10;
    					printf("\nEl programa finalizo debido a que no se ingreso ninguna opcion valida\n");
    				}

    			} while (opcion != 10);


    return 0;
}

