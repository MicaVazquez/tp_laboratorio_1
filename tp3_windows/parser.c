#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
   char id[100];
   char nombre[100];
   char apellido[100];
   char precio[100];
   char codigoVuelo[100];
   char tipoPasajero[100];
   char estadoVuelo[100];
   Passenger* unPasajero;
   int cant;
   int exito = 0;

   fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);//falsa lectura
   while(feof(pFile)==0)
   {
	     cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

	     if(cant == 7)
	     {
           unPasajero = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo,estadoVuelo);

           if(unPasajero != NULL)
           {
        	   ll_add(pArrayListPassenger, unPasajero);
        	   exito = 1;
           }
	     }
   }
    return exito;// ??
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
