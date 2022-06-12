/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#define LEN_VALIDACION 30
#define LEN_AUX 64
#define SI 1
#define NO 0
#define ERROR -1
#define OK 0

static int isValidId(int id);
static int isValidTipoPasajero(int tipoPasajero);
static int isValidPrecio(float precio);
static int isValidEstadoVuelo(int estadoVuelo);

/**
 * @fn int isValidId(int)
 * @brief Valida el atributo id de la entidad Passenger.
 *
 * @param id: Campo a validar.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
static int isValidId(int id)
{
	int retorno = NO;
	char auxId[LEN_AUX];

	if(id >= 0)
	{
		sprintf(auxId, "%d", id); // Formateado a cadena.
		if(esNumerica(auxId, LEN_AUX) == SI)
		{
			retorno = SI;
		}
	}

	return retorno;
}

/**
 * @fn int isValidTipoPasajero(int)
 * @brief Valida el atributo tipoPasajero de la entidad Passenger.
 *
 * @param tipoPasajero: Campo a validar.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
static int isValidTipoPasajero(int tipoPasajero)
{
	int retorno = NO;
	char auxTipoPasajero[LEN_AUX];

	if(tipoPasajero >= 0)
	{
		sprintf(auxTipoPasajero, "%d", tipoPasajero); // Formateado a cadena.
		if(esNumerica(auxTipoPasajero, LEN_AUX) == SI)
		{
			retorno = SI;
		}
	}

	return retorno;
}

/**
 * @fn int isValidPrecio(float)
 * @brief Valida el atributo precio de la entidad Passenger.
 *
 * @param precio: Campo a validar.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
static int isValidPrecio(float precio)
{
	int retorno = NO;
	char auxPrecio[LEN_AUX];

	if(precio > 0)
	{
		sprintf(auxPrecio, "%.2f", precio); // Formateado a cadena.
		if(esFlotante(auxPrecio, LEN_AUX) == SI)
		{
			retorno = SI;
		}
	}

	return retorno;
}

/**
 * @fn int isValidEstadoVuelo(int)
 * @brief Valida el atributo estadoVuelo de la entidad Passenger.
 *
 * @param estadoVuelo: Campo a validar.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
static int isValidEstadoVuelo(int estadoVuelo)
{
	int retorno = NO;
	char auxEstadoVuelo[LEN_AUX];

	if(auxEstadoVuelo >= 0)
	{
		sprintf(auxEstadoVuelo, "%d", estadoVuelo); // Formateado a cadena.
		if(esNumerica(auxEstadoVuelo, LEN_AUX) == SI)
		{
			retorno = SI;
		}
	}

	return retorno;
}

// -------------------------------------------------------------------------------- //
// Contructor & Destructor


/**
 * @fn Passenger Passenger_new*()
 * @brief Reserva un espacio de memoria para un elemento de la entidad Passenger.
 *
 * @return El puntero del tipo de dato estructura Passenger.
 */
Passenger* Passenger_new()
{
	return (Passenger*) malloc (sizeof(Passenger));
}

/**
 * @fn void Passenger_delete(Passenger*)
 * @brief Libera el espacio de memoria de los datos del tipo Passenger.
 *
 * @param this: Es el puntero de contexto del tipo de dato estructura Passenger.
 */
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
 * @fn Passenger Passenger_newParametros*(int, char*, char*, float, int, int, int)
 * @brief
 *
 * @param id:
 * @param nombre:
 * @param apellido:
 * @param precio:
 * @param codigoVuelo:
 * @param tipoPasajero:
 * @param estadoVuelo:
 * @return
 */
