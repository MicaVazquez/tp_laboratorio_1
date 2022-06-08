#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"
#include "validaciones.h"
#include "Controller.h"
#include <ctype.h>

static int idIncremental = 0;
static int Passenger_obtenerID();
static int Passenger_obtenerID()
{
	return idIncremental++;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
  FILE* pFile;

	  if(path != NULL && pArrayListPassenger != NULL)
	  {
		  pFile = fopen(path,"r");

		  if(pFile != NULL)
		  {
			  parser_PassengerFromText(pFile, pArrayListPassenger);//pide pArchivo y la linkedList
		  }
		  else
		  {
			  printf("No se pudo abrir el archivo");
		  }

		  fclose(pFile);
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
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
   Passenger* unPasajero = Passenger_new();

   int id;
   char nombre[50];
   char apellido[50];
   float precio;
   int tipoPasajero;
   char codigoVuelo[100];
   char estado[100];
   int opcion;
   int exito = 0;

   char codeFlight[8][100]={"MM0987B","BA2491A","IB08004","BR3456J","FR5678G","HY4567D","GU2345F","TU6789B"};
   char statusFlight[8][100]={"En Horario","Aterrizado","Aterrizado","Demorado","En Horario","Demorado","En Vuelo","Aterrizado"};


 if(unPasajero != NULL)
 {

	 id = Passenger_obtenerID();

	 getString("\nIngrese un nombre: ",nombre,1,51);
	 getString("\nIngrese un apellido: ",apellido,1,51);

	 getFloat("\nIngrese el precio: ",&precio,1,99999999);

	 printf("\nElija un codigo de vuelo:\n1-MM0987B\n2-BA2491A\n3-IB08004\n4-BR3456J\n5-FR5678G\n6-HY4567D\n7-GU2345F\n8-TU6789B\n");

	 getInt("\nOpcion: ",&opcion,1,8);

	 strcpy(codigoVuelo,codeFlight[opcion-1]);

	 strcpy(estado,statusFlight[opcion-1]);

	 printf("\nElija un tipo de pasajero\n 1. FirstClass\n 2. ExecutiveClass\n 3. EconomyClass");

	 getInt("\nOpcion: ",&tipoPasajero,1,3);


	 if(Passenger_setId(unPasajero, id) == -1 ||
			 Passenger_setNombre(unPasajero, nombre) == -1 ||
			 Passenger_setApellido(unPasajero, apellido) == -1||
			 Passenger_setPrecio(unPasajero, precio) == -1||
			 Passenger_setTipoPasajero(unPasajero,tipoPasajero) == -1||
			 Passenger_setCodigoVuelo(unPasajero, codigoVuelo) == -1||
			 Passenger_setStatusFlight(unPasajero, estado) == -1)
	 {
		 Passenger_delete(unPasajero);
	 }
	 else
	 {
		 exito = 1;//exito en alta
		 ll_add(pArrayListPassenger, unPasajero);
	 }

 }
   return exito;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int tam = ll_len(pArrayListPassenger);
	int i;
	Passenger* auxPasajero;
	int auxId;//auxId que busca el id|
    int flag = 0;
	int id;//id que quiere buscar el pasajero
	int opcionCodigoVuelo;
	int rtn = 0;

	char codeFlight[8][100]={"MM0987B","BA2491A","IB08004","BR3456J","FR5678G","HY4567D","GU2345F","TU6789B"};
	char statusFlight[8][100]={"En Horario","Aterrizado","Aterrizado","Demorado","En Horario","Demorado","En Vuelo","Aterrizado"};

	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[100];
	char estado[50];
	int option;

	controller_ListPassenger(pArrayListPassenger);

	getInt("\nIngrese en id del pasajero a modificar: ", &id, 1, tam);

	for(i=0;i<tam;i++)
	{
		auxPasajero = ll_get(pArrayListPassenger, i);//devuelve una posicion

		Passenger_getId(auxPasajero, &auxId);
		if(auxId == id)
		{
			flag = 1;
			printf("\nPasajero encontrado exitosamente...\n");
			break;
		}
	}

    if(flag==1)
    {
    	 printf("id      name       lastname     price      flycode       typePassenger        statusFlight\n");
    			   //mostar el pasajero con sus datos
    			   Passenger_printOne(auxPasajero);
	   do
	   {
		   getInt(" 1.Nombre\n 2.Apellido\n 3.Precio\n 4.Codigo de vuelo\n 5.Tipo de pasajero\n 6.Volver al menu principal\nOpcion: ",&option,1,6);

		   switch(option)
		   {
			   case 1:
				   getString("Ingrese el nombre del pasajero : ",nombre,1,50);
				   Passenger_setNombre(auxPasajero,nombre);
				   rtn = 1;
				   break;
			   case 2:
				   getString("Ingrese el apellido del pasajero : ",apellido,1,50);
				   Passenger_setApellido(auxPasajero,apellido);
				   rtn = 1;
				   break;
			   case 3:
				   getFloat("Ingrese el precio : ",&precio,1,400000000);
				   Passenger_setPrecio(auxPasajero,precio);
				   rtn = 1;
				   break;
			   case 4:
				   printf("\nElija un codigo de vuelo:\n1-MM0987B\n2-BA2491A\n3-IB08004\n4-BR3456J\n5-FR5678G\n6-HY4567D\n7-GU2345F\n8-TU6789B\n");
                   getInt("\nOpcion: ",&opcionCodigoVuelo,1,8);
                   strcpy(codigoVuelo,codeFlight[opcionCodigoVuelo-1]);
                   strcpy(estado,statusFlight[opcionCodigoVuelo-1]);
                   Passenger_setCodigoVuelo(auxPasajero, codigoVuelo);
                   Passenger_setStatusFlight(auxPasajero, estado);
                   rtn = 1;
				   break;
			   case 5:
				   printf("\nElija un tipo de pasajero\n 1. FirstClass\n 2. ExecutiveClass\n 3. EconomyClass");
                   getInt("\nOpcion: ",&tipoPasajero,1,3);
                   Passenger_setTipoPasajero(auxPasajero, tipoPasajero);
                   rtn = 1;
				   break;
			   case 6:
				   break;
		   }
	   }while(option != 6);

    }
    else
    {
    	printf("Id de pasajero inexistente...");
    }
		return rtn;
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
	int tam = ll_len(pArrayListPassenger);
	int i;
	int id;
	int flag = 0;
	int auxId;
	char confirmar;
	int retorno = 0;
	Passenger* auxPasajero;

	controller_ListPassenger(pArrayListPassenger);

		getInt("\nIngrese en id del pasajero a modificar: ", &id, 1, tam);

		for(i=0;i<tam;i++)
		{
			auxPasajero = ll_get(pArrayListPassenger, i);//devuelve una posicion

			Passenger_getId(auxPasajero, &auxId);
			if(auxId == id)
			{
				flag = 1;
				printf("\nPasajero encontrado exitosamente...\n");
				break;
			}
		}

		if(flag == 1)
		{
			Passenger_printOne(auxPasajero);
			printf("\nID     Apellido   Nombre    Precio     Codigo de vuelo   Tipo de Pasajero\n");

			printf("Dar de baja? [S|N]: ");
			fflush(stdin);
			scanf("%c",&confirmar);
			confirmar = toupper(confirmar);

			if(confirmar == 'S')
			{
                ll_remove(pArrayListPassenger, i);
				printf("Se han borrado los datos...");
				retorno = 1;
			}
			else
			{
				printf("No se han borrado los datos...");

			}
		}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* p;
	int cantidad = ll_len(pArrayListPassenger);
	int i;


	for(i=0;i<cantidad;i++)
	{
		p = (Passenger*) ll_get(pArrayListPassenger,i);
		Passenger_printOne(p);
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
{
    return 1;
}

