/*
 * arrayPassenger.h
 *
 *  Created on: 24 abr. 2022
 *      Author: PC-INC
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char nombre[51];//nombre
	char apellido[51];//apellido
	float precio;
	char codigoDeVuelo[10];//codigo de vuelo  FK
	int tipoDePasajero;// vip ejecutivo turista
	int isEmpty; //(esta vacio)

}ePasajero;

typedef struct
{
	char IDcodigoDeVuelo[10];//PK
	int estadoDeVuelo;// activo demorado cancelado
	int isEmptyCV;

}eAvion;
/**
 * @brief busca un indice libre del array y retorna el indice si lo encontro o -1 si no encontro.
 *
 * @param list array ePasajero
 * @param len largo del array
 * @return
 */
int buscarLibre(ePasajero* list, int len);

/**
 * @brief cargar un pasajero
 *
 * @return devulve un pasajero
 */
ePasajero cargarDatos(eAvion* listaAviones,int lenA);


/**
 * @brief controla el alta de pasajeros
 *
 * @param list array de ePasajero
 * @param len  largo
 * @param id   id
 * @return
 */
int altaPasajero(ePasajero* list, int len, eAvion* listaAviones,int lenA);
/**
 * @brief Para indicar que todas las posiciones en la matriz están vacías,
esta función pone la bandera (isEmpty) en VERDADERO en todos
posición de la matriz(array).
 *
 * @param list Puntero a una matriz de pasajeros
 * @param len int de longitud de la matriz
 * @return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
 */
int inicializarArrayPasajeros(ePasajero* list, int len); // MAIN initPassengers(arrayPassengers, ELEMENTS);


/**
 * @brief agregar en una lista existente de pasajeros los valores recibidos como parámetros
  en la primera posición vacía
 *
 * @param list lista de pasajeros
 * @param len int longitud
 * @param id int
 * @param nombre char
 * @param apellido char
 * @param precio int
 * @param tipoDePasajero int
 * @param codigoDeVuelo char
 * @return int Devuelve (-1) si hay error [Longitud no válida o puntero NULL o sin
espacio libre] - (0) si está bien
 */
int agregarPasajero(ePasajero* list, int len, int id, char nombre[],char
apellido[],float precio,int tipoDePasajero, char codigoDeVuelo[],int isEmpty); //addPassenger(arrayPassenger,ELEMENTS,id,name,lastName,price,typePassenger,flycode);






/**
 * @brief Devuelve/Retorna la posición del índice en la matriz.
 *
 * @param list Passenger*
 * @param len entero
 * @param id  entero
 * @return Posición del índice de pasajeros de regreso o (-1) si [Longitud o
Puntero NULL recibido o pasajero no encontrado]
 */
int encontrarPasajeroPorId(ePasajero* list, int len,int id);



/**
 * @brief Eliminar una pasajera por Id (poner isEmpty Flag en 1)
 *
 *
 * @param list array
 * @param len int
 * @param id  int
 * @return Devuelve (-1) si hay un error [Longitud no válida o puntero NULL o si no se puede
encontrar un pasajero] - (0) si está bien.
 */
int eliminarPasajero(ePasajero* list, int len, int id, int posicion);




/**
 * @brief Ordenar el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
descendente.
 *
 * @param list array
 * @param len int longitud
 * @param order [1] indicate UP - [0] indicate DOWN
 * @return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
 */
int ordenarPasajerosPorApellido(ePasajero* list, int len, int order);


/**
 * @brief imprime el contenido del array de pasajeros.
 *
 * @param list
 * @param largo
 * @return int
 */
int imprimirArrayPasajeros(ePasajero* list, int largo);

/**
 * @brief imprime un pasajero
 *
 * @param unPasajero
 */
void imprimirUnPasajero(ePasajero unPasajero);


/**
 * @brief Ordenar los elementos en la matriz de pasajeros, el orden de los argumentos
indicar orden ARRIBA o ABAJO.
 *
 * @param list array
 * @param len
 * @param order int [1] indica ARRIBA - [0] indica ABAJO
 * @return Devuelve (-1) si hay un error [longitud no válida o puntero NULL] - (0) si está bien
 */
int ordenarPasajerosPorCodigo(ePasajero* list, int len, int order,eAvion* listaAviones);

/**
 * @brief controla la modificacion de pasajeros
 *
 * @param list array
 * @param len longitud
 */
void modificarPasajero (ePasajero* list, int len, eAvion* listaAviones, int lenA);


/**
 * @brief controla las bajas
 *
 * @param list
 * @param len
 * @return Retorna 0 si se realizo una baja y -1 si no.
 */
int bajaPasajero(ePasajero* list, int len);

/**
 * @brief Carga forzada de 5 pasajeros
 *
 * @param list
 */
void hardcodearPasajeros (ePasajero* list);

/**
 * @brief Calcula el total, el promedio y cantidad que supera el promedio.
 *
 * @param lista
 * @param tam
 */
void importeTotalPromedio(ePasajero* lista, int tam);

/**
 * @brief Carga forzada de codigos y estados de vuelos
 *
 * @param list
 */
void hardcodearAvion(eAvion* list);

/**
 * @brief muestra los pasajeros con vuelos activos
 *
 * @param list
 * @param largo
 * @param listaAviones
 * @return 0
 */
int mostrarPasajerosVueloActivo(ePasajero* list, int largo, eAvion* listaAviones, int len);

/**
 * @brief controla la parate de informar llamando a las distintas funciones que ordenan y muestran
 *
 * @param pasajeros lista de pasjeros
 * @param lenP   longitud del array de ePsajero
 * @param aviones lista de vuelos
 * @param lenA   longitud del array de eAvion
 */
void informar(ePasajero* pasajeros, int lenP, eAvion* aviones, int lenA);




//////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief
 *
 * @param list array de pasajeros
 * @param lenP tam array paajeros
 * @param listaAviones Array de aviones
 * @param lenA tam array de aviones
 * @return retorno 0 si se hizo un alta de pasajeros y retorna 1 si se hizo un alta de codigos de vuelo
 */
int DarDeAlta(ePasajero* list, int lenP, eAvion* listaAviones,int lenA);

/**
 * @brief
 *
 * @param listaA Array de aviones
 * @param lenA tam array de aviones
 * @return
 */
int altaVuelos(eAvion* listaA,int lenA);

/**
 * @brief
 *
 * @param list
 * @param len
 * @return
 */
int buscarLibreCodigoVuelo(eAvion* list, int len);

/**
 * @brief
 *
 * @param listA
 * @param lenA
 */
void inicializarCodigosVuelos(eAvion* listA, int lenA);


/**
 * @brief
 *
 * @param listaAv
 * @param lenA
 * @param input
 * @return
 */
int buscarRepetido(eAvion* listaAv, int lenA,char* input);




void modificarEstadoVuelo(eAvion* listaAviones,int lenA);



void menuModificar(ePasajero* list, int lenP, eAvion* listaAviones,int lenA);
#endif /* ARRAYPASSENGER_H_ */