Passenger* Passenger_newParametros(
		int id,
		char* nombre,
		char* apellido,
		float precio,
		char* codigoVuelo,
		int tipoPasajero,
		int estadoVuelo)
{
	Passenger* this = Passenger_new();

	if(this != NULL)
	{
		if(
			Passenger_setId(this, id) 						== OK &&
			Passenger_setNombre(this, nombre) 				== OK &&
			Passenger_setApellido(this, apellido) 			== OK &&
			Passenger_setPrecio(this, precio) 				== OK &&
			Passenger_setCodigoVuelo(this, codigoVuelo) 	== OK &&
			Passenger_setTipoPasajero(this, tipoPasajero) 	== OK &&
			Passenger_setEstadoVuelo(this, estadoVuelo) 	== OK
		)
		{
			return this;
		}
	}

	return NULL;
}

/**
 * @fn Passenger Passenger_newParametrosStr*(char*, char*, char*, char*, char*, char*, char*)
 * @brief
 *
 * @param idStr:
 * @param nombreStr:
 * @param apellidoStr:
 * @param precioStr:
 * @param codigoVueloStr:
 * @param tipoPasajeroStr:
 * @param estadoVueloStr:
 * @return
 */
Passenger* Passenger_newParametrosStr(
		char* idStr,
		char* nombreStr,
		char* apellidoStr,
		char* precioStr,
		char* codigoVueloStr,
		char* tipoPasajeroStr,
		char* estadoVueloStr)
{
	Passenger* this = Passenger_new();

	if(this != NULL)
	{
		if(
			Passenger_setIdStr(this, idStr) 					== OK &&
			Passenger_setNombre(this, nombreStr) 				== OK &&
			Passenger_setApellido(this, apellidoStr) 			== OK &&
			Passenger_setPrecioStr(this, precioStr)				== OK &&
			Passenger_setCodigoVuelo(this, codigoVueloStr) 		== OK &&
			Passenger_setTipoPasajeroStr(this, tipoPasajeroStr) == OK &&
			Passenger_setEstadoVueloStr(this, estadoVueloStr) 	== OK
		)
		{
			return this;
		}
	}

	return NULL;
}

// -------------------------------------------------------------------------------- //
// Setters y Getters


// ~ Campo id

/**
 * @fn int Passenger_setId(Passenger*, int)
 * @brief
 *
 * @param this
 * @param id
 * @return
 */
int Passenger_setId(Passenger* this, int id)
{
	int retorno = ERROR;

	if(	this != NULL &&
		id >= 0 &&
		isValidId(id) == SI)
	{
		this->id = id;
		retorno = OK;
	}

	return retorno;
}

/**
 * @fn int Passenger_setIdStr(Passenger*, char*)
 * @brief
 *
 * @param this
 * @param id
 * @return
 */
int Passenger_setIdStr(Passenger* this, char* id)
{
	int retorno = ERROR;

	if(	this != NULL &&
		id != NULL &&
		id >= 0 &&
		esNumerica(id, LEN_AUX) == SI)
	{
		this->id = atoi(id); // Casteo del dato para su respectiva asignacion
		retorno = OK;
	}

	return retorno;
}

/**
 * @fn int Passenger_getId(Passenger*, int*)
 * @brief
 *
 * @param this:
 * @param id:
 * @return
 */
int Passenger_getId(Passenger* this, int* id)
{
	int retorno = ERROR;

	if(	this != NULL &&
		id >= 0)
	{
		*id = this->id; // Asigno al puntero de dicho campo el valor original
		retorno = OK;
	}

	return retorno;
}

/**
 * @fn int Passenger_getIdStr(Passenger*, char*)
 * @brief
 *
 * @param this:
 * @param id:
 * @return
 */
int Passenger_getIdStr(Passenger* this, char* id)
{
	int retorno = ERROR;

	if(	this != NULL &&
		id >= 0)
	{
		snprintf(id, (int)sizeof(this->id), "%d", this->id); // Formateado a cadena segura.
		retorno = OK;
	}

	return retorno;
}


// ~ Campo nombre

