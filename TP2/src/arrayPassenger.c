/*
 * arrayPassenger.c
 *
 *  Created on: 28 abr. 2022
 *      Author: Sistemas4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayPassenger.h"
#include "utn.h"

// Added Functions
static void printPassenger(Passenger aPassenger);
static int searchFreeIndex(Passenger* list, int len);
static void printHeadListPassenger();
static int autoincrementarIdPassenger();

static void hardcode(Passenger* list, int len);
static int modifyPassenger(Passenger* list, int len);

static void hardcode(Passenger* list, int len)
{
	int idAux;
	for(int i = 0; i < len; i++)
	{
		idAux = autoincrementarIdPassenger();
		addPassenger(list, len, idAux, "Cosme", "Fulanito", 999999, 1, "asd123");
	}
}

/**
 * @fn void printPassenger(Passenger)
 * @brief
 *
 * @param aPassenger
 */
static void printPassenger(Passenger aPassenger)
{
//	char printStatusFlight[];
//
//	if(aPassenger.statusFlight == 1)
//	{
//		printStatusFlight = {"ACTIVE"};
//	}
//	else
//	{
//		printStatusFlight = {"INACTIVE"};
//	}

	if(aPassenger.isEmpty == 0)
	{
		printf("| %6d | %15s | %15s | $ %.2f | %7s | %14d | %13d |\n",
				aPassenger.id,
				aPassenger.name,
				aPassenger.lastName,
				aPassenger.price,
				aPassenger.flycode,
				aPassenger.typePassenger,
				aPassenger.statusFlight);
	}
}

/**
 * @fn int searchFreeIndex(Passenger*, int)
 * @brief
 *
 * @param list
 * @param len
 * @return
 */
static int searchFreeIndex(Passenger* list, int len)
{
	int returnValue = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				returnValue = i;
				break;
			}
		}
	}

	return returnValue;
}

/**
 * @fn void printHeadListPassenger()
 * @brief
 *
 */
static void printHeadListPassenger()
{
	printf("\n| %6s | %15s | %15s | %11s | %6s | %2s | %2s |\n",
			PRINT_HEAD_LIST_ID,
			PRINT_HEAD_LIST_NAME,
			PRINT_HEAD_LIST_LASTNAME,
			PRINT_HEAD_LIST_PRICE,
			PRINT_HEAD_LIST_FLYCODE,
			PRINT_HEAD_LIST_TYPEPASSENGER,
			PRINT_HEAD_LIST_STATUSFLIGHT);
	printf(PRINT_HEAD_SEPARATOR);
}

/**
 * @fn int autoincrementarIdPassenger()
 * @brief
 *
 * @return
 */
static int autoincrementarIdPassenger()
{
	static int valor = 1000;
	valor++;
	return valor;
}


static int modifyPassenger(Passenger* list, int len)
{
	int returnValue = -1;
	Passenger auxPassenger;
	int index;
	int option;

	if(	utn_getInt(&auxPassenger.id,
		" > Enter the id of the passenger to modify: ",
		MSG_ERROR, 1000, 1999, RETRIES) == 0)
	{
		index = findPassengerById(list, len, auxPassenger.id);
		if(index != -1)
		{
			printHeadListPassenger();
			printPassenger(list[index]);
			if(	utn_getInt(&option,
				"\n > Do you want to modify the data of this user?\n   1. YES\n   2. NO\n\n > Enter option: ",
				MSG_ERROR, 1, 2, RETRIES) == 0)
			{
				if(option == 1) // YES
				{
					if(utn_getInt(&option, "\n   Select the data to modify:\n\n    1. Name\n    2. LastName\n    3. Price\n    4. Type Passenger\n    5. FlyCode\n\n   > Enter option: ", MSG_ERROR, 1, 5, REINTENTOS)  == 0)
					{
						switch(option)
						{
							case 1: // Name
								if(utn_getNombre(auxPassenger.name, " > Enter your name: ", MSG_ERROR, 15, RETRIES) == 0)
								{
									strcpy(list[index].name, auxPassenger.name);
									printf(MSG_UPDATED_DATA);
								}
								else
								{
									printf(MSG_ERROR_MAINMENU);
								}
								break;
							case 2: // Last name
								if(utn_getNombre(auxPassenger.lastName, " > Enter your last name: ", MSG_ERROR, 15, RETRIES) == 0)
								{
									strcpy(list[index].lastName, auxPassenger.lastName);
									printf(MSG_UPDATED_DATA);
								}
								else
								{
									printf(MSG_ERROR_MAINMENU);
								}
								break;
							case 3: // Price
								if(utn_getFloat(&auxPassenger.price, " > Enter the price of the flight: ", MSG_ERROR, 10000, 999999, RETRIES) == 0)
								{
									list[index].price = auxPassenger.price;
									printf(MSG_UPDATED_DATA);
								}
								else
								{
									printf(MSG_ERROR_MAINMENU);
								}
								break;
							case 4: // Type Passenger
								if(utn_getInt(&auxPassenger.typePassenger, " > Enter the passenger category: ", MSG_ERROR, 1, 4, RETRIES) == 0)
								{
									list[index].typePassenger = auxPassenger.typePassenger;
									printf(MSG_UPDATED_DATA);
								}
								else
								{
									printf(MSG_ERROR_MAINMENU);
								}
								break;
							case 5: // FlyCode
								if(utn_getString(auxPassenger.flycode, " > Enter the flycode: ", MSG_ERROR, 6, RETRIES) == 0)
								{
									strcpy(list[index].flycode, auxPassenger.flycode);
									printf(MSG_UPDATED_DATA);
								}
								else
								{
									printf(MSG_ERROR_MAINMENU);
								}
								break;
						}
					}
					else
					{
						printf(MSG_ERROR_MAINMENU);
					}
				}
				else
				{
					returnValue = 2; // NO
				}
			}
		}
		else
		{
			printf(" [x] Error! Passenger id not found!\n <<< Redirecting to main menu...\n");
		}
	}

	return returnValue;
}


