/*
 * validaciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: PC-INC
 */
//CUERPO/DESARROLLO
#include <stdio.h>
#include <stdlib.h>
int pedirEnteroPositivo(char mensaje[],char error[])
{
    int numero;

    printf("%s",mensaje);
    scanf("%d", &numero);

    while(numero < 1)
    {
        printf("%s",error);
        scanf("%d", &numero);
    }

    return numero;
}
