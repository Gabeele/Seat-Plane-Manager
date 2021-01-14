///PROG71985 Assignment 4
///Question 2
/// 
///Gavin Abeele
/// 
///November 30, 2020
/// 
///1.0 November 2020: Inital 
///1.1 November 2020: Refactor
/// 
///Functions framework for the flight structure and array

#define _CRT_SECURE_NO_WARNINGS

#include "flight.h"

FLIGHT createFlight(int flightNumber, PLANE plane) {	//Creates a flight

	FLIGHT flight;
	flight.flightNumber = flightNumber;

	flight.plane = plane;

	return flight;
}

void writeToFile() {	//Writes the values of the struct from the array
	FILE* filePointer;
	char assignedValue[ASSIGNED_VALUE_LENGTH];
	char firstName[NAME_LENGTH], lastName[NAME_LENGTH];
	int seatID, flightNumber;

	filePointer = fopen("ColossusAirlines_FlightSeatManager.txt", "w");

	if (filePointer == NULL)
	{
		printf("Error: File cannot be written too.");
		exit(1);
	}

	for (int i = 0; i < MAX_NUMBER_OF_FLIGHTS; i++) {
		for (int j = 0; j < NUMER_OF_SEATS; j++) {

			//Convert the assigned value to a string
			if (flightArray[i].plane.seatArray[j].assigned) {
				strcpy_s(assignedValue, ASSIGNED_VALUE_LENGTH, "true", ASSIGNED_VALUE_LENGTH);
			}
			else {
				strcpy_s(assignedValue, ASSIGNED_VALUE_LENGTH, "false", ASSIGNED_VALUE_LENGTH);
			}

			fprintf(filePointer, "%d %s %s %s %d\n", flightArray[i].plane.seatArray[j].seatID, flightArray[i].plane.seatArray[j].lastName, flightArray[i].plane.seatArray[j].firstName, assignedValue, flightArray[i].flightNumber);		//Writes each array value to a file


			if (flightArray[i].plane.seatArray->confirmation == CONFIRMATION_SYMBOL_EDIT) {	//Changes the symbol to blank
				flightArray[i].plane.seatArray->confirmation = CONFIRMATION_SYMBOL_BLANK;
			}
		}
	}

	fclose(filePointer);
}

void readFile() {	//Inializes and reads the file
	FILE* filePointer;
	int tempSeatID, flightNumber;
	char tempLastName[NAME_LENGTH], tempFirstName[NAME_LENGTH], tempAssignedValue[ASSIGNED_VALUE_LENGTH], yesNoInput;
	SEATID seatID;
	bool assigned;

	filePointer = fopen("ColossusAirlines_FlightSeatManager.txt", "r");

	initFlightArray();	//Initalizes the arrays

	while (filePointer == NULL)		//Checks for the file, if it is not there then prompt the user to create a new file or exit
	{
		printf("Error: File cannot be oppened.\nAttempt to create a new file and initalize it? (y/n)\n");
		scanf_s("%c", &yesNoInput, YES_NO_LENGTH);

		if (yesNoInput == 'y' || yesNoInput == 'Y') {

			writeToFile();	//Creates a new file
			filePointer = fopen("ColossusAirlines_FlightSeatManager.txt", "r");	//Resetting the file pointer 
			break;
		}
		else if (yesNoInput == 'n' || yesNoInput == 'N') {
			printf("Exiting program.");
			exit(1);
		}
		else {
			printf("Input error: exiting.");
			exit(1);
		}
	}

	while (fscanf(filePointer, "%d %s %s %s %d[^\n]", &tempSeatID, tempLastName, tempFirstName, tempAssignedValue, &flightNumber) != EOF) {	//While the pointer is not end of file, it will take each line and split the values, then call to create the seat information

		seatID = getSeatIDFromSeatNum(tempSeatID);	//Obtatining the seatID number

		//Comparing the file assigned string and setting the assigned value
		if (strcmp(tempAssignedValue, "true") == 0) {
			assigned = true;
		}
		else if (strcmp(tempAssignedValue, "false") == 0) {
			assigned = false;
		}
		else {
			assigned = false;
		}

		switch (flightNumber)	//Assignes the flight number to the flight array plane seat assignment
		{
		case FLIGHT102:
			assignSeat(seatID, assigned, tempLastName, tempFirstName, CONFIRMATION_SYMBOL_BLANK, &flightArray[0].plane);
			break;
		case FLIGHT311:
			assignSeat(seatID, assigned, tempLastName, tempFirstName, CONFIRMATION_SYMBOL_BLANK, &flightArray[1].plane);
			break;
		case FLIGHT444:
			assignSeat(seatID, assigned, tempLastName, tempFirstName, CONFIRMATION_SYMBOL_BLANK, &flightArray[2].plane);
			break;
		case FLIGHT519:
			assignSeat(seatID, assigned, tempLastName, tempFirstName, CONFIRMATION_SYMBOL_BLANK, &flightArray[3].plane);
			break;
		}
	}

	fclose(filePointer);

}

PFLIGHT getFlightFromNumber(int number)		//Returns the flight from the flight number
{
	for (int i = 0; i < MAX_NUMBER_OF_FLIGHTS; i++) {
		if (flightArray[i].flightNumber == number) {
			return &flightArray[i];
		}
	}

}

void initFlightArray()	//Initalizes the flight array with default values
{
	flightArray[0] = createFlight(FLIGHT102, createPlane(1, NULL));


	flightArray[1] = createFlight(FLIGHT311, createPlane(1, NULL));


	flightArray[2] = createFlight(FLIGHT444, createPlane(2, NULL));


	flightArray[3] = createFlight(FLIGHT519, createPlane(2, NULL));


}