int Passenger_setNombre(Passenger* this, char* nombre)
{
	int retorno = ERROR;

	if(	this != NULL &&
		nombre != NULL &&
		esNombreValido(nombre, LEN_AUX) == SI)
	{
//		nombre = toupper(nombre[0]);
		strncpy(this->nombre, nombre, LEN_AUX);
		retorno = OK;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
	int retorno = ERROR;

	if(	this != NULL &&
		nombre != NULL)
	{
		strncpy(nombre, this->nombre, LEN_AUX);
		retorno = OK;
	}

	return retorno;
}


// ~ Campo apellido

int Passenger_setApellido(Passenger* this, char* apellido)
{
	int retorno = ERROR;

	if(	this != NULL &&
		apellido != NULL &&
		esNombreValido(apellido, LEN_AUX) == SI)
	{
//		apellido = toupper(apellido[0]);
		strncpy(this->apellido, apellido, LEN_AUX);
		retorno = OK;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this, char* apellido)
{
	int retorno = ERROR;

	if(	this != NULL &&
		apellido != NULL)
	{
		strncpy(apellido, this->apellido, LEN_AUX);
		retorno = OK;
	}

	return retorno;
}


// ~ Campo precio

/**
 * @fn int Passenger_setPrecio(Passenger*, float)
 * @brief
 *
 * @param this:
 * @param precio:
 * @return
 */
int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno = ERROR;

	if(	this != NULL &&
		precio >= 0 &&
		isValidPrecio(precio) == SI)
	{
		this->precio = precio;
		retorno = OK;
	}

	return retorno;
}

/**
 * @fn int Passenger_setPrecioStr(Passenger*, char*)
 * @brief
 *
 * @param this:
 * @param precio:
 * @return
 */
int Passenger_setPrecioStr(Passenger* this, char* precio)
{
	int retorno = ERROR;

	if(	this != NULL &&
		precio != NULL &&
		precio >= 0 &&
		esFlotante(precio, LEN_AUX) == SI)
	{
		this->precio = atof(precio); // Casteo del dato para su respectiva asignacion
		retorno = OK;
	}

	return retorno;
}

/**
 * @fn int Passenger_getPrecio(Passenger*, float*)
 * @brief
 *
 * @param this:
 * @param precio:
 * @return
 */
int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno = ERROR;

	if(	this != NULL &&
		precio >= 0)
	{
		*precio = this->precio; // Asigno al puntero de dicho campo el valor original
		retorno = OK;
	}

	return retorno;
}

/**
 * @fn int Passenger_getPrecioStr(Passenger*, char*)
 * @brief
 *
 * @param this:
 * @param precio:
 * @return
 */
int Passenger_getPrecioStr(Passenger* this, char* precio)
{
	int retorno = ERROR;

	if(	this != NULL &&
		precio >= 0)
	{
		snprintf(precio, (int)sizeof(this->precio), "%.2f", this->precio); // Formateado a cadena segura.
		retorno = OK;
	}

	return retorno;
}


// ~ Campo codigoVuelo

/**
 * @fn int Passenger_setCodigoVuelo(Passenger*, char*)
 * @brief
 *
 * @param this:
 * @param codigoVuelo:
 * @return
 */
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno = ERROR;

	if(	this != NULL &&
		codigoVuelo != NULL &&
		esAlfaNumerico(codigoVuelo, LEN_AUX) == SI)
	{
		strncpy(this->codigoVuelo, codigoVuelo, LEN_AUX);
		retorno = OK;
	}

	return retorno;
}

/**
 * @fn int Passenger_getCodigoVuelo(Passenger*, char*)
 * @brief
 *
 * @param this:
 * @param codigoVuelo:
 * @return
 */
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno = ERROR;

	if(	this != NULL &&
		codigoVuelo != NULL)
	{
		strncpy(codigoVuelo, this->codigoVuelo, LEN_AUX);
		retorno = OK;
	}

	return retorno;
}


// ~ Campo tipoPasajero

