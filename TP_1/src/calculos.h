/*
 * calculos.h
 *
 *  Created on: 14 abr. 2022
 *      Author: PC-INC
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
/**
 * @brief La funcion recibe dos enteros.
 * El segundo va a dividirse por 100 para convertirlo al entero en decimal.
 * Luego el descuento convertido en decimal se multiplicara por el precio original o base.
 * Y el ultimo valor obtenido lo resta al precio original.
 *
 * @param valor precio original o base.
 * @param rebaja valor del descuento  que se quiere aplicar el precio original.
 * @return retorna el resultado en flotante.
 */
float calcularDescuento(int valor, int rebaja);




/**
 * @brief La funcion recibe dos enteros. El segundo entero que recibe lo convierte a decimal,
 *  luego lo multiplica por el primer entero. Y el ultimo valor obtenido lo suma al primer entero.
 *
 * @param valor precio original o base.
 * @param recarga valor del interes que se quiere aplicar el precio original.
 * @return retorna un flotante como resultado.
 */
float calcularAumento(int valor, int recarga);




/**
 * @brief Divide dos flotantes y retorna un flotante como resultado
 *
 * @param dividendo primer parametro que recibe un numero flotante.
 * @param divisor   segundo parametro que recibe otro numero flotante.
 * @return retorna un flotante como resultado.
 */
float dividir(float dividendo, float divisor);



/**
 * @brief La funcion resta dos enteros.
 *
 * @param a primer parametro que recibe un numero entero.
 * @param b segundo parametro que recibe un numero entero.
 * @return Devuelve el resultado de la resta como un entero.
 */
int restar(int a, int b);



/**
 * @brief La funcion recibe un entero y devuelve el valor absoluto del mismo.
 *
 * @param recibe el entero que va a ser multiplicado por -1 en caso que sea negativo y lo retorna.
 * @return retorna el valor absoluto de un entero.
 */
int obtenerValorAbsoluto(int x);



#endif /* CALCULOS_H_ */
