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
 * @param error    Mensaje para que reingrese.
 * @return         Devuelve un entero.
 */

int pedirEnteroPositivo(char mensaje[],char error[]);

#endif /* VALIDACIONES_H_ */