int mainMenu(void)
{
	int returnValue = -1;
	Passenger listPassengers[LEN_PASSENGERS];
	Passenger auxPassenger;
	int option;
	int answerYorN;

	initPassengers(listPassengers, LEN_PASSENGERS);
	hardcode(listPassengers, 5);

	do
	{
		utn_getInt(&option, MSG_REQUESTDATA, MSG_ERROR, 1, 5, REINTENTOS);
		switch(option)
		{
			case 1: // ALTA REALIZADA
				if(	utn_getNombre(auxPassenger.name, " > Enter your name: ", MSG_ERROR, 15, RETRIES) == 0 &&
					utn_getNombre(auxPassenger.lastName," > Enter your last name: ", MSG_ERROR, 15, RETRIES) == 0 &&
					utn_getFloat(&auxPassenger.price, " > Enter the price of the flight: ", MSG_ERROR, 10000, 999999, RETRIES) == 0 &&
					utn_getString(auxPassenger.flycode, " > Enter the flycode: ", MSG_ERROR, 6, RETRIES) == 0 &&
					utn_getInt(&auxPassenger.typePassenger, " > Enter the passenger category: ", MSG_ERROR, 1, 4, RETRIES) == 0)
				{
					auxPassenger.id = autoincrementarIdPassenger();
					addPassenger(listPassengers, LEN_PASSENGERS,
							auxPassenger.id,
							auxPassenger.name,
							auxPassenger.lastName,
							auxPassenger.price,
							auxPassenger.typePassenger,
							auxPassenger.flycode);
					printPassengers(listPassengers, LEN_PASSENGERS);
				}
				else
				{
					printf(MSG_ERROR_MAINMENU);
				}
				break;
			case 2: // MODIFICACION REALIZADO
				printPassengers(listPassengers, LEN_PASSENGERS);
				modifyPassenger(listPassengers, LEN_PASSENGERS);
				break;
			case 3: // BAJAS REALIZADO
				printPassengers(listPassengers, LEN_PASSENGERS);
				if(utn_getInt(&auxPassenger.id, "\n > Enter the id of the passenger to delete: ", MSG_ERROR, 1000, 1999, RETRIES) == 0)
				{
					answerYorN = removePassenger(listPassengers, LEN_PASSENGERS, auxPassenger.id);
					if(answerYorN == 1)
					{
						printf(" OK! The data was deleted!\n");
					}
					else if(answerYorN == 2)
					{
						printf(" OK! The data was not deleted!\n");
					}
				}
				else
				{
					printf(MSG_ERROR_MAINMENU);
				}
				break;
			case 4: // INFORMES INCOMPLETO
				printPassengers(listPassengers, LEN_PASSENGERS);
				break;
		}

	}while(option != 5);

	return returnValue;
}

/**
 * @fn int initPassengers(Passenger*, int)
 * @brief To indicate that all position in the array empty,
 * 		  this function put the flag (isEmpty) in TRUE in all
 * 		  position of the array.
 *
 * @param list Passenger* Pointer to array of passenger.
 * @param len Array lenght
 * @return (-1) if Error [Invalid lenght or NULL pointer] - (0) if Ok.
 */
int initPassengers(Passenger* list, int len)
{
	int returnValue = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
			returnValue = 0;
		}
	}

	return returnValue;
}

/**
 * @fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[])
 * @brief Add in a existing list of passengers the values received as parameters
 * 		  in the first empty position.
 *
 * @param list Passenger*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param price float
 * @param typePassenger int
 * @param flycode char
 * @return (-1) if Error [Invalid lenght of NULL pointer or without free space] - (0) if Ok.
 */
