#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#define ARCHIVO_CSV "data.csv"
#define ARCHIVO_BINARIO "data.bin"
#define MSJ_MENU " Menu: "
#define MSJ_ERROR " [x] Error! No se puedo cargar el LinkedList!\n Intentelo mas tarde..."

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
 *****************************************************/

int main()
{
	setbuf(stdout, NULL);

	int option = 0;
	LinkedList* listaPasajeros = ll_newLinkedList();

	do{
		if(	utn_getInt(&option, MSJ_MENU, "Volviendo", 1, 10, 2) == 0 &&
			option > 0)
		{
			switch(option)
			{
			case 1: 	// CARGAR DATOS CON EXTENSION .CSV
				controller_loadFromText(ARCHIVO_CSV, listaPasajeros);
				break;
			case 2: 	// CARGAR DATOS CON EXTENSION .BIN O .DAT
				controller_loadFromBinary(ARCHIVO_BINARIO, listaPasajeros);
				break;
			case 3: 	// ALTA
				controller_addPassenger(listaPasajeros);
				break;
			case 4: 	// MODIFICACION
				controller_editPassenger(listaPasajeros);
				break;
			case 5: 	// BAJA
				controller_removePassenger(listaPasajeros);
				break;
			case 6: 	// LISTAR
				controller_ListPassenger(listaPasajeros);
				break;
			case 7: 	// ORDENAR
				controller_sortPassenger(listaPasajeros);
				break;
			case 8: 	// GUARDAR DATOS CON EXTENSION .CSV
				controller_saveAsText(ARCHIVO_CSV, listaPasajeros);
				break;
			case 9: 	// GUARDAR DATOS CON EXTENSION .BIN O .DAT
				controller_saveAsBinary(ARCHIVO_BINARIO, listaPasajeros);
				break;
			case 10: 	// SALIR
				printf(" Gracias! Vuelva prontos!");
				break;
			}
		}
		else
		{
			printf(MSJ_ERROR);
			break;
		}
	}while(option != 10);

	return 0;
}

