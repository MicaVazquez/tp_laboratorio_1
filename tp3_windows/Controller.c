#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"
#include "validaciones.h"
#include "Controller.h"
#include <ctype.h>

static int idIncremental = 1001;
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
  int exito = 0;

	  if(path != NULL && pArrayListPassenger != NULL)
	  {
		  pFile = fopen(path,"r");

		  if(pFile != NULL)
		  {
			  parser_PassengerFromText(pFile, pArrayListPassenger);//pide pArchivo y la linkedList
			  exito = 1;
		  }
		  else
		  {
			  printf("\nNo se pudo abrir el archivo...");
		  }

		  fclose(pFile);
	  }
    return exito;
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
	FILE* pFile;
	int exito = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"rb");

		if(pFile != NULL)
		{
			parser_PassengerFromBinary(pFile,pArrayListPassenger);
			exito = 1;
		}
		else
		{

			printf("\nError al leer el archivo\n");
		}
	}
    return exito;
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
   int estado;
   int opcion;
   int exito = 0;

   char codeFlight[8][100]={"MM0987B","BA2491A","IB08004","BR3456J","FR5678G","HY4567D","GU2345F","TU6789B"};
   int statusFlight[8]={1,4,4,2,1,2,3,4};


 if(unPasajero != NULL)
 {

	 id = Passenger_obtenerID();

	 getString("\nIngrese un nombre: ",nombre,1,51);
	 getString("\nIngrese un apellido: ",apellido,1,51);

	 getFloat("\nIngrese el precio: ",&precio,1,99999999);

	 printf("\nElija un codigo de vuelo:\n1-MM0987B\n2-BA2491A\n3-IB08004\n4-BR3456J\n5-FR5678G\n6-HY4567D\n7-GU2345F\n8-TU6789B\n");

	 getInt("\nOpcion: ",&opcion,1,8);

	 strcpy(codigoVuelo,codeFlight[opcion-1]);

	 estado = statusFlight[opcion-1];

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
	//char statusFlight[8][100]={"En Horario","Aterrizado","Aterrizado","Demorado","En Horario","Demorado","En Vuelo","Aterrizado"};
	int statusFlight[8]={1,4,4,2,1,2,3,4};

	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[100];
	int estado;
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
    	printf("\nID     Apellido   Nombre    Precio     Codigo de vuelo   Tipo de Pasajero\n");
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
                   estado = statusFlight[opcionCodigoVuelo-1];
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

		getInt("\nIngrese en id del pasajero a dar de baja: ", &id, 1, tam);

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
		{   printf("\nID     Apellido   Nombre    Precio     Codigo de vuelo   Tipo de Pasajero\n");
			Passenger_printOne(auxPasajero);

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

	printf("\nID   Nombre       Apellido    Precio    Tipo de Pasajero  Codigo de Vuelo    Estado de vuelo\n");

	for(i=0;i<cantidad;i++)
	{
		p = (Passenger*) ll_get(pArrayListPassenger,i);
		Passenger_printOne(p);


		if(i == 200)
		{
			system("pause");
		}
		if(i == 400)
		{
			system("pause");
		}
		if(i == 600)
		{
			system("pause");
		}
		if(i == 800)
		{
			system("pause");
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
	int option;
	int orden;

	getInt("\nOrdenar por: 1.Nombre 2.Precio. Opcion: ", &option, 1, 2);

    switch(option)
    {
      case 1:
          getNumero(&orden, "\nOrden...0.Descendente 1.Ascendente. Opcion: ", "Error.", 0, 1);
    	  printf("\nOrdenando...espere un momento por favor.\n\n");

          ll_sort(pArrayListPassenger, Passenger_sortName, orden);

    	  printf("Ordenamiento terminado\n");
    	  break;
      case 2:
    	  getNumero(&orden, "\nOrden...0.Descendente 1.Ascendente. Opcion: ", "Error.", 0, 1);
    	  printf("\nOrdenando...espere un momento por favor.\n\n");

    	  ll_sort(pArrayListPassenger, Passenger_sortPrice, orden);

    	  printf("Ordenamiento terminado\n");
    	  break;
    }

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
	FILE* pFile;

	Passenger* unPasajero;

	int exito = 0;

	int i;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[100];
	int estado;
	char types[3][50]={"FirstClass","ExecutiveClass","EconomyClass"};
	char statusFlight[4][100]={"En Horario","Demorado","En Vuelo","Aterrizado"};


	pFile = fopen(path,"w");

	if(pFile != NULL)
	{
      fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");

      for(i=0;i<ll_len(pArrayListPassenger);i++)
      {
    	  unPasajero = ll_get(pArrayListPassenger, i);

    	  Passenger_getId(unPasajero, &id);
    	  Passenger_getNombre(unPasajero, nombre);
    	  Passenger_getApellido(unPasajero, apellido);
    	  Passenger_getPrecio(unPasajero, &precio);
    	  Passenger_getTipoPasajero(unPasajero, &tipoPasajero);
    	  Passenger_getCodigoVuelo(unPasajero, codigoVuelo);
    	  Passenger_getStatusFlight(unPasajero, &estado);


    	  fprintf(pFile,"%d,%s,%s,%.0f,%s,%s,%s\n", id ,nombre, apellido,precio,codigoVuelo,types[tipoPasajero-1],statusFlight[estado-1]);
      }
      printf("Datos guardados en modo texto!!!\n");
      fclose(pFile);
      exito = 1;
	}
	else
	{
		printf("\nNo se pudo abrir el archivo...");
	}
    return exito;
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
	FILE* pFile;
	Passenger* unPasajero;

	int i;
	int tam;
	int exito = 0;

	pFile = fopen(path,"wb");

	if(pFile != NULL)
	{
		tam = ll_len(pArrayListPassenger);

		for(i=0;i<tam;i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			fwrite(unPasajero,sizeof(Passenger),1,pFile);
		}

		printf("Datos guardados en modo binario!!!\n");
		fclose(pFile);
		exito = 1;
	}
	else
	{
		printf("\nNo se pudo abrir el archivo...");
	}

    return exito;
}