int addPassenger(Passenger* list, int len, int id,
			char name[], char lastName[], float price,
			int typePassenger, char flycode[])
{
	int returnValue = -1;
	int freeIndex;

	if(list != NULL && len > 0)
	{
		freeIndex = searchFreeIndex(list, len);
		if(freeIndex != -1)
		{
			list[freeIndex].id = id;
			strcpy(list[freeIndex].name, name);
			strcpy(list[freeIndex].lastName, lastName);
			list[freeIndex].price = price;
			list[freeIndex].typePassenger = typePassenger;
			strcpy(list[freeIndex].flycode, flycode);
			list[freeIndex].statusFlight = STATUS_ACTIVE;
			list[freeIndex].statusFlight = 1;
			list[freeIndex].isEmpty = 0;
			returnValue = 0;
		}
	}

	return returnValue;
}

/**
 * @fn int findPassengerById(Passenger*, int, int)
 * @brief find a Passenger by Id and returns the index position in array
 *
 * @param list Passenger*
 * @param len int
 * @param id int
 * @return Passenger index position of (-1)
 * 		   if [Invalid lenght of NULL pointer received of passenger not found]
 */
int findPassengerById(Passenger* list, int len, int id)
{
	int returnValue = -1;

	if(list != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				returnValue = i;
				break;
			}
		}
	}

	return returnValue;
}

/**
 * @fn int removePassenger(Passenger*, int, int)
 * @brief Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * @param list Passenger*
 * @param len int
 * @param id int
 * @return Return (-1) if Error [Invalid length or NULL pointer or if can't
 * 		   find a passenger] - (0) if Ok.
 */
int removePassenger(Passenger* list, int len, int id)
{
	int returnValue = -1;
	int optionYorN;
	int index = -1;

	if(list != NULL && len > 0 && id > 0)
	{
		index = findPassengerById(list, len, id);
		if(index != -1)
		{
			printHeadListPassenger();
			printPassenger(list[index]);
			if(	utn_getInt(&optionYorN,
				"\n > Do you want to delete the found user?\n   . 1 = YES\n   . 2 = NO\n\n > Enter option: ",
				MSG_ERROR, 1, 2, RETRIES) == 0)
			{
				if(optionYorN == 1) // YES
				{
					list[index].isEmpty = 1;
					returnValue = 1;
				}
				else
				{
					returnValue = 2; // NO
				}
			}
		}
		else
		{
			printf(" [x] Error! Passenger id not found!\n <<< Redirecting to main menu...\n");
		}
	}

	return returnValue;
}

// FALTA
/**
 * @fn int sortPassenger(Passenger*, int, int)
 * @brief Sort the elements in the array of passengers, the argument order
	      indicate UP or DOWN order
 *
 * @param list Passenger*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 */
int sortPassenger(Passenger* list, int len, int order)
{
	int returnValue = -1;
	int i;
	Passenger aux;
	int isOrdered;

	if (list != NULL && len > 0)
	{
		do
		{
			isOrdered = 1;
			len--;
			for (i = 0; i < len; i++)
			{
				if(strcmp(list[i].lastName, list[i + 1].lastName) < 0)
				{
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					isOrdered = 0;
				}
				else if(strcmp(list[i].lastName, list[i + 1].lastName) == 0 &&
						list[i].typePassenger < list[i + 1].typePassenger)
				{
					list[i] = list[i + 1];
					list[i + 1] = aux;
					isOrdered = 0;
				}
			}
		}while (isOrdered == 0);
		returnValue = 0;
	}

	return returnValue;
}

/**
 * @fn int printPassengers(Passenger*, int)
 * @brief print the content of passengers array.
 *
 * @param list Passenger*
 * @param lenght int
 * @return
 */
int printPassengers(Passenger* list, int lenght)
{
	int returnValue = -1;

	if(list != NULL && lenght > 0)
	{
		printHeadListPassenger();
		for(int i = 0; i < lenght; i++)
		{
			printPassenger(list[i]);
		}
		returnValue = 0;
	}

	return returnValue;
}

// FALTA
/**
 * @fn int sortPassengersByCode(Passenger*, int, int)
 * @brief Sort the elements in the array of passengers, the argument order
 * 		  indicate UP or DOWN order.
 *
 * @param list Passenger*
 * @param len int
 * @param order order int [1] indicate UP - [0] indicate DOWN.
 * @return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 */
int sortPassengersByCode(Passenger* list, int len, int order)
{
	int returnValue = -1;
	int i;
	Passenger aux;
	int isOrdered;

	if (list != NULL && len > 0)
	{
		do
		{
			isOrdered = 1;
			len--;
			for (i = 0; i < len; i++)
			{
				if(strcmp(list[i].flycode, list[i + 1].lastName) < 0)
				{
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					isOrdered = 0;
				}
				else if(strcmp(list[i].lastName, list[i + 1].lastName) == 0 &&
						list[i].typePassenger < list[i + 1].typePassenger)
				{
					list[i] = list[i + 1];
					list[i + 1] = aux;
					isOrdered = 0;
				}
			}
		}while (isOrdered == 0);
		returnValue = 0;
	}

	return returnValue;
}

