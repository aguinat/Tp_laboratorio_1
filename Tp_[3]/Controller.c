#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){

	if(path!=NULL && pArrayListPassenger !=NULL ){
		FILE *pArchivo = fopen(path, "r");
		parser_PassengerFromText(pArchivo, pArrayListPassenger);
	}

	return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{	int cargaBinario;

	cargaBinario = 0;
	if(path != NULL && pArrayListPassenger!=NULL){
		FILE *pFile = fopen(path, "rb");
		if(pFile!=NULL){
			parser_PassengerFromBinary(pFile, pArrayListPassenger);
			cargaBinario = 1;
		}else{
			printf("Error al intentar abrir el archivo Binario.\n\n");
		}

	}
    return cargaBinario;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{	int cargaCorrecta;
	int ultimoIdCargado;
	Passenger *newPassenger = NULL;

	cargaCorrecta = 0;
	ultimoIdCargado = GetLastId_LinkedList(pArrayListPassenger);

	if(pArrayListPassenger != NULL && ultimoIdCargado>0){
		newPassenger = Passenger_getFromUser(&cargaCorrecta, &ultimoIdCargado);
		if(newPassenger != NULL){
			ll_add(pArrayListPassenger, newPassenger);
			cargaCorrecta = 1;
			printf("Carga completa del nuevo pasajero\n");
		}
	}else{
		printf("ERROR. No se pudo realizar la carga.\n");
	}

	return cargaCorrecta;
}


/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{	int lenListPassenger;
	int registrosMostrados;
	int continuar;
	Passenger *passenger = NULL;
	registrosMostrados = 0;

	if(pArrayListPassenger!= NULL){
		lenListPassenger = ll_len(pArrayListPassenger);
		if(lenListPassenger>0){
			printf("\n\nDatos del pasajero:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","ID", "Nombre", "Apellido", "Precio", "Tipo Pasajero","Codigo Vuelo", "Estado Vuelo");
			for(int i = 0; i< lenListPassenger; i++){
				passenger = ll_get(pArrayListPassenger, i);
				if(passenger!= NULL){
					registrosMostrados++;
					MostrarUnPasajero(passenger);
					if(registrosMostrados==100){
						ConfirmarContinuar("Continuar... ?'SI'/'NO': ", "ERROR. Respuesta invalida", &continuar, 3);
						if(continuar == 1){
							registrosMostrados = 0;
						}else{
							break;
						}
					}
				}

			}
		}

	}


    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{	int idPassenger;
	int numeroValido;
	Passenger *auxPassenger = NULL;
	int index;
	int idExiste;

	controller_ListPassenger(pArrayListPassenger);
	numeroValido = GetIntNumber("\nIndique el id del pasajero que desea modificar los datos: ", "ERROR. Id invalido.", 3, &idPassenger);
	if (numeroValido == 1){
		idExiste = GetIndexPassenger_ById(pArrayListPassenger, &index,idPassenger);
		if(idExiste == 1){
			auxPassenger = ll_get(pArrayListPassenger, index);
			if(auxPassenger != NULL){
				if(ModificarDatosPasajero(auxPassenger, idPassenger)== 1){
					ll_set(pArrayListPassenger, index, auxPassenger);
				}
			}
		}else{
			printf("ERROR. El id indicado no existe.");
		}
	}

    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{	int cargaCorrecta;
	Passenger* auxPassenger = NULL;
	int largoDeLista;
	int i;

	cargaCorrecta = 1;
	largoDeLista = ll_len(pArrayListPassenger);

	if (path != NULL && pArrayListPassenger != NULL && largoDeLista > 0) {
		printf("Guardado archivo Binario. \n");

		FILE * pBin = fopen(path, "wb");

		if(pBin != NULL){
			for (i = 0; i < largoDeLista; i++){
				auxPassenger = ll_get(pArrayListPassenger, i);
				if(auxPassenger != NULL){
					fwrite(auxPassenger,sizeof(Passenger),1,pBin);
				}else{
					cargaCorrecta = 0;
				}
			}
			fclose(pBin);
		}else{
			cargaCorrecta = 0;
		}
	}
    return cargaCorrecta;
}

