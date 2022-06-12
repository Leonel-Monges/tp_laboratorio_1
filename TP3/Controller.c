#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#define ARCHIVO_CSV "data.csv"
#define ARCHIVO_BINARIO "data.bin"

static int controller_printPassenger(LinkedList* pArrayListPassenger, int index)
{
	int retorno = -1;
	Passenger* pPassenger;
	Passenger auxPassenger;

	if(pArrayListPassenger != NULL && index >= 0)
	{
		pPassenger = (Passenger*) ll_get (pArrayListPassenger,index);
		if(	pPassenger != NULL &&
			Passenger_getId(pPassenger, &auxPassenger.id) &&
			Passenger_getNombre(pPassenger, auxPassenger.nombre) &&
			Passenger_getApellido(pPassenger, auxPassenger.apellido) &&
			Passenger_getPrecio(pPassenger, &auxPassenger.precio) &&
			Passenger_getCodigoVuelo(pPassenger, auxPassenger.codigoVuelo) &&
			Passenger_getTipoPasajero(pPassenger, &auxPassenger.tipoPasajero) &&
			Passenger_getEstadoVuelo(pPassenger, &auxPassenger.estadoVuelo)
			)
		{
			printf("\n | %4d | %15s | %15s | $ %.2f | %s | %d | %d |",
					auxPassenger.id,
					auxPassenger.nombre,
					auxPassenger.apellido,
					auxPassenger.precio,
					auxPassenger.codigoVuelo,
					auxPassenger.tipoPasajero,
					auxPassenger.estadoVuelo);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			parser_PassengerFromText(pFile, pArrayListPassenger);
			fclose(pFile);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int len = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL)
	{
//		printf("\n |  ID  |       NAME      |  HS WK  |   SALARY  |\n");
//		printf(" |------|-----------------|---------|-----------|");
		for(int i = 0; i < len; i++)
		{
			controller_printPassenger(pArrayListPassenger, i);
		}
	}

	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

