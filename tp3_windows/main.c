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

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	getInt("MENU:\n1.Cargar datos de pasajeros desde el archivo-modo texto.\n2.Cargar datos de pasajero desde el archivo-modo binario\n3.Alta de pasajero\n4.Modificar datos de pasajeros.\n5.Baja de pasajeros\n6.Listar pasajeros\n7.Ordenar pasajeros\n8.Guardar datos(modo texto)\n9.Guardar datos(modo binario)\n10.Salir\n Opcion: ", &option, 1, 10);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                //system("pause");
                break;
            case 2:
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            	break;
            case 4:
            	controller_editPassenger(listaPasajeros);
            	break;
            case 5:
            	// baja
            	controller_removePassenger(listaPasajeros);
            	break;
            case 6://listar
            	controller_ListPassenger(listaPasajeros);
            	break;
            case 7://ordenar
            	break;
            case 8://guardar
            	break;
            case 9://guardar
            	break;
            case 10://salir
            	break;
        }
    }while(option != 10);
    return 0;
}

