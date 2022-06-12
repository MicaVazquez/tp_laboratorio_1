/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[100];
	int estado;

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
int Passenger_setStatusFlight(Passenger* this,int estado);

/**
 * @brief devuelve una copia del dato que se encuentra en el campo estado
 *
 * @param this
 * @param estado
 * @return devuelve el dato para ser imprimido
 */
int Passenger_getStatusFlight(Passenger* this,int* estado);

/**
 * @brief le asigna al tipo de pasajero string un valor numerico
 *
 * @param tipoPasajero variable char
 * @return retorna un entero
 */
int Passenger_changeTypeP(char* tipoPasajero);
/**
 * @brief imprime un pasajero por consola
 *
 * @param unPasajero
 */
void Passenger_printOne(Passenger* unPasajero);
/**
 * @brief ordenar ppr nombre
 *
 * @param p1 un pasajero
 * @param p2 otro pasajero
 * @return retorna comparacion
 */
int Passenger_sortName(void* p1,void*p2);
/**
 * @brief ordenar por precio
 *
 * @param p1
 * @param p2
 * @return retorna comparacion ( 1 si el primer precio es mayor al segundo precio y 0 si es al reves)
 */
int Passenger_sortPrice(void* p1,void* p2);
/**
 * @brief le da un valor entero al string estado de vuelo
 *
 * @param estadoVuelo
 * @return retorna un entero(1 En Horario, 2 Demorado,En Vuelo 3, 4 Aterrizado)
 */
int Passenger_changeStatusFlight(char* estadoVuelo);
/**
 * @brief obtiene el maximo id guardado en un archivo
 *
 * @param id
 * @return retorna si hubo exito 1 y 0 si no
 */
int Passenger_LastId(char* id);
/**
 * @brief  busca el id maximo en la linkedlist
 *
 * @param pArrayListPassenger
 * @return retorna el id maximo
 */
int Passenger_buscarIdMax(LinkedList* pArrayListPassenger);
/**
 * @brief  guarda el id maximo encontado antes de guardar ewl archivo
 *
 * @param lastId
 * @return retorna si hubo exito 1 y 0 si no
 */
int Passenger_saveLastId(int lastId);

#endif /* PASSENGER_H_ */
