#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include "DataLoading.h"
#define MAX_TYPEPASSENGER 3
#define MAX_STATUSFLIGHT 4
#define LENPALABRA 50
#define LEN_CODE 7
#define REIN 3
#define LINEA_ARCHIVO 7
#define MAX_PRICE 50000

int Passenger_setId(Passenger* this,int id){
	int setCorrecto;

	setCorrecto = 0;
	if (this != NULL && id>= 0) {
		this->id = id;
		setCorrecto = 1;
	}
	return setCorrecto;
}
int Passenger_getId(Passenger* this,int* id){
	int getCorrecto;

	getCorrecto = 0;
	if(this!=NULL && id!=NULL){
		*id = this->id;
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setNombre(Passenger* this,char* nombre){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		setCorrecto = 1;
	}

	return setCorrecto;
}
int Passenger_getNombre(Passenger* this,char* nombre){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre,this->nombre);
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setApellido(Passenger* this,char* apellido){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && apellido != NULL){
		strcpy(this->apellido, apellido);
		setCorrecto = 1;
	}

	return setCorrecto;
}
int Passenger_getApellido(Passenger* this,char* apellido){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo, codigoVuelo);
		setCorrecto = 1;
	}

	return setCorrecto;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && ValidarRango(tipoPasajero, 0, MAX_TYPEPASSENGER) == 1){
		this->tipoPasajero = tipoPasajero;
		setCorrecto = 1;
	}else{
		printf("ERROR. No fue posible guardar el tipo de pasajero.\n");
	}

	return setCorrecto;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && tipoPasajero != NULL) {
		*tipoPasajero = this->tipoPasajero;
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setPrecio(Passenger* this, float precio){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && ValidarRangoFloat(precio, 0, MAX_PRICE) == 1){
		this->precio = precio;
		setCorrecto = 1;
	}else{
		printf("ERROR. No fue posible guardar el precio.\n");
	}

	return setCorrecto;
}
int Passenger_getPrecio(Passenger* this,float* precio){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo){
	int setCorrecto;

	setCorrecto = 0;
	if (this != NULL && ValidarRango(estadoVuelo, 1, MAX_STATUSFLIGHT) == 1) {
		this->estadoVuelo = estadoVuelo;
		setCorrecto = 1;
	} else {
		printf("ERROR. No fue posible guardar el estado del vuelo.\n");
	}

	return setCorrecto;
}
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && estadoVuelo != NULL) {
		*estadoVuelo = this->estadoVuelo;
		getCorrecto = 1;
	}

	return getCorrecto;
}

void Passenger_delete(Passenger* this){
	if(this != NULL){
		free(this);
	}
}

Passenger* Passenger_new(){
	Passenger* auxPassenger = NULL;
	auxPassenger = (Passenger*)malloc(sizeof(Passenger));

	return auxPassenger;
}

Passenger* Passenger_newParametros(int* idStr,char* nombreStr,int* tipoPasajero, char* apellidoStr, float* precio, char* codigoVuelo, int* estadoVuelo){
	Passenger* auxPassenger = NULL;
	auxPassenger = Passenger_new();

	if(auxPassenger !=NULL){
		if(idStr != NULL && nombreStr != NULL && tipoPasajero != NULL && apellidoStr != NULL && precio != NULL && codigoVuelo != NULL && estadoVuelo != NULL){
			Passenger_setId(auxPassenger, *idStr);
			Passenger_setNombre(auxPassenger, nombreStr);
			Passenger_setApellido(auxPassenger, apellidoStr);
			Passenger_setCodigoVuelo(auxPassenger, codigoVuelo);
			Passenger_setPrecio(auxPassenger, *precio);
			Passenger_setTipoPasajero(auxPassenger, *tipoPasajero);
			Passenger_setEstadoVuelo(auxPassenger, *estadoVuelo);
		}else{
			Passenger_delete(auxPassenger);
			auxPassenger = NULL;
		}

	}

	return auxPassenger;
}

Passenger* Passenger_getFromUser(int* cargaCorrecta, int* id){
	int cargaCompleta;
	int datoIncorrecto;
	int confirma;
	char auxNombre[LENPALABRA];
	char auxApellido[LENPALABRA];
	char auxCodigo[LEN_CODE];
	float auxPrecio;
	int auxTipoPasajero;
	int auxEstadoVuelo;
	Passenger* auxPassenger = NULL;
	*id = *id+1;
	cargaCompleta = 0;
	datoIncorrecto = 0;

	if (cargaCorrecta != NULL) {
		do {
			if (getPalabra(auxNombre, "Ingrese su nombre: \n", "ERROR. Nombre invalido.\n") == 0) {
				datoIncorrecto = 1;
			}
			if (getPalabra(auxApellido, "Ingrese su apellido: \n","ERROR. Apellido invalido.\n") == 0) {
				datoIncorrecto = 1;
			}
			if (getCodigoVuelo(auxCodigo, LEN_CODE) == 0) {
				datoIncorrecto = 1;
			}
			if (getPrice(&auxPrecio) == 0) {
				datoIncorrecto = 1;
			}
			if (getPassegerType(&auxTipoPasajero) == 0) {
				datoIncorrecto = 1;
			}
			if (getStatusFlight(&auxEstadoVuelo) == 0) {
				datoIncorrecto = 1;
			}
			if (datoIncorrecto != 1) {
				ConfirmarContinuar("Confirme la carga del pasajero (SI/NO): ","Ingrese una respuesta valida", &confirma, REIN);
				if (confirma == 1) {
					auxPassenger = Passenger_newParametros(id, auxNombre, &auxTipoPasajero, auxApellido, &auxPrecio, auxCodigo, &auxEstadoVuelo);
					if(auxPassenger != NULL){
						cargaCompleta = 1;
					}
				}
			} else {
				printf("\nUno o mas datos no fueron cargados correctamente.");
				ConfirmarContinuar("\n¿Quiere volver a reingresar los datos?: (SI/NO)", "\nIngrese una respuesta valida. ", &confirma, REIN);
			}
		} while (confirma == 1 && cargaCompleta == 0);
	}

	*cargaCorrecta = cargaCompleta;
	return auxPassenger;
}

