/*
 * arrayPassenger.c
 *
 *  Created on: 24 abr. 2022
 *      Author: PC-INC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassenger.h"
#include "validaciones.h"



#define LIBRE 1
#define OCUPADO 0
#define BAJA -1

#define CANCELADO 0
#define DEMORADO 1
#define ACTIVO 2

static int idIncremental = 1005;
static int ePasajero_obtenerID();
static int ePasajero_obtenerID()
{
	return idIncremental++;
}


int inicializarArrayPasajeros(ePasajero* list, int len)
{  int retorno = -1;
   int i;
    if(list != NULL && len > 0)
    {
    	retorno =0;
    	for(i=0;i<len;i++)
    	{
            list[i].isEmpty = LIBRE;

    	}
    }
	return retorno;
}

ePasajero cargarDatos(eAvion* listaAviones, int lenA)
{
	ePasajero unPasajero;
	char nombre[51];
	char apellido[51];
	float precio;
	int tipoDePasajero;
	int opcionCodigo;
    int i;

	getString("\nIngrese un nombre: ",nombre,1,51);
	getString("\nIngrese un apellido: ",apellido,1,51);

    getFloat("\nIngrese el precio: ",&precio,1,99999999);

    printf("\nElija un codigo de vuelo: ");

       for(i=0;i<lenA;i++)
       {
    	   if(listaAviones[i].isEmptyCV == OCUPADO)
    	   {
       	      printf("\n\n %d. %s",i+1,listaAviones[i].IDcodigoDeVuelo);
    	   }
       }

    getInt("\nOpcion: ",&opcionCodigo,1,lenA);

    strcpy(unPasajero.codigoDeVuelo,listaAviones[opcionCodigo-1].IDcodigoDeVuelo);

	printf("\nElija un tipo de pasajero\n\n 1. Primera Clase\n\n 2. Ejecutivo\n\n 3. Economico");

	getInt("\nOpcion: ",&tipoDePasajero,1,3);

	   strcpy(unPasajero.nombre,nombre);
	   strcpy(unPasajero.apellido,apellido);
	   unPasajero.precio=precio;
	   unPasajero.tipoDePasajero=tipoDePasajero;
	   unPasajero.isEmpty=0;
		return unPasajero;
}

int buscarLibre(ePasajero* list, int len)
{
	int i;
	int indice=-1;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty == LIBRE)//libre
		{
			indice=i;
			break;
		}
	}
 return indice;
}


int agregarPasajero(ePasajero* list, int len, int id, char nombre[],char
apellido[],float precio,int tipoDePasajero, char codigoDeVuelo[],int isEmpty)
{
	int indice;
	int retorno =-1;


	indice = buscarLibre(list,len);

	if(indice != -1 && list != NULL)
	{
		strcpy(list[indice].nombre, nombre);
		strcpy(list[indice].apellido, apellido);
        list[indice].precio = precio;
        list[indice].tipoDePasajero = tipoDePasajero;
        strcpy(list[indice].codigoDeVuelo,codigoDeVuelo);

        list[indice].id = id;
        list[indice].isEmpty = isEmpty;

		retorno = 0;
	}
return retorno;
}


int altaPasajero(ePasajero* list, int len, eAvion* listaAviones, int lenA)
{
	ePasajero pasajeroAux;
	int id;
	int recibo = -1;

	if(list != NULL && len > 0)
	{
	pasajeroAux = cargarDatos(listaAviones,lenA);
	id = ePasajero_obtenerID();
	recibo = agregarPasajero(list,len,id,pasajeroAux.nombre,pasajeroAux.apellido,pasajeroAux.precio,pasajeroAux.tipoDePasajero,pasajeroAux.codigoDeVuelo,pasajeroAux.isEmpty);

		if(recibo  == 0)
		{
			printf("La carga fue exitosa...");
		}
		else
		{
			printf("No hay espacio... ");
		}

	}
	return recibo;
}


int encontrarPasajeroPorId(ePasajero* list, int len,int id)
{  int i;
   int indice = -1;

	if(list != NULL && len > 0)
	{
        for(i=0;i<len;i++)
        {
        	if(list[i].id == id && list[i].isEmpty == OCUPADO)
        	{
        		indice = i;
               break;
        	}
        }
	}
   return indice;
}

void imprimirUnPasajero(ePasajero unPasajero)
{
	char vec[][31] = {"Primera Clase","Ejecutivo","Economico"};
	//char estado[][31] = {"Cancelado","Demorado","Activo"};

	printf("|%-5d|%-10s|%-10s|%-10.2f|%-17s|%-16s|\n",unPasajero.id,unPasajero.apellido, unPasajero.nombre, unPasajero.precio,unPasajero.codigoDeVuelo,vec[unPasajero.tipoDePasajero-1]);
}

int imprimirArrayPasajeros(ePasajero* list, int largo)
{
	int i=0;


	printf("\nID     Apellido   Nombre    Precio     Codigo de vuelo   Tipo de Pasajero\n");

    if( list != NULL && largo > 0)
    {
		for(i=0;i<largo;i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				imprimirUnPasajero(list[i]);
			}
		}
    }
    return 0;
}


void modificarPasajero (ePasajero* list, int len,eAvion* listaAviones, int lenA)
{
	int datoEncontrado;
	int auxId;
	int opcionModificar;
	int opcionCodigo;
	int i;
	imprimirArrayPasajeros(list, len);
	getInt("\nIngrese numero de ID del pasajero a modificar: ",&auxId,0,999999);
	datoEncontrado = encontrarPasajeroPorId(list, len, auxId);

	if(datoEncontrado != -1 )
	{
		printf("\nSe encontro el dato: \n");
		printf("\nID     Apellido   Nombre    Precio     Codigo de vuelo   Tipo de Pasajero\n");
		imprimirUnPasajero(list[datoEncontrado]);


		do{
			getInt("\n¿Que desea modificar?\n  1.Nombre\n  2.Apellido \n  3.Precio\n  4.Codigo de vuelo\n  5.Tipo de pasajero\n  6.Volver al menu\nOpcion: ",&opcionModificar,1,6);
				switch(opcionModificar)
				{

					case 1:
						getString("Ingrese nombre: ",list[datoEncontrado].nombre , 1, 51);
						break;
					case 2:
						getString("Ingrese apellido: ",list[datoEncontrado].apellido , 1, 51);
						break;
					case 3:
						getFloat("Ingrese precio: ",&list[datoEncontrado].precio , 1, 999999);
						break;
					case 4:
						 printf("\nElija un codigo de vuelo: ");

						       for(i=0;i<lenA;i++)
						       {
						    	   if(listaAviones[i].isEmptyCV == OCUPADO)
						    	   {
						       	      printf("\n\n %d. %s",i+1,listaAviones[i].IDcodigoDeVuelo);
						    	   }
						       }

						    getInt("\nOpcion: ",&opcionCodigo,1,lenA);

						    strcpy(list[datoEncontrado].codigoDeVuelo,listaAviones[opcionCodigo-1].IDcodigoDeVuelo);

						break;
					case 5:
						printf("\nElija un tipo de pasajero\n\n 1.Primera Clase\n\n 2.Ejecutivo\n\n 3.Economico");
						getInt("\nOpcion: ",&list[datoEncontrado].tipoDePasajero,1,3);
						break;
					case 6:
						break;
					default:
						printf("La opcion ingresada es incorrecta.");
						break;
				}

		}while(opcionModificar != 6);
	}
	else
	{
		printf("No se encontro el dato.");
	}
}

int eliminarPasajero(ePasajero* list, int len, int id, int posicion )
{
	int retorno = -1;
	char confirmar;

	if(list != NULL && len > 0)
	{
		printf("Dar de baja? [S|N]: ");
		fflush(stdin);
		scanf("%c",&confirmar);
		confirmar = toupper(confirmar);

		if(confirmar == 'S')
		{
			list[posicion].isEmpty= BAJA;
			printf("Se han borrado los datos...");
			retorno = 0;
		}
		else
		{
			printf("No se han borrado los datos...");
			retorno = 1;
		}
	}
	return retorno;
}


int bajaPasajero(ePasajero* list, int len)
{
	int retorno = -1;
	int datoEncontrado;
	int auxId;
	imprimirArrayPasajeros(list, len);
	getInt("\nIngrese numero de ID del pasajero a dar de baja: ",&auxId,0,999999);;
	datoEncontrado = encontrarPasajeroPorId(list,len, auxId);

	if(datoEncontrado != -1 )
	{

		printf("\nSe encontro el dato: \n");
		printf("\nID     Apellido   Nombre    Precio     Codigo de vuelo   Tipo de Pasajero\n");
		imprimirUnPasajero(list[datoEncontrado]);
		if(eliminarPasajero(list, len,auxId,datoEncontrado) == 0)
		{
			retorno = 0;
		}
	}
	else
	{
		printf("No se encontro el dato.");
	}
	return retorno;
}

int ordenarPasajerosPorApellido(ePasajero* list, int len, int order)
{
	int retorno = -1;
	int i;
	int j;
	ePasajero aux;

	if(list != NULL && len > 0)
	{
		retorno = 0;

		if(order == 1)//UP//ascendente
		{
            for(i=0;i<len-1;i++)
            {
            	for(j=i+1;j<len;j++)
            	{
            		if(stricmp(list[i].apellido,list[j].apellido)>0)
            		{
                          aux = list[i];
                          list[i] = list[j];
                          list[j] = aux;
            		}
            		else
            		{
            			if(stricmp(list[i].apellido,list[j].apellido)==0)
            			{
            				if(list[i].tipoDePasajero < list[j].tipoDePasajero)
            				{
            					aux = list[i];
            					list[i] = list[j];
            					list[j] = aux;
            				}

            			}
            	    }
            	}
		   }
	    }
		else//DOWN descendente
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(stricmp(list[i].apellido,list[j].apellido)<0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(stricmp(list[i].apellido,list[j].apellido)==0)
						{
							if(list[i].tipoDePasajero > list[j].tipoDePasajero)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}

						}
					}
				}
			}
		}


	}

return retorno;
}



void hardcodearPasajeros (ePasajero* list)
{
	int i;

	int id[] = {1000,1001,1002,1003,1004};
	char nombre[][51] = {"Mariana","Agustin","Lorelai","Esteban","Leonel"} ;//nombre
	char apellido[][51] = {"Romero","Rivola","Gilmore","Larusso","Benitez"};//apellido
	float precio[] = {22000,23000,24000,25000,26000};
	char codigoDeVuelo[][10] = {"RFG2","DRG3","ERT7","JTU1","CWR9"};//codigo de vuelo
	int tipoDePasajero[] = {1,2,2,3,1};// vip ejecutivo turista
	int isEmpty[] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};


	for(i=0;i<5;i++)
	{
		list[i].id = id[i];
		strcpy(list[i].nombre, nombre[i]);
		strcpy(list[i].apellido, apellido[i]);
		list[i].precio = precio[i];
		strcpy(list[i].codigoDeVuelo,codigoDeVuelo[i]);
		list[i].tipoDePasajero = tipoDePasajero[i];
		list[i].isEmpty = isEmpty[i];

	}

}

void hardcodearAvion(eAvion* list)
{
	int i;
	char IDcodigoDeVuelo[][10]={"RFG2","DRG3","ERT7","JTU1","CWR9"};//PK
	int estadoDeVuelo[]= {DEMORADO,DEMORADO,ACTIVO,CANCELADO,ACTIVO};
	int isEmptyCV[] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

	for(i=0;i<5;i++)
		{
			strcpy(list[i].IDcodigoDeVuelo,IDcodigoDeVuelo[i]);
			list[i].estadoDeVuelo = estadoDeVuelo[i];
			list[i].isEmptyCV = isEmptyCV[i];
		}
}

int ordenarPasajerosPorCodigo(ePasajero* list, int len, int order, eAvion* listaAviones)
{
	int retorno = -1;
	int i;
	int j;
	ePasajero aux;

	if(list != NULL && listaAviones != NULL && len > 0)
	{
		retorno = 0;
         if(order == 1)//UP
         {
        	 for(i=0;i<len-1;i++)//recorre lista de pasajeros
        	 {
        		 for(j=i+1;j<len;j++)
        		 {
        			 if(stricmp(list[i].codigoDeVuelo,list[j].codigoDeVuelo)>0)//compara codigo entre posicones
        			 {
        				 aux = list[i];
        				 list[i] = list[j];
        				 list[j] = aux;
        			 }
        		 }
        	 }
         }
         else
         {
        	 for(i=0;i<len-1;i++)//DOWN
        	 {
        		 for(j=i+1;j<len;j++)
        		 {
        			 if(stricmp(list[i].codigoDeVuelo,list[j].codigoDeVuelo)<0)
        			 {
        				 aux = list[i];
        				 list[i] = list[j];
        				 list[j] = aux;
        			 }
        		 }
        	 }
         }
	}

return retorno;
}

int mostrarPasajerosVueloActivo(ePasajero* list, int largo, eAvion* listaAviones, int len)
{

	int i=0;
	int j=0;

	char vec[][31] = {"Primera Clase","Ejecutivo","Economico"};
	char estado[][31] = {"Cancelado","Demorado","Activo"};


	printf("\nCodigo de vuelo   Estado de vuelo    ID     Apellido   Nombre    Precio     Tipo de Pasajero\n");

    if( list != NULL && largo > 0)
    {
		for(i=0;i<largo;i++)//recorre array de pasajeros
		{
			if(list[i].isEmpty == OCUPADO)// si la posicion esta ocupada
			{
                for(j=0;j<len;j++)//recorre array de aviones
                {
                	if(stricmp(list[i].codigoDeVuelo,listaAviones[j].IDcodigoDeVuelo)==0)
                	{
                      if(listaAviones[j].estadoDeVuelo == ACTIVO)
                      {
                    	  printf("|%-17s|%-17s|%-5d|%-10s|%-10s|%-10.2f|%-16s|\n",list[i].codigoDeVuelo,estado[listaAviones[j].estadoDeVuelo],list[i].id,list[i].apellido, list[i].nombre, list[i].precio,vec[list[i].tipoDePasajero-1]);

                      }
                	}
                }

			}
		}
    }
    return 0;
}



void importeTotalPromedio(ePasajero* lista, int tam)
{   int i;
    int acumulador = 0;
    int contador = 0;
    int contadorMayores = 0;
    float promedio;

	if(lista != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				acumulador+= lista[i].precio;
				contador++;
			}
		}

	}
	if(contador != 0)
	{
	  printf("\n -El total es: %d\n",acumulador);
      promedio = (float)acumulador/contador;
      printf("\n -El promedio es: %.2f\n",promedio);

      for(i=0;i<tam;i++)
      {
    	  if(lista[i].isEmpty == OCUPADO && lista[i].precio > promedio)
    	  {
              contadorMayores++;
    	  }
      }

      if(contadorMayores > 0)
      {
    	  printf("\n -La cantidad de pasajeros que superan el promedio: %d\n",contadorMayores);
      }

	}

}

void informar(ePasajero* pasajeros, int lenP, eAvion* aviones, int lenA)
{

		int opcionInformar;
	    int orden;
	do{
		getInt("\n\n¿Que desea informar?\n  1. Pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n  2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n  3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n  4. Volver al menu\n Opcion: ",&opcionInformar,1,4);
		switch(opcionInformar)
		{

		case 1:
			//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
			printf("\nElija un orden\n 1- Ascendete A-Z \n 2- Descendente Z-A");
			getInt("\nOpcion:",&orden,1,2);
			ordenarPasajerosPorApellido(pasajeros,lenP, orden);
			imprimirArrayPasajeros(pasajeros, lenP);
			break;
		case 2:
			//Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
			importeTotalPromedio(pasajeros,lenP);
			break;
		case 3:
			//Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
			printf("\nElija un orden\n 1- Ascendete A-Z \n 2- Descendente Z-A");
			getInt("\nOpcion:",&orden,1,2);
			ordenarPasajerosPorCodigo(pasajeros, lenP,orden ,aviones);
			mostrarPasajerosVueloActivo(pasajeros, lenP,aviones,lenA);
			break;
		case 4:
			break;
		}
	}while(opcionInformar != 4);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int DarDeAlta(ePasajero* list, int lenP, eAvion* listaAviones,int lenA)
{
    int opcionDeAlta;
    int retornoAlta;


	getInt("\nQuiere dar de alta?:\n 1_Pasajeros\n 2_Vuelos\nOpcion: ",&opcionDeAlta,1,2);

	switch(opcionDeAlta)
	{

		case 1:
			retornoAlta = altaPasajero(list,lenP,listaAviones,lenA);//rtn 0//-1

			break;

		case 2:
			altaVuelos(listaAviones,lenA);
			break;
	}
	return retornoAlta;
}

int altaVuelos(eAvion* listaA,int lenA)
{

	int indiceLibre;
	int rtn = -2 ;
	char auxCV[10];


	indiceLibre = buscarLibreCodigoVuelo(listaA,lenA);

	if(indiceLibre != -1 && listaA != NULL)
	{
       getLetrasYNumeros("\n Ingrese un nuevo codigo de vuelo: ", auxCV, 1, 10);//codigo de vuelo
       if(buscarRepetido(listaA, lenA,auxCV )==1)
       {
    	   printf("\nError.Ese codigo ya existe.\n");
       }
       else
       {
    	   strcpy(listaA[indiceLibre].IDcodigoDeVuelo,auxCV);
       }

        listaA[indiceLibre].estadoDeVuelo = CANCELADO;
        listaA[indiceLibre].isEmptyCV = OCUPADO;

		rtn = 1;
	}
	else
	{
		printf("\n No hay espacio...");
	}

return rtn;
}


int buscarLibreCodigoVuelo(eAvion* list, int len)
{
	int i;
	int indice=-1;

	if( list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmptyCV == LIBRE)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}



void inicializarCodigosVuelos(eAvion* listA, int lenA)
{
	int i;
	if(listA != NULL && lenA > 0)
	{

		for(i=0;i<lenA;i++)
		{
			listA[i].isEmptyCV = LIBRE;

		}

	}
}


int buscarRepetido(eAvion* listaAv, int lenA,char* input)
{
     int i;
     int rtn = 0;

     for(i=0;i<lenA;i++)
     {
        if(stricmp(listaAv[i].IDcodigoDeVuelo,input)==0)
        {
        	rtn= 1;//true
        	break;
        }
     }
     return rtn;
}


void menuModificar(ePasajero* list, int lenP, eAvion* listaAviones,int lenA)
{
    int opcion;



	getInt("\nQue desea modificar?:\n 1_Pasajeros\n 2_Estado de vuelo\n",&opcion,1,2);

	switch(opcion)
	{

		case 1:
			 modificarPasajero(list,lenP,listaAviones,lenA);
			break;

		case 2:
			modificarEstadoVuelo(listaAviones,lenA);
			break;
	}

}

void modificarEstadoVuelo(eAvion* listaAviones,int lenA)
{

 int i;
 int opcionCodigo;
 int opcionEstado;
 char estado[][31] = {"Cancelado","Demorado","Activo"};

  printf("\nElija un codigo de vuelo: ");

       for(i=0;i<lenA;i++)
       {
    	   if(listaAviones[i].isEmptyCV == OCUPADO)
    	   {
       	      printf("\n\n %d. %s | %s",i+1,listaAviones[i].IDcodigoDeVuelo,estado[listaAviones[i].estadoDeVuelo]);
    	   }
       }

    getInt("\nOpcion: ",&opcionCodigo,1,lenA);

    getInt("\n Elija un estado de vuelo: \n1.Cancelado \n2.Demorado \n3.Activo \n.Opcion: ",&opcionEstado,1,3);

    listaAviones[opcionCodigo-1].estadoDeVuelo = opcionEstado-1;
}

