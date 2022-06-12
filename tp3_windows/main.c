#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	int option;
	int flagText = 0;
	int flagBinary = 0;
	int flagSaveText = 0;
	int flagSaveBinary = 0;


    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	getInt("\nMENU:\n1.Cargar datos de pasajeros desde el archivo-modo texto.\n2.Cargar datos de pasajeros desde el archivo-modo binario\n3.Alta de pasajero\n4.Modificar datos de pasajeros.\n5.Baja de pasajeros\n6.Listar pasajeros\n7.Ordenar pasajeros\n8.Guardar datos(modo texto)\n9.Guardar datos(modo binario)\n10.Salir\n Opcion: ", &option, 1, 10);
        switch(option)
        {
            case 1:
            	if(flagText == 0)
            	{
					if(controller_loadFromText("data.csv",listaPasajeros)==1)
					{
						printf("\nSe cargo el archivo exitosamente!!!");
						flagText = 1;
					}
            	}
            	else
            	{
            		printf("\nEl archivo ya fue cargado...");
            	}
                break;

            case 2:
            	if(flagBinary == 0)
            	{
					if(controller_loadFromBinary("data.bin", listaPasajeros)==1)
					{
						printf("\nSe cargo el archivo exitosamente!!!");
						flagBinary = 1;
					}
            	}
            	else
            	{
            		printf("\nEl archivo ya fue cargado...");
            	}
            	break;

            case 3:
            	if(controller_addPassenger(listaPasajeros)==1)
            	{
            		printf("\nSe cargo el pasajero exitosamente!!!");
            	}
            	else
            	{
            		printf("\nError.No se pudo cargar el pasajero...");
            	}
            	break;

            case 4:
            	if(ll_len(listaPasajeros))
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo se han ingresado pasajeros aun...");
            	}
            	break;

            case 5:
            	if(ll_len(listaPasajeros))
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo se han ingresado pasajeros aun...");
            	}
            	break;

            case 6:
            	if(ll_len(listaPasajeros))
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo se han ingresado pasajeros aun...");
            	}
            	break;

            case 7:
            	if(ll_len(listaPasajeros))
            	{
            		controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo se han ingresado pasajeros aun...");
            	}
            	break;

            case 8://guardar
            	if(flagText || flagBinary)
            	{
            	   if(controller_saveAsText("data.csv", listaPasajeros)==1)
            	   {
                         flagSaveText = 1;// se guardo
            	   }
            	}
            	else
            	{
            		printf("\nPrimero debe cargar el archivo antes de guardar.");
            	}
            	break;

            case 9://guardar
            	if(flagText || flagBinary)
            	{
            		if(controller_saveAsBinary("data.bin", listaPasajeros)==1)
            		{
            			flagSaveBinary = 1;// se guardo
            		}
            	}
            	else
            	{
            		printf("\nPrimero debe cargar el archivo antes de guardar.");
            	}
            	break;

            case 10:
            	if(flagSaveText && flagSaveBinary)
            	{
            		printf("\nChau!");
            		ll_deleteLinkedList(listaPasajeros);
            	}
            	else
            	{
            		printf("\nPrimero debe guardar los pasajeros en archivo .csv y .bin...");
            	}
            	break;
        }
    }while(option != 10 || !(flagSaveText == 1 && flagSaveBinary == 1));
    return 0;
}

