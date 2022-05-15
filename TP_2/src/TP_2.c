/*
 ============================================================================
 Name        : TP_2.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "arrayPassenger.h"



#define CANT 10
#define MAX_CANT 10
int main(void)
{
    setbuf(stdout,NULL);
	ePasajero pasajeros[CANT];//Pasajeros hasta 2000. ARRAY[2000]
	eAvion aviones[MAX_CANT];

	int opcion;
	int contadorDatos=5;

   inicializarArrayPasajeros(pasajeros, CANT);
   inicializarCodigosVuelos(aviones,MAX_CANT);
   hardcodearPasajeros(pasajeros);
   hardcodearAvion(aviones);

    do{
    	getInt("\nMENU\n(1).Alta  (2).Modificar  (3).Baja  (4).Informar  (5).Salir\n Opcion: ",&opcion,1,5);
    	switch(opcion)
    	{

			case 1:
                   if(DarDeAlta(pasajeros,CANT,aviones,MAX_CANT)==0)
                   {
                	   contadorDatos++;
                   }
				break;

			case 2://MODIFICAR
					if( contadorDatos > 0)
					{
					  menuModificar(pasajeros, CANT,aviones,MAX_CANT);
					}
					else
					{
						printf("No existen datos cargados...");
					}
				break;

			case 3://BAJA
				if( contadorDatos > 0)
				{

					if(bajaPasajero(pasajeros, CANT)==0)
					{
						contadorDatos--;
					}
				}
				else
				{
					printf("No existen datos cargados...");
				}
				break;

			case 4://INFORMAR
				if(contadorDatos > 0)
				{
					informar(pasajeros,CANT,aviones,MAX_CANT);

				}
				else
				{
					printf("No existen datos cargados...");
				}
				break;

			case 5://SALIR
				break;

    	}
    	printf("\n\n");
    } while(opcion != 5);


    return EXIT_SUCCESS;
}


