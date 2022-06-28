#include "ArrayPassenger.h"
#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMCADENA 50
#define REIN 3
#define BUSSINES 1
#define ENCONOMY 2
#define VIP 3
#define ACTIVO 1
#define CANCELADO 2
#define REPROGRAMADO 3

int addPaseenger(Passengers list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[], int statusFlight){
	int index;
	int validacion;

	validacion = 0;

	if(list != NULL && name != NULL && lastName != NULL && flyCode != NULL){
		index = searchFreeIndex(list, len);
		if(index != -1){
			strcpy(list[index].name, name);
			strcpy(list[index].lastName, lastName);
			strcpy(list[index].flyCode, flyCode);
			list[index].price = price;
			list[index].typePassenger = typePassenger;
			list[index].statusFlight = statusFlight;
			list[index].id = id;
			list[index].isEmpty = 0;

			validacion = 1;
		}else{
			printf("\nERROR.No hay lugar para cargar mas pasajeros\n");
		}
	}
	return validacion;
}

int requestPassengers(Passengers list[], int len, int* id, int reintentos){
	int idAux;
	int validacion;
	int confirma;
	int datosCargados;
	Passengers auxPassengers;

	datosCargados = 1;
	validacion = 0;

	if(list != NULL && len > 0){
		do{
			idAux = *id;
			if(GetLetters("Ingrese el nombre del pasajero: ", "\nERROR. NOMBRE INVALIDO.\n", auxPassengers.name, sizeof(auxPassengers.name), reintentos) == 0){
				printf("Error. No se pudo guardar correctamente el nombre del pasajero.\n");
				datosCargados = 0;
			}
			if(datosCargados!= 0 && GetLetters("Ingrese el apellido del pasajero: ", "\nERROR. APELLIDO INVALIDO.\n", auxPassengers.lastName, sizeof(auxPassengers.lastName), reintentos) == 0){
				printf("Error. No se pudo guardar correctamente el Apellido del pasajero.\n");
				datosCargados = 0;
			}
			if(datosCargados!= 0 && GetNumberWithRange("Ingrese el tipo de pasajero, (1 - Bussines, 2 - Economy, 3 - VIP): ", "\nERROR. TIPO INGRESO INVALIDO.\n ", reintentos,1,3, &auxPassengers.typePassenger) == 0){
				printf("Error. No se pudo guardar correctamente el tipo correspondiente al pasajero.\n");
				datosCargados = 0;
			}
			if(datosCargados!= 0 && GetFloatNumberWithRange("Ingrese el precio del vuelo: ", "\nERROR. PRECIO INVALIDO.\n ", reintentos,10,50000 ,&auxPassengers.price) == 0){
				printf("Error. No se pudo guardar correctamente el precio.\n");
				datosCargados = 0;
			}
			if(datosCargados!= 0 && GetStringAlfaNum("Ingrese el codigo de vuelo del pasajero: ", "\nERROR. CODIGO INVALIDO.\n", auxPassengers.flyCode, sizeof(auxPassengers.flyCode), reintentos) == 0){
				printf("Error. No se pudo guardar correctamente el codigo de vuelo del pasajero.\n");
				datosCargados = 0;
			}
			if(datosCargados!= 0 && GetNumberWithRange("Ingrese el estado del vuelo, (1-ACTIVO, 2- CANCELADO, 3- REPOGRAMADO): ", "\nError. Estado invalido.\n ", reintentos,1,3, &auxPassengers.statusFlight) == 0){
				printf("Error. No se pudo guardar correctamente el estado del vuelo.\n");
				datosCargados = 0;
			}

			if(datosCargados != 0){
				auxPassengers.id = 0;
				printf("\nEl id se generara una vez que confirme la carga del pasajero.");
				printf("\nPasajero a cargar:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
				printSinglePassenger(auxPassengers);
				ConfirmarContinuar("Confirme la carga del pasajero (SI/NO): ", "Ingrese una respuesta valida", &confirma, reintentos);
				if(confirma==1){
					auxPassengers.id = idAux+1;
					if(addPaseenger(list, len, auxPassengers.id, auxPassengers.name, auxPassengers.lastName, auxPassengers.price, auxPassengers.typePassenger, auxPassengers.flyCode, auxPassengers.statusFlight)==1){
						printf("\nSe Realizo la carga correctamente.\n");
						*id = auxPassengers.id;
						validacion = 1;
					}else{
						printf("ERROR AL CARGAR PASAJERO.\n");
					}
				}
			}
			else {
				printf("\nUno o mas datos no fueron cargados correctamente.");
				ConfirmarContinuar("\n¿Quiere volver a reingresar los datos?: (SI/NO) ","\nIngrese una respuesta valida. ", &confirma, REIN);
				if(confirma == 1){
					datosCargados = 1;
				}
			}
		} while (confirma == 1 && validacion == 0);
	}
	return validacion;
}

int initPassengers(Passengers list[], int len){
	int validacion;

	validacion = 0;

	if(list != NULL && len>0){
		for(int i = 0;i < len; i++)
		    {
		    	list[i].isEmpty = 1;
		        list[i].id = 0;
		    }
		validacion = 1;
	}


    return validacion;

}

int searchFreeIndex(Passengers list[], int len){
	int i;
	int index;

	  index = -1;
	  if(list != NULL && len > 0){
		  for (i = 0; i < len; i++){
		  		  if (list[i].isEmpty == 1){
		  			  index = i;
		  		  break;
		  		  }
		  	  }
	  }

	  return index;
}

void printSinglePassenger(Passengers list){
	if(list.typePassenger == 1){
		switch(list.statusFlight){
		case 1:
			printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"Bussines", list.price, "Activo", list.flyCode);
			break;
		case 2:
			printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"Bussines", list.price, "Cancelado", list.flyCode);
			break;
		case 3:
			printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"Bussines", list.price, "Reprogramado", list.flyCode);
			break;
		}
	}
	if(list.typePassenger == 2){
		switch(list.statusFlight){
			case 1:
				printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"Economy", list.price, "Activo", list.flyCode);
			break;
			case 2:
				printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"Economy", list.price, "Cancelado", list.flyCode);
			break;
			case 3:
				printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"Economy", list.price, "Reprogramado", list.flyCode);
			break;
		}
	}
	if(list.typePassenger == 3){
		switch(list.statusFlight){
		case 1:
			printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"VIP", list.price, "Activo", list.flyCode);
			break;
		case 2:
			printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"VIP", list.price, "Cancelado", list.flyCode);
			break;
		case 3:
			printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"VIP", list.price, "Reprogramado", list.flyCode);
			break;
	}
	}
}

