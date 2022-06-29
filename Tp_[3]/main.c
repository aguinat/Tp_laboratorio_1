#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "LibrarieInt.h"

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
    int existenPasajerosCargados;
    int pasajeroCargadoManualmente;
    int datosGuardados;

    datosGuardados = 0;
    existenPasajerosCargados = 0;
    pasajeroCargadoManualmente = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    do {
    		opcionCorrecta = GetNumberWithRange("\n***********************\n"
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
    							"\nOpcion invalida, vuelva a intentarlo: ", REIN, 1, 10, &opcion);
    							printf("\n");
    				if (opcionCorrecta == 1) {
    					switch (opcion) {
    					case 1:
    						if(existenPasajerosCargados == 0){
        						existenPasajerosCargados = controller_loadFromText("data.csv",listaPasajeros);
    						}else{
    							printf("Existen pasajeros cargados");
    						}
    						break;
    					case 2:
    						if(existenPasajerosCargados == 0){
    							existenPasajerosCargados = controller_loadFromBinary("data.bin", listaPasajeros);
    						}else{
    							printf("Existen pasajeros cargados");
    						}
    						break;
    					case 3:
    						pasajeroCargadoManualmente = controller_addPassenger(listaPasajeros);
    						break;
    					case 4:
    						if(existenPasajerosCargados == 1 || pasajeroCargadoManualmente == 1){
    							controller_editPassenger(listaPasajeros);
    						}else{
    							printf("No existen pasajeros para editar\n\n");
    						}
    						break;
    					case 5:
    						if(existenPasajerosCargados == 1 || pasajeroCargadoManualmente == 1){
    							controller_removePassenger(listaPasajeros);
    						}else{
    							printf("No existen pasajeros para eliminar\n\n");
    						}

    						break;
    					case 6:
    						if(existenPasajerosCargados == 1 || pasajeroCargadoManualmente == 1){
    							controller_ListPassenger(listaPasajeros);
    						}else{
    							printf("No existen pasajeros para listar\n\n");
    						}
    						break;
    					case 7:
    						if(existenPasajerosCargados == 1 || pasajeroCargadoManualmente == 1){
    							controller_sortPassenger(listaPasajeros);
    						}else{
    							printf("No existen pasajeros para ordenar\n\n");
    						}
    						break;
    					case 8:
    						controller_saveMaxIdAsText(listaPasajeros);
    						controller_saveAsText("data.csv", listaPasajeros);
    						datosGuardados = 1;
    						break;
    					case 9:
    						controller_saveMaxIdAsText(listaPasajeros);
    						controller_saveAsBinary("data.bin", listaPasajeros);
    						datosGuardados = 1;
    					    break;
    					case 10:
    						if(datosGuardados == 0){
    							printf("Los datos no fueron guardados.\n");
    							opcion = 0;
    						}
    						break;
    					}


    				}else{
    					opcion = 10;
    					printf("\nEl programa finalizo debido a que no se ingreso ninguna opcion valida\n");
    				}

    			} while (opcion != 10);

    return 0;
}