int GetLastId_LinkedList(LinkedList* pArrayListPassenger){
	int id;
	int maxId;
	int largoDeLista;
	Passenger *auxPassenger = NULL;
	maxId = 0;

	if( pArrayListPassenger != NULL){
		largoDeLista = ll_len(pArrayListPassenger);
		if (largoDeLista > 0) {
			for (int i = 0; i < largoDeLista; i++) {
				auxPassenger = ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &id);
				if(id>maxId){
					maxId = id;
				}
			}
		}
	}

	return maxId;
}

void MostrarUnPasajero(Passenger* this){
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	int estadoVuelo;
	char estadoVuelo_Str[50];
	int estadoVueloValido;
	int tipoPasajero;
	char tipoPasajero_Str[50];
	int tipoPasajeroValido;

	if(this!=NULL){
		Passenger_getId(this, &id);
		Passenger_getNombre(this, nombre);
		Passenger_getApellido(this, apellido);
		Passenger_getCodigoVuelo(this, codigoVuelo);
		Passenger_getPrecio(this, &precio);
		Passenger_getTipoPasajero(this, &tipoPasajero);
		Passenger_getEstadoVuelo(this, &estadoVuelo);

		if(tipoPasajero>0 && estadoVuelo>0){
			estadoVueloValido = getStr_StatusFlight(estadoVuelo_Str, estadoVuelo);
			tipoPasajeroValido = getStr_PassegerType(tipoPasajero_Str, tipoPasajero);
			if(estadoVueloValido == 1 && tipoPasajeroValido == 1){
				printf("%-5d %-15s %-20s %-20s %-15.2f %-20s %-20s\n", id, nombre, apellido, codigoVuelo, precio, tipoPasajero_Str, estadoVuelo_Str);
			}
		}
	}

}

int ModificarDatosPasajero(Passenger* this, int id){
	int opcionCorrecta;
	int opcion;
	int datoIncorrecto;
	int confirma;
	int cargaCompleta;
	char auxNombre[50];
	char auxApellido[50];
	char auxCodigo[50];
	float auxPrecio;
	int auxTipoPasajero;
	int auxEstadoVuelo;

	datoIncorrecto = 0;
	do{
		opcionCorrecta = GetNumberWithRange(
				"\n1: Nombre"
				"\n2: Apellido"
				"\n3: Precio"
				"\n4: Tipo pasajero"
				"\n5: Codigo de Vuelo"
				"\n6: Estado de vuelo"
				"\n7: Salir"
				"\nIngrese lo que desea modificar: ", "\n\nOpcion invalida\n",REIN, 1, 7, &opcion);
		if(opcionCorrecta==1){
			switch (opcion) {
			case 1:
				if (getPalabra(auxNombre, "\nIngrese el nombre del pasajero: ","\nERROR. Nombre invalido.\n") == 0) {
					printf("Error. No se pudo guardar correctamente el nombre del pasajero.\n");
					datoIncorrecto = 1;
				}
				break;
			case 2:
				if (getPalabra(auxApellido, "Ingrese el apellido del pasajero: \n","ERROR. Apellido invalido.\n")== 0) {
					printf("Error.No se pudo guardar correctamente el apellido del pasajero.\n");
					datoIncorrecto = 1;
				}
				break;
			case 3:
				if(getPrice(&auxPrecio) == 0){
					datoIncorrecto = 1;
				}
				break;
			case 4:
				if(getPassegerType(&auxTipoPasajero) == 0){
					datoIncorrecto = 1;
				}
				break;
			case 5:
				if(getPrice(&auxPrecio) == 0){
					datoIncorrecto = 1;
				}
				break;
			case 6:
				if(getStatusFlight(&auxEstadoVuelo) == 0){
					datoIncorrecto = 1;
				}
				break;
			}
			ConfirmarContinuar("¿Desea modificar otro dato? ", "\nError. Vuelva a intentarlo", &confirma, REIN);
			if (confirma==0  && datoIncorrecto != 1) {
				this = Passenger_newParametros(&id, auxNombre, &auxTipoPasajero, auxApellido, &auxPrecio, auxCodigo, &auxEstadoVuelo);
				if (this != NULL) {
					cargaCompleta = 1;
					printf("Datos modificados correctamente.\n");
				}
			}else{
				if(datoIncorrecto == 1){
					printf("\nUno o mas datos no fueron cargados correctamente.");
					ConfirmarContinuar("\n¿Quiere volver a reingresar los datos?: (SI/NO)", "\nIngrese una respuesta valida. ", &confirma, REIN);
				}
			}
		}else{
			opcion = 7;
		}
	}while(opcion != 7 && confirma == 1) ;

	return cargaCompleta;
}


int GetIndexPassenger_ById(LinkedList* pArrayListPassenger, int* index, int id){
	int largoDeLista;
	int idExiste;
	int idAux;
	Passenger *auxPassenger = NULL;

	idExiste = 0;
		largoDeLista = ll_len(pArrayListPassenger);
		if (largoDeLista > 0) {
			for (int i = 0; i < largoDeLista; i++) {
				auxPassenger = ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &idAux);
				if(id==idAux){
					*index = i;
					idExiste = 1;
				}
			}
		}

	return idExiste;
}