int printPassenger(Passengers list[], int len){
	int i;
	int flagDatosVacios;
	int validacion;
	validacion = 0;

	if(list!=NULL && len> 0){
		flagDatosVacios = 1;
			printf("\nDatos de los pasajeros:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
			for (i = 0; i < len; i++) {
				if (list[i].isEmpty == 0 && list[i].id !=0) {
					printSinglePassenger(list[i]);
					flagDatosVacios = 0;
					validacion = 1;
				}
			}
			if (flagDatosVacios == 1) {
				puts("No se encontraron datos.\n");
			}
	}

	return validacion;

}

int modifyPassengerData(Passengers list[], int len, int reintentos){
  int idPasajero;
  int index;
  int opcion;
  int opcionCorrecta;
  int continuar;
  int datosCambiados;
  datosCambiados = 0;
  int validacionCorrecta;

  if(list!=NULL && len>0){
	  printPassenger(list, len);
	  validacionCorrecta = GetIntNumber("Ingrese el ID del pasajero a modificar: ","\nError. ID invalido.", reintentos, &idPasajero);
	  if(validacionCorrecta == 1){
	  	  if (findPassengerById(list, len, idPasajero, &index) == 1){
	  		do{
	  			opcionCorrecta = GetNumberWithRange("\n1: Nombre"
	  				  			  				  "\n2: Apellido"
	  				  			  				  "\n3: Precio"
	  				  			  				  "\n4: Tipo de Pasajero"
	  				  			  				  "\n5: Codigo de Vuelo"
	  				  							  "\n6: Salir"
	  				  							  "\nIngrese lo que desea modificar: ", "\n\nOPCION INVALIDA.\n\n", reintentos,1,5, &opcion);
	  			if(opcionCorrecta == 1){
	  				switch(opcion){
	  					  		 case 1:
	  					  			 if(GetLetters("\nIngrese el nombre del pasajero: ", "\nError. Nombre invalido.", list[index].name, sizeof(list[index].name), reintentos) == 0){
	  					  				printf("Error.No se pudo guardar correctamente el nombre del pasajero.\n");
	  					  			 }
	  					  			 break;
	  					  		 case 2:
	  					  			 GetLetters("\nIngrese el apellido del pasajero: ", "\nError. Apellido invalido.", list[index].lastName, sizeof(list[index].lastName), reintentos);
	  					  			 break;
	  					  		 case 3:
	  					  			GetFloatNumberWithRange("\nIngrese el precio: ", "\nError. Precio invalido.", reintentos,10,50000, &list[index].price);
	  					  			break;
	  					  		 case 4:
	  					  			 GetIntNumber("Ingrese el tipo de pasajero: (1 - Bussines, 2 - Economy, 3 - VIP)", "\nError. Tipo ingreso invalido.", reintentos, &list[index].typePassenger);
	  					  			 break;
	  					  		 case 5:
	  					  			GetStringAlfaNum("Ingrese el codigo de vuelo del pasajero: ", "\nError. Codigo invalido.", list[index].flyCode, sizeof(list[index].flyCode), reintentos);
	  					  			break;
	  					  		 }
	  				ConfirmarContinuar("¿Desea modificar otro dato?(SI/NO): ", "\nError. Vuelva a intentarlo", &continuar, reintentos);
					if (continuar == 0) {
						datosCambiados = 1;
						printf("\nPASAJERO MODIFICADO CORRECTAMENTE.\n");
						printf("\nDatos de los pasajeros:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
						printSinglePassenger(list[index]);
					}
	  			}else{
	  				printf("\nNO SE SELECCIONO NINGUNA OPCION CORRECTA.\n\n");
	  				printf("\n***SE REGRESA AL MENU PRINCIPAL****\n\n");
	  				opcion = 6;
	  			}
	  		}while(opcion != 6 && datosCambiados == 0 );
	  	  }else{
	  		  printf("\nEL ID INGRESADO NO SE ENCUENTRA EN LA BASE.\n\n");
	  		  printf("\n***SE REGRESA AL MENU PRINCIPAL****\n\n");
	  	  }
	  }
  }
  return datosCambiados;
}

int findPassengerById(Passengers list[], int len, int id, int* index){
	int i;
	int clienteExiste;

	clienteExiste = 0;

	for(i=0; i<len; i++)	{
		if(list[i].isEmpty==0 && list[i].id== id){
			clienteExiste = 1;
			*index = i;
			break;
		}
	}
	return clienteExiste;
}

int removePassenger(Passengers list[], int len, int id, int index){
	int pasajeroEliminado;
	pasajeroEliminado = 0;

	if(list != NULL && len > 0 ){
		if(list[index].id == id){
			list[index].isEmpty = 1;
			pasajeroEliminado = 1;
		}

	}
	return pasajeroEliminado;
}

int passengerDischarge(Passengers list[], int len, int reintentos){
	int index;
	int idPasajero;
	int validacionCorrecta;
	int confirmarBaja;
	if(list != NULL && len > 0 ){
		printPassenger(list, len);
		validacionCorrecta = GetIntNumber("Ingrese el ID del pasajero que quiere dar de baja: ", "\nError. ID invalido\n", reintentos, &idPasajero);
		if(validacionCorrecta == 1 && findPassengerById(list, len, idPasajero, &index) == 1){
			printf("\nPasajero que se dara de baja:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
			printSinglePassenger(list[index]);
	  		ConfirmarContinuar("\n¿Confirma la baja del pasajero? (SI/NO): ", "\nError. Vuelva a intentarlo", &confirmarBaja, reintentos);
			if(confirmarBaja == 1){
			  removePassenger(list, len, idPasajero, index);
			  printf("\nPasajero dado de baja correctamente");

			}
		}
	}
	return validacionCorrecta;

}

int sortPassengers(Passengers list[], int len, int order){
	int ordenarAcedenteDecedente;
	int lenAux;
	int i;
	int estaOrdenado;

	lenAux=len;
	Passengers auxPassenger;

	if(list!=NULL && len>0){
		if(order==1){
			ordenarAcedenteDecedente =-1;
		}
		else{
			ordenarAcedenteDecedente = 1;
		}
		do{
			estaOrdenado = 1;
			for(i=0;i<lenAux;i++){
				if(list[i].isEmpty==0 && list[i+1].isEmpty==0){
						if(stricmp(list[i].lastName,list[i+1].lastName)==0){
							if(list[i].typePassenger>list[i+1].typePassenger){
								auxPassenger=list[i];
								list[i]=list[i+1];
								list[i+1]=auxPassenger;
								estaOrdenado = 0;
							}
						}
						else{
							if(stricmp(list[i].lastName,list[i+1].lastName)== ordenarAcedenteDecedente){
								auxPassenger=list[i];
								list[i]=list[i+1];
								list[i+1]=auxPassenger;
								estaOrdenado = 0;
							}
						}
					}
				}
			}while(estaOrdenado == 0 );
		}
	if(estaOrdenado == 1){
		printf("\n****Datos ordenados****\n");
		printPassenger(list, len);
	}
	return estaOrdenado;
}

int sortPassengerByCode(Passengers list[], int len, int order, int statusFlight){
	int ordenarAcedenteDecedente;
	int lenAux;
	int i;
	int estaOrdenado;

	lenAux=len;
	Passengers auxPassenger;

	if(list!=NULL && len>0){
		if(order==1){
			ordenarAcedenteDecedente =-1;
		}
		else{
			ordenarAcedenteDecedente = 1;
		}
		do{
			estaOrdenado = 1;
			for(i=0;i<lenAux;i++){
				if(list[i].isEmpty==0 && list[i+1].isEmpty==0 ){
					if(stricmp(list[i].flyCode,list[i+1].flyCode)==0){
						if(list[i].typePassenger>list[i+1].typePassenger){
							auxPassenger=list[i];
							list[i]=list[i+1];
							list[i+1]=auxPassenger;
							estaOrdenado = 0;
						}
					}else{
						if(stricmp(list[i].flyCode,list[i+1].flyCode)== ordenarAcedenteDecedente){
							auxPassenger=list[i];
							list[i]=list[i+1];
							list[i+1]= auxPassenger;
							estaOrdenado = 0;
						}
					}
				}
			}
		}while(estaOrdenado == 0 );
	}

	if(estaOrdenado == 1){
		printf("\nPasajeros:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
		for(i=0;i<len;i++){
			if(list[i].statusFlight == statusFlight){
				printSinglePassenger(list[i]);
			}
		}
	}

	return estaOrdenado;
}

int printSubMenuReport(Passengers list[], int len, int reintentos){
	int opcion;
	int opcionCorrecta;
	int validacion;

	validacion = 0;
	if(list!=NULL && len>0){
		do{
			printf("\n1.Listado ordenado por Apellido y Iipo de pasajero"
					"\n2.Total y Promedio de los precios de los pasajes"
					"\n3.Listado de los pasajeros por Codigo de vuelo y estado de vuelo 'ACTIVO'"
					"\n4.Salir\n");
			opcionCorrecta = GetNumberWithRange("\nElija el informe que desea mostrar: ", "\nERROR. Opcion invalida.", reintentos, 1, 4, &opcion);
			if (opcionCorrecta == 1) {
				validacion = 1;
				switch (opcion) {
					case 1:
						sortPassengers(list, len, -1);
						break;
					case 2:
						TotalAvaragePrice(list, len);
						break;
					case 3:
						sortPassengerByCode(list, len, -1, 1);
						break;
				}
			}else{
				opcion = 4;
				printf("\nNo se ingreso ninguna opcion valida.\n");
				printf("\n****SE REGRESA AL MENU PRINCIPAL****.\n\n");
			}
		}while(opcion != 4);

	}
	return validacion;
}

void TotalAvaragePrice(Passengers list[], int len){
	int i;
	float totalPrice;
	float avarage;
	int countPrice;
	int countPriceUp;

	totalPrice = 0;
	countPrice = 0;
	countPriceUp = 0;
	for(i = 0; i<len ; i++){
		if(list[i].isEmpty == 0){
			totalPrice = list[i].price + totalPrice;
			countPrice++;
		}
	}

	CalcularPromedio(totalPrice, countPrice, &avarage);

	for(i = 0; i<len ; i++){
		if(list[i].isEmpty == 0){
			if(list[i].price>avarage){
				countPriceUp++;
			}
		}
	}

	if(countPrice!= 0){
		printf("\nTotal de Precios: %.2f\n\nPromedio de precios: %.2f\n\nCantidad de pasajeros que superan el Precio Promedio: %d\n\n",totalPrice,avarage,countPriceUp);
	}

}

int cargaForzada(Passengers list[], int len, int* id){
	int i;
	int j;
	int idAux;
	int cantidadDePasajeros;
	int cargaExitosa;
	char nombres[5][50] = {"Mariela", "Juan Pablo", "Mauro", "Yolanda", "Fabio"};
	char apellidos[5][50] = {"Gomez","Martinez","Gomez","Alberdi","Benitez"};
	float precios[5] = {20000,30000, 18000, 32000, 45000};
	char codigoVuelo[5][50] = {"AA200","LA201","AA200","LA200","AA220"};
	int tipoPasajeros[5] = {1,2,2,1,2};
	int estadoVuelos[5] = {1,1,1,2,3};

	cargaExitosa = 0;
	cantidadDePasajeros = 5;
	idAux = *id;

	if (len > cantidadDePasajeros){
		for (i = 0; i<len; i++){
			if(list[i].isEmpty == 1 && i<cantidadDePasajeros){
				for(j = 0; j<5; j++){
					idAux++;
					addPaseenger(list, len, idAux, nombres[j], apellidos[j], precios[j], tipoPasajeros[j], codigoVuelo[j], estadoVuelos[j]);
				}
				cargaExitosa = 1;
			}
		}
	}
	*id = idAux;
	return cargaExitosa;
}

