/*
 * arrayPassenger.h
 *
 *  Created on: 28 abr. 2022
 *      Author: Sistemas4
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define LEN_NAME 51
#define LEN_PASSENGERS 10
#define LEN_FLYCODE 10
#define MSG_REQUESTDATA "\n ----- TP2 Leonel Monges (1E) Incompleto -----\n Flight System 1.0\n\t1. Add Passenger\n\t2. Modify Passenger\n\t3. Delete Passenger\n\t4. Reports\n\t5. Exit\n> Enter option: "
#define MSG_ERROR " [x] Error!\n"
#define MSG_ERROR_MAINMENU "\n [!] Sorry! Please try again later...\n <<< Redirecting to main menu...\n\n"
#define MSG_UPDATED_DATA  "OK! The data was updated!\n"
#define STATUS_ACTIVE 1
#define STATUS_INACTIVE 0
#define PRINT_HEAD_LIST_ID "ID"
#define PRINT_HEAD_LIST_NAME "NAME"
#define PRINT_HEAD_LIST_LASTNAME "LASTNAME"
#define PRINT_HEAD_LIST_PRICE "PRICE"
#define PRINT_HEAD_LIST_FLYCODE "FLYCODE"
#define PRINT_HEAD_LIST_TYPEPASSENGER "TYPE PASSENGER"
#define PRINT_HEAD_LIST_STATUSFLIGHT "STATUS FLIGHT"
#define PRINT_HEAD_SEPARATOR "| ------ | --------------- | --------------- | ----------- | ------- | -------------- | ------------- |\n"
#define RETRIES 2
#define TRUE 1
#define FALSE 0

	typedef struct
	{
		int id;
		char name[LEN_NAME];
		char lastName[LEN_NAME];
		float price;
		char flycode[LEN_FLYCODE];
		int typePassenger;
		int statusFlight;
		int isEmpty;
	}Passenger;

	int initPassengers(Passenger* list, int len);
	int addPassenger(Passenger* list, int len, int id,
			char name[], char lastName[], float price,
			int typePassenger, char flycode[]);
	int findPassengerById(Passenger* list, int len, int id);
	int removePassenger(Passenger* list, int len, int id);
	int sortPassenger(Passenger* list, int len, int order);
	int printPassengers(Passenger* list, int lenght);
	int sortPassengersByCode(Passenger* list, int len, int order);
	int mainMenu(void);

#endif /* ARRAYPASSENGER_H_ */
