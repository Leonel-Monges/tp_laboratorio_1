/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "validaciones.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[4];
	int tipoPasajero;
	int estadoVuelo;
//	int isEmpty;
} Passenger;

Passenger* Passenger_new();
//Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr);
Passenger* Passenger_newParametros(
		int id,
		char* nombre,
		char* apellido,
		float precio,
		char* codigoVuelo,
		int tipoPasajero,
		int estadoVuelo);

Passenger* Passenger_newParametrosStr(
		char* idStr,
		char* nombreStr,
		char* apellidoStr,
		char* precioStr,
		char* codigoVueloStr,
		char* tipoPasajeroStr,
		char* estadoVueloStr);

void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);
int Passenger_setIdStr(Passenger* this, char* id);
int Passenger_getIdStr(Passenger* this, char* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);
int Passenger_setPrecioStr(Passenger* this, char* precio);
int Passenger_getPrecioStr(Passenger* this, char* precio);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);
int Passenger_setTipoPasajeroStr(Passenger* this, char* tipoPasajero);
int Passenger_getTipoPasajeroStr(Passenger* this, char* tipoPasajero);

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);
int Passenger_setEstadoVueloStr(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVueloStr(Passenger* this, char* estadoVuelo);

#endif /* PASSENGER_H_ */