/** @fn int Passenger_setId(Passenger*, int)
* @brief
*
* @param this:
* @param tipoPasajero:
* @return
*/
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int retorno = ERROR;

	if(	this != NULL &&
		tipoPasajero >= 0 &&
		isValidTipoPasajero(tipoPasajero) == SI)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = OK;
	}

	return retorno;
}

/**
* @fn int Passenger_setTipoPasajeroStr(Passenger*, char*)
* @brief
*
* @param this:
* @param tipoPasajero:
* @return
*/
int Passenger_setTipoPasajeroStr(Passenger* this, char* tipoPasajero)
{
	int retorno = ERROR;

	if(	this != NULL &&
		tipoPasajero != NULL &&
		tipoPasajero >= 0 &&
		esNumerica(tipoPasajero, LEN_AUX) == SI)
	{
		this->id = atoi(tipoPasajero); // Casteo del dato para su respectiva asignacion
		retorno = OK;
	}

	return retorno;
}

/**
* @fn int Passenger_getTipoPasajero(Passenger*, int*)
* @brief
*
* @param this:
* @param tipoPasajero:
* @return
*/
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int retorno = ERROR;

	if(	this != NULL &&
		tipoPasajero >= 0)
	{
		*tipoPasajero = this->tipoPasajero; // Asigno al puntero de dicho campo el valor original
		retorno = OK;
	}

	return retorno;
}

/**
* @fn int Passenger_getTipoPasajeroStr(Passenger*, char*)
* @brief
*
* @param this:
* @param tipoPasajero:
* @return
*/
int Passenger_getTipoPasajeroStr(Passenger* this, char* tipoPasajero)
{
	int retorno = ERROR;

	if(	this != NULL &&
		tipoPasajero >= 0)
	{
		snprintf(tipoPasajero, (int)sizeof(this->tipoPasajero), "%d", this->tipoPasajero); // Formateado a cadena segura.
		retorno = OK;
	}

	return retorno;
}


// ~ Campo estadoVuelo

/** @fn int Passenger_setEstadoVuelo(Passenger*, int)
* @brief
*
* @param this:
* @param estadoVuelo:
* @return
*/
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	int retorno = ERROR;

	if(	this != NULL &&
		estadoVuelo >= 0 &&
		isValidEstadoVuelo(estadoVuelo) == SI)
	{
		this->estadoVuelo = estadoVuelo;
		retorno = OK;
	}

	return retorno;
}

/**
* @fn int Passenger_setEstadoVueloStr(Passenger*, char*)
* @brief
*
* @param this:
* @param estadoVuelo:
* @return
*/
int Passenger_setEstadoVueloStr(Passenger* this, char* estadoVuelo)
{
	int retorno = ERROR;

	if(	this != NULL &&
		estadoVuelo != NULL &&
		estadoVuelo >= 0 &&
		esNumerica(estadoVuelo, LEN_AUX) == SI)
	{
		this->estadoVuelo = atoi(estadoVuelo); // Casteo del dato para su respectiva asignacion
		retorno = OK;
	}

	return retorno;
}

/**
* @fn int Passenger_getEstadoVuelo(Passenger*, int*)
* @brief
*
* @param this:
* @param estadoVuelo:
* @return
*/
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int retorno = ERROR;

	if(	this != NULL &&
		estadoVuelo >= 0)
	{
		*estadoVuelo = this->estadoVuelo; // Asigno al puntero de dicho campo el valor original
		retorno = OK;
	}

	return retorno;
}

/**
* @fn int Passenger_getTipoPasajeroStr(Passenger*, char*)
* @brief
*
* @param this:
* @param tipoPasajero:
* @return
*/
int Passenger_getEstadoVueloStr(Passenger* this, char* estadoVuelo)
{
	int retorno = ERROR;

	if(	this != NULL &&
		estadoVuelo >= 0)
	{
		snprintf(estadoVuelo, (int)sizeof(this->estadoVuelo), "%d", this->estadoVuelo); // Formateado a cadena segura.
		retorno = OK;
	}

	return retorno;
}

