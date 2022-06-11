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
//leer aclaraciones para verificar que falta
//validacion confirmar-en baja


int main()
{
	setbuf(stdout,NULL);
    int option;
    int flagText = 0;
   int flagSave = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	getInt("\nMENU:\n1.Cargar datos de pasajeros desde el archivo-modo texto.\n2.Cargar datos de pasajero desde el archivo-modo binario\n3.Alta de pasajero\n4.Modificar datos de pasajeros.\n5.Baja de pasajeros\n6.Listar pasajeros\n7.Ordenar pasajeros\n8.Guardar datos(modo texto)\n9.Guardar datos(modo binario)\n10.Salir\n Opcion: ", &option, 1, 10);
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
            	if(controller_loadFromBinary("data.bin", listaPasajeros)==1)
            	{
            		printf("\nSe cargo el archivo exitosamente!!!");
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
            	//controller_ListPassenger(listaPasajeros);
            	break;
            case 4:
            	if(ll_len(listaPasajeros))
            	{
            		controller_editPassenger(listaPasajeros);
            		//controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo se han ingresado pasajeros aun...");
            	}
            	break;
            case 5:
            	// baja
            	if(ll_len(listaPasajeros))
            	{
            		controller_removePassenger(listaPasajeros);
            		//controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo se han ingresado pasajeros aun...");
            	}
            	break;
            case 6://listar
            	if(ll_len(listaPasajeros))
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo se han ingresado pasajeros aun...");
            	}
            	break;
            case 7://ordenar
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
            	if(flagText == 1)
            	{
            	   if(controller_saveAsText("data.csv", listaPasajeros)==1)
            	   {
                         flagSave = 1;// se guardo
            	   }
            	}
            	else
            	{
            		printf("\nPrimero debe cargar el archivo antes de guardar.");
            	}
            	break;
            case 9://guardar
            	controller_saveAsBinary("data.bin", listaPasajeros);
            	break;
            case 10:
            	if(flagSave == 1)
            	{
            		printf("\nChau!");
            	}
            	else
            	{
            		printf("\nPrimero debe guardar un archivo...");
            	}
            	break;
        }
    }while(option != 10 && flagSave == 0);
    return 0;
}

