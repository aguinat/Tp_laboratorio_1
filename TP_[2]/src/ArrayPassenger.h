#ifndef LIBRARIEPASSENGERS_H_
#define LIBRARIEPASSENGERS_H_

typedef struct
{
	int id; // PK
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}Passengers;

int addPaseenger(Passengers list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[], int statusFlight);
int initPassengers(Passengers list[], int len);
int printPassenger(Passengers list[], int len);
int searchFreeIndex(Passengers list[], int len);
int requestPassengers(Passengers list[], int len, int* id, int reintentos);
void printSinglePassenger(Passengers list);
int modifyPassengerData(Passengers list[], int len, int reintentos);
int removePassenger(Passengers list[], int len, int id, int index);
int findPassengerById(Passengers list[], int len, int id, int* index);
int passengerDischarge(Passengers list[], int len, int reintentos);
int printSubMenuReport(Passengers list[], int len, int reintentos);
void TotalAvaragePrice(Passengers list[], int len);
int cargaForzada(Passengers list[], int len, int* id);

// \fn int sortPassengers(Passengers list[], int len, int order)
/// \brief Ordena por Apellido y tipo de pasajero
/// \param array de tipó estructura, que contiene los datos
/// \param tamaño del array
/// \param Indica el orden que tomara, Orden = 1 - ascendente
/// \return Si se ordeno el array con exito.
int sortPassengers(Passengers list[], int len, int order);

// \fn int sortPassengers(Passengers list[], int len, int order)
/// \brief Ordena unicamente por codigo de vuelo
/// \param array de tipó estructura, que contiene los datos
/// \param tamaño del array
/// \param Indica el orden que tomara, Orden = 1 - ascendente
/// \return Si se ordeno el array con exito.
int sortPassengerByCode(Passengers list[], int len, int order, int statusFlight);


#endif /* LIBRARIEPASSENGERS_H_ */
