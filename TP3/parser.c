#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#define LEN_CAMPOS 256

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int lectura;

	Passenger* pPassenger;
	char campoId[LEN_CAMPOS];
	char campoNombre[LEN_CAMPOS];
	char campoApellido[LEN_CAMPOS];
	char campoPrecio[LEN_CAMPOS];
	char campoTipoPasajero[LEN_CAMPOS];
	char campoCodigoVuelo[LEN_CAMPOS];
	char campoEstadoVuelo[LEN_CAMPOS];

	do
	{
		lectura = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				campoId,
				campoNombre,
				campoApellido,
				campoPrecio,
				campoCodigoVuelo,
				campoTipoPasajero,
				campoEstadoVuelo);

		if(lectura == 6)
		{
			pPassenger = Passenger_newParametrosStr(
					campoId,
					campoNombre,
					campoApellido,
					campoPrecio,
					campoCodigoVuelo,
					campoTipoPasajero,
					campoEstadoVuelo);

			if(pPassenger != NULL)
			{
				ll_add(pArrayListPassenger, pPassenger);
				retorno = 0;
				printf("llego hasta aca");
			}
		}
		else
		{
			break; // No se pudo leer.
		}
	}while(!feof(pFile));

	fclose(pFile);  // Cierre de archivo

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
    return 1;
}
