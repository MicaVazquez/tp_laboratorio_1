/*
 * calculos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: PC-INC
 */

float calcularDescuento(int valor, int rebaja)
{
	float resultadoDescuento;

	 resultadoDescuento = valor - (valor*(float)rebaja/100);
	 return resultadoDescuento;
}

float calcularAumento(int valor , int recarga)
{
	float resultadoAumento;                                //CALCULOS
	resultadoAumento = valor + (valor*(float) recarga/100);
	return resultadoAumento;
}

float dividir(float dividendo, float divisor)
{
	float resultadoDivision;
	resultadoDivision = dividendo / divisor;

	return resultadoDivision;
}

int restar(int a, int b)
{
	int resta;
	resta = a - b;
	return resta;
}

int obtenerValorAbsoluto(int x)
{
	int resultado;
	if(x<0)
	{
		resultado=x*-1;
		return resultado;
	}
	return x;
}

