/*
 * validaciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: PC-INC
 */
//CUERPO/DESARROLLO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void getString(char mensaje[],char input[],int tamMin,int tamMax)
{
    int i;
    int retorno;

    do
    {
        retorno=1;
        printf(mensaje);
        fflush(stdin);
        gets(input);

        if(strlen(input)>=tamMin && strlen(input)<=tamMax)
        {
            for(i=0; i<strlen(input); i++)
            {
                if((input[i]<'a' || input[i]>'z') && (input[i]<'A' || input[i]>'Z')&& (input[i] != ' '))
                {
                    retorno=0;
                    break;
                }
            }

        }

        if(retorno==0)
        {
            printf("error\n");
        }

    }
    while(retorno==0);
}



void getInt(char mensaje[],int *numero,int tamMin,int tamMax)
{
    char ingreso[50];
    int retorno=0;
    int flag=1;
    int auxiliar=0;
    int i;

    do
    {
        printf(mensaje);
        fflush(stdin);
        gets(ingreso);

            for(i=0;i<=strlen(ingreso);i++)
            {
                if(ingreso[i]=='.')
                {
                    flag=0;
                    break;
                }
            }

            auxiliar=atoi(ingreso);

            if(auxiliar>=tamMin && auxiliar<=tamMax && flag==1)
            {
                *numero=auxiliar;
                retorno=1;

            }

        if(retorno==0)
            {
                printf("error\n");
            }


    }while(retorno==0);


}



void getFloat(char mensaje[],float *numero,float tamMin,float tamMax)
{
    char ingreso[50];
    int retorno=0;
    int flag=0;
    float auxiliar;
    int i;



    do
    {
        printf(mensaje);
        fflush(stdin);
        gets(ingreso);

        for(i=0;i<=strlen(ingreso);i++)
        {
            if(ingreso[i]=='.')
            {
                flag++;

                if(flag==2)
                {
                    break;
                }
            }
        }

        auxiliar=atof(ingreso);

        if(auxiliar>=tamMin && auxiliar<=tamMax &&flag!=2)
        {
            *numero=auxiliar;
            retorno=1;

        }
        if(retorno==0)
        {
            printf("error\n");
        }


    }while(retorno==0);

}

void getLetrasYNumeros(char mensaje[],char input[],int tamMin,int tamMax)
{
    int i;
    int retorno=0;

    do
    {

        printf(mensaje);
        fflush(stdin);
        gets(input);

        if(strlen(input)>=tamMin && strlen(input)<=tamMax)
        {
            for(i=0;i<strlen(input);i++)
            {
                if((input[i]<'a' || input[i]>'z') && (input[i]<'A' || input[i]>'Z') && (input[i]<'0' || input[i]>'9'))
                {
                    retorno=0;
                    break;
                }
                else
                {
                    retorno=1;
                }
            }

        }


        if(retorno==0)
        {
            printf("error\n");
        }

    }while(retorno==0);
}

static int esNumerica(char* cadena, int limite);
static int getIntt(int* pResultado);




/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un maximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getIntt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	myGets(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = 1; // VERDADERO
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;		}
		//CONTINUE
	}
	//BREAK
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
void getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno = -1;
	int bufferInt;


    if(pResultado != NULL && mensaje != NULL && mensaje != NULL && minimo <= maximo)
    {
		do
		{
			printf("%s",mensaje);
			if(	getIntt(&bufferInt) == 0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			printf("%s",mensajeError);

		}while(retorno==-1);
    }

}
