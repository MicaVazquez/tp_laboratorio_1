/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[100];
	char estado[50];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr, char* estadoVuelo);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);
/**
 * @brief setea la variable de estado de vuelo
 *
 * @param this
 * @param estado
 * @return retorna el estado de vuelo validado
 */
int Passenger_setStatusFlight(Passenger* this,char* estado);

/**
 * @brief devuelve una copia del dato que se encuentra en el campo estado
 *
 * @param this
 * @param estado
 * @return devuelve el dato para ser imprimido
 */
int Passenger_getStatusFlight(Passenger* this,char* estado);

/**
 * @brief le asigna al tipo de pasajero string un valor numerico
 *
 * @param tipoPasajero variable char
 * @return retorna un entero
 */
int Passenger_changeTypeP(char* tipoPasajero);
void Passenger_printOne(Passenger* unPasajero);

#endif /* PASSENGER_H_ */