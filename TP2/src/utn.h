/*
 * utn.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Sistemas4
 */

#ifndef UTN_H_
#define UTN_H_

#define REINTENTOS 2
#define ERROR_MSJ " [x] Error!\n"
#define ERROR_MSJ_SOLO_NUMEROS " [x] Error! Se admite solo numeros!\n"
#define ERROR_REINTENTOS "\n [!] Lo sentimos! Intentelo mas tarde...\n <<< Redireccionando al menu principal...\n"
#define MSJ_ERROR_SOLO_SI_O_NO "[!] Error! Se admite solo ingresar s/S o n/N!\n"
#define LIMITE_BUFFER_STRING 2048

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char rangoInicial, char rangoFinal, int reintentos);
int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int limite, int reintentos);
int utn_getAlfaNumerico(char* pResultado, char* mensaje, char* mensajeError, int limite, int reintentos);
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int limite, int reintentos);
int utn_getPorcentaje(float* pResultado, float valorIngresado, float porcentaje, int opcion);
int utn_calcularOperacion(float* pResultado, float numero1, float numero2, int opcionOperacion);

#endif /* UTN_H_ */
