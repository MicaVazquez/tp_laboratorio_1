/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger * puntero;

	puntero =  (Passenger*)malloc(sizeof(Passenger));

	return puntero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr)
{
     Passenger *  unPasajero = Passenger_new();
     int tipoPasajeroInt;
     int estadoVueloInt;

     if(unPasajero != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL)
     {
        tipoPasajeroInt = Passenger_changeTypeP(tipoPasajeroStr);//asigna un numero al tipo
        estadoVueloInt =  Passenger_changeStatusFlight(estadoVueloStr);

        if(Passenger_setId(unPasajero, atoi(idStr)) == -1 ||
        		Passenger_setNombre(unPasajero, nombreStr) == -1 ||
				Passenger_setApellido(unPasajero, apellidoStr) == -1||
				Passenger_setPrecio(unPasajero, atof(precioStr)) == -1||
				Passenger_setTipoPasajero(unPasajero,tipoPasajeroInt) == -1||
				Passenger_setCodigoVuelo(unPasajero, codigoVueloStr) == -1||
				Passenger_setStatusFlight(unPasajero, estadoVueloInt) == -1)
               {
        	       Passenger_delete(unPasajero);
               }

     }

     return unPasajero;
}



void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

		if(this!= NULL && id != NULL)
		{

			*id = this->id;
			retorno = 0;

		}

		return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno =-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this!= NULL && nombre != NULL)
	{

		strcpy(nombre,this->nombre);
		retorno = 0;

	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno =-1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido,apellido);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this!= NULL && apellido != NULL)
	{

		strcpy(apellido,this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this!= NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this!= NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
  int retorno = -1;

  if(this != NULL && tipoPasajero > 0)
  {
	  this->tipoPasajero = tipoPasajero;
	  retorno = 0;
  }
  return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	  return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		*precio = this->precio;
		retorno = 0;
	}

	  return retorno;
}

int Passenger_setStatusFlight(Passenger* this,int estado)
{
	int retorno =-1;

	if(this != NULL && estado >= 0)
	{
		this->estado = estado;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getStatusFlight(Passenger* this,int* estado)
{
	int retorno = -1;

	if(this!= NULL && estado >= 0)
	{
		*estado = this->estado;
		retorno = 0;
	}
	return retorno;
}

int Passenger_changeTypeP(char* tipoPasajero)
{
	int typePassengerInt;

	if(strcmp(tipoPasajero,"FirstClass")==0)
	{
		typePassengerInt = 1;
	}
	else
	{
		if(strcmp(tipoPasajero,"ExecutiveClass")==0)
		{
			typePassengerInt = 2;
		}
		else
		{
			if(strcmp(tipoPasajero,"EconomyClass")==0)
			{
				typePassengerInt = 3;
			}
		}
	}
	return typePassengerInt;
}

int Passenger_changeStatusFlight(char* estadoVuelo)
{
	int statusFlightInt;

	if(strcmp(estadoVuelo,"En Horario")==0)
	{
		statusFlightInt = 1;
	}
	else
	{
	    if(strcmp(estadoVuelo,"Demorado")==0)
		{
			statusFlightInt = 2;
		}
		else
		{
			if(strcmp(estadoVuelo,"En Vuelo")==0)
			{
				statusFlightInt = 3;
			}
			else if(strcmp(estadoVuelo,"Aterrizado")==0)
			{
				statusFlightInt = 4;
			}
		}
	}
	return statusFlightInt;
}

void Passenger_printOne(Passenger* unPasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[100];
	int estado;
	char types[3][50]={"FirstClass","ExecutiveClass","EconomyClass"};
	char statusFlight[4][100]={"En Horario","Demorado","En Vuelo","Aterrizado"};

	Passenger_getId(unPasajero, &id);
	Passenger_getNombre(unPasajero, nombre);
	Passenger_getApellido(unPasajero, apellido);
	Passenger_getPrecio(unPasajero, &precio);
	Passenger_getTipoPasajero(unPasajero, &tipoPasajero);
	Passenger_getCodigoVuelo(unPasajero, codigoVuelo);
	Passenger_getStatusFlight(unPasajero, &estado);


	printf("\n%-5d%-15s%-15s%-10.2f%-17s%-16s%15s\n", id ,nombre, apellido,precio,types[tipoPasajero-1],codigoVuelo, statusFlight[estado-1]);
}

int Passenger_sortName(void* p1,void*p2)
{
	char name1[50];
	char name2[50];
	int rtn;

	Passenger* pasajero1 = (Passenger*)p1;
	Passenger* pasajero2 = (Passenger*)p2;

	if(pasajero1 != NULL && pasajero2 != NULL)
	{
       Passenger_getNombre(pasajero1, name1);
       Passenger_getNombre(pasajero2, name2);

       rtn =stricmp(name1,name2);
	}

	return rtn;
}

int Passenger_sortPrice(void* p1,void* p2)
{
	int retorno;
	float precio1=0;
	float precio2=0;

	    Passenger* pasajero1 = (Passenger*)p1;
	    Passenger* pasajero2 = (Passenger*)p2;

	    if(pasajero1!=NULL && pasajero2!=NULL)
	    {
	        Passenger_getPrecio(pasajero1, &precio1);
	        Passenger_getPrecio(pasajero2, &precio2);


	       if(precio1>precio2)
	       {
	           retorno = 1;
	       }
	       else if(precio1<precio2)
	       {
	           retorno = -1;
	       }
	       else
	       {
	           retorno = 0;
	       }

	    }
	return retorno;
}
