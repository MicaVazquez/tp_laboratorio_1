/*
 ============================================================================
 Name        : TP_1.c
 Author      : VAZQUEZ MICAELA 1-k
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "calculos.h"

int main(void)
{
	setbuf(stdout, NULL);
		int opcion;
        int precioAerolineas;
        int precioLatam;
        int kilometros;

        float tarjetaCreditoAerolineas;
        float tarjetaDebitoAerolineas;
        float bitcoinAerolineas;
        float precioUnitarioAerolineas;

        float tarjetaCreditoLatam;
        float tarjetaDebitoLatam;
        float bitcoinLatam;
        float precioUnitarioLatam;

        float valorBitcoin;
        int banderaCalculosHechos;
        int banderaPrecios;
        int banderaKilometros;
        int resultado;
        int diferenciaPrecios;

        banderaKilometros=0;
        banderaCalculosHechos=0;
        banderaPrecios=0;
        valorBitcoin= 4606954.55;
		do
		{
			opcion = pedirEnteroPositivo("1-Ingresar kilometros\n2-Ingresar precio de vuelos \n3-Calcular todos los costos \n4-Informar resultados \n5-Carga forzada de datos\n6-Salir\n", "Error, no ingreso una opcion correcta.\n");


			switch(opcion)
			{
				case 1:
			    if(banderaKilometros==0)//bandera para que se ingrese solo una vez los kilometros.
				{
			    kilometros = pedirEnteroPositivo("Ingrese los kilometros: ","Error , reingrese los kilometros: ");
                banderaKilometros = 1;
				}
			    else
			    {
			    	printf("\nYa se ingresaron kilometros.");
			    }
				break;

				case 2:
			   if(banderaKilometros==1)//bandera para que no acceda a la opcion 2 sin antes haber ingresado los kilometros en la opcion 1.
			   { //se piden los dos precios y se invoca a la funcion para que valide que sea un nuemero posiivo.
				precioAerolineas = pedirEnteroPositivo("Ingrese el precio del vuelo en Aerolineas: ","Error, reingrese nuevamente el precio del vuelo en Aerolineas: ");

				precioLatam = pedirEnteroPositivo("Ingrese el precio del vuelo en Latam: ","Error, reingrese nuevamente el precio del vuelo en Latam: ");
                 banderaPrecios = 1;
			    }
			   else
			   {   //mensaje para que reingrese si con anterioridad ingreso un numero negativo
				   printf("Error.Se deben ingresar los kilometros (Presione opción 1).");
			   }
				break;

				case 3:

					if(banderaPrecios==1)//bandera para que no se hagan los calculos sin antes haber ingresado kilometros y precios.
					{
						tarjetaDebitoAerolineas = calcularDescuento(precioAerolineas,10);
						tarjetaCreditoAerolineas = calcularAumento(precioAerolineas,25);
						bitcoinAerolineas = dividir(valorBitcoin,precioAerolineas);
						precioUnitarioAerolineas = dividir(precioAerolineas,kilometros);

						tarjetaDebitoLatam = calcularDescuento(precioLatam,10);
						tarjetaCreditoLatam = calcularAumento(precioLatam,25);
						bitcoinLatam = dividir(valorBitcoin,precioLatam);
						precioUnitarioLatam = dividir(precioLatam,kilometros);

						resultado = restar(precioAerolineas,precioLatam);
						diferenciaPrecios = obtenerValorAbsoluto(resultado);

						printf("Ya se han calculado todos los costos.");
						banderaCalculosHechos=1;
					}
					else
					{//mensaje para que antes ingrese los valores necesarios para hacer los calculos.
						printf("Error. Se deben ingresar los precios antes de hacer los calculos (Presione opción 2)");
					}

				break;

				case 4:
					if(banderaCalculosHechos==1)//bandera para que se hagan los calculos antes de mostrar.
					{
						printf("\n=================================================================================\n");
						printf("Kilometros ingresados: %d km\n\n", kilometros);

					    printf("Precio vuelo Aerolineas: $ %d\n",precioAerolineas);
						printf("a) Precio tarjeta de debito Aerolineas: $ %.2f\n",tarjetaDebitoAerolineas);
						printf("b) Precio tarjeta de credito Aerolineas: $ %.2f \n",tarjetaCreditoAerolineas);
						printf("c) Precio el precio en bitcoin Aerolineas: $ %f BTC\n",bitcoinAerolineas);
						printf("d) Precio el precio unitario de Aerolineas: $ %f \n\n",precioUnitarioAerolineas);

						printf("Precio vuelo Latam: %d\n",precioLatam);
						printf("a) Precio tarjeta de debito Latam: $%.2f\n",tarjetaDebitoLatam);
						printf("b) Precio tarjeta de credito Latam:$ %.2f\n",tarjetaCreditoLatam);
						printf("c) Precio el precio en bitcoin Latam:$ %f BTC\n",bitcoinLatam);
						printf("d) Precio unitario de Latam:$ %f\n\n",precioUnitarioLatam);

						printf("La diferencia de precio: %d",diferenciaPrecios);
						printf("\n=================================================================================\n");
					}
					else
					{   //mensaje por si se intenta mostrar resultados sin antes haber permitido que se hicieran los calculos.
						printf("Error, antes de mostrar los resultados deben hacerse los calculos(Presione opción 3)");
					}
				break;

				case 5:
                //carga forzada - calculos y resultados
					precioAerolineas=162965;
					precioLatam=159339;
					kilometros=7090;
					tarjetaDebitoAerolineas=calcularDescuento(precioAerolineas,10);
					tarjetaCreditoAerolineas= calcularAumento(precioAerolineas,25);
					bitcoinAerolineas=dividir(valorBitcoin,precioAerolineas);
					precioUnitarioAerolineas=dividir(precioAerolineas,kilometros);

					tarjetaDebitoLatam= calcularDescuento(precioLatam,10);
					tarjetaCreditoLatam= calcularAumento(precioLatam,25);
					bitcoinLatam= dividir(valorBitcoin,precioLatam);
					precioUnitarioLatam=dividir(precioLatam,kilometros);

					resultado= restar(precioAerolineas,precioLatam);
					diferenciaPrecios=obtenerValorAbsoluto(resultado);

		        printf("\n=================================================================================\n");

		        printf("Kilometros ingresados: %d km\n\n",kilometros);
				printf("Precio vuelo Aerolineas: $ %d\n",precioAerolineas);
			    printf("a) Precio tarjeta de debito Aerolineas: $ %.2f\n",tarjetaDebitoAerolineas);
				printf("b) Precio tarjeta de credito Aerolineas: $ %.2f \n",tarjetaCreditoAerolineas);
				printf("c) Precio el precio en bitcoin Aerolineas: $ %f BTC\n",bitcoinAerolineas);
				printf("d) Precio el precio unitario de Aerolineas: $ %f \n\n",precioUnitarioAerolineas);

				printf("Precio vuelo Latam: $ %d\n",precioLatam);
				printf("a) Precio tarjeta de debito Latam: $ %.2f\n",tarjetaDebitoLatam);
				printf("b) Precio tarjeta de credito Latam: $ %.2f\n",tarjetaCreditoLatam);
				printf("c) Precio el precio en bitcoin Latam: $ %f BTC\n",bitcoinLatam);
				printf("d) Precio unitario de Latam: $ %f\n\n",precioUnitarioLatam);

				printf("La diferencia de precio: %d",diferenciaPrecios);
				printf("\n=================================================================================\n");

                break;
				case 6:
				printf("Adios\n");
				break;

				default:
				printf("Error, no ingreso una opcion correcta\n");
				break;

			}
            printf("\n\n");

		}while(opcion != 6);

	return EXIT_SUCCESS;
}

