/*
 * validaciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: PC-INC
 */
//PROTOTIPO/FIRMA
#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
/**
 * @brief La funcion pide un entero positivo y valida que sea mayor que 0.
 *
 * @param mensaje  Mensaje para que el usuario sepa que ingresar.
 * @param input    Lo que se ingresa.
 * @return         Devuelve un entero.
 */
void getString(char mensaje[],char input[],int tamMin,int tamMax);

/**
 * @brief la funcion pide una cadena de caracteres y valida que no se ingresen numeros.
 *
 * @param mensaje  Mensaje para que el usuario sepa que ingresar.
 * @param numero   direccion de memoria de la varible
 * @param tamMin
 * @param tamMax
 */
void getInt(char mensaje[],int *numero,int tamMin,int tamMax);

/**
 * @brief la funcion pide un entero
 *
 * @param mensaje Mensaje para que el usuario sepa que ingresar.
 * @param numero
 * @param tamMin
 * @param tamMax
 */
void getFloat(char mensaje[],float *numero,float tamMin,float tamMax);





/**
 * @brief la funcion pide letras y numeros
 *
 * @param mensaje Mensaje para que el usuario sepa que ingresar.
 * @param input lo que ingresa el usuario.
 * @param tamMin
 * @param tamMax
 */
void getLetrasYNumeros(char mensaje[],char input[],int tamMin,int tamMax);

/**
 * @brief Solicita el numero al usuario, luego de verificar le devulve el resultado
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado.
 * @param minimo Es el numero minimo a ser aceptado
 * @param maximo Es el numero maximo a ser aceptado
 * @param reintentos
 * @return Retorna 0 si se obtuvo el numero y -1 si no
 */
void getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);



int myGets(char* cadena, int longitud);

#endif /* VALIDACIONES_H_ */
