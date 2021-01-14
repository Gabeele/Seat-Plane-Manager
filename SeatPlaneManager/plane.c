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
///Functions framework for the structure and array

#include "plane.h"

PLANE createPlane(int planeID, SEAT seatArray[]) {	//Initalizes the plane to have default values

	PLANE plane;

	plane.planeID = planeID;

	for (int i = 0; i < NUMER_OF_SEATS; i++) {
		
		plane.seatArray[i] = createSeatInfo(i, false, "NA", "NA", CONFIRMATION_SYMBOL_BLANK);	

	}
	return plane;
}

int numOfEmptySeats(PPLANE plane) {		//Returns the number of empty seats

	int numEmpty = 0;

	for (int i = 0; i < NUMER_OF_SEATS; i++) {

		if (!plane->seatArray[i].assigned) {
			numEmpty++;

		}
	}

	return numEmpty;
}

void listEmptySeats(PPLANE plane) {		//Prints the empty seats

	printf("\nEmpty seats avalibale: \n");

	for (int i = 0; i < NUMER_OF_SEATS; i++) {
		if (!plane->seatArray[i].assigned) {
			printSeat(plane, i);
		}
	}

}

void alphaListSeats(PPLANE plane) {		//Prints all the array stuctures in order

	printf("\nSeats in alphabetical order: \n");

	for (int i = 0; i < NUMER_OF_SEATS; i++) {
		printSeat(plane, i);
	}

}

void assignSeat(SEATID seatID, bool assigned, char lName[], char fName[], char confirmSym, PPLANE plane) {		//Creates a new seat from passed through values

	SEAT newSeat = createSeatInfo(seatID, assigned, lName, fName, confirmSym);

	plane->seatArray[seatID] = newSeat;	//Adds the seat to the array with the enum seatID 

}

bool deleteSeatInfo(SEATID seatToDelete, PPLANE plane)	//C
{
	if (plane->seatArray[seatToDelete].assigned) {		//If the seat is assigned, then it will reassign it to be an empty seat
		assignSeat(seatToDelete, false, "NA", "NA", CONFIRMATION_SYMBOL_EDIT, plane);
		return true;
	}
	else {
		return false;
	}

}

void printSeat(PPLANE plane, int seatID) {	//Prints the seat with the passed through value of seatID
	char seatCode[SEATID_LENGTH];

	//Sets seatID number to a string
	switch (seatID) {
	case 0:
		strcpy_s(seatCode, SEATID_LENGTH, "A1", SEATID_LENGTH);
		break;
	case 1:
		strcpy_s(seatCode, SEATID_LENGTH, "A2", SEATID_LENGTH);
		break;
	case 2:
		strcpy_s(seatCode, SEATID_LENGTH, "B1", SEATID_LENGTH);
		break;
	case 3:
		strcpy_s(seatCode, SEATID_LENGTH, "B2", SEATID_LENGTH);
		break;
	case 4:
		strcpy_s(seatCode, SEATID_LENGTH, "C1", SEATID_LENGTH);
		break;
	case 5:
		strcpy_s(seatCode, SEATID_LENGTH, "C2", SEATID_LENGTH);
		break;
	case 6:
		strcpy_s(seatCode, SEATID_LENGTH, "D1", SEATID_LENGTH);
		break;
	case 7:
		strcpy_s(seatCode, SEATID_LENGTH, "D2", SEATID_LENGTH);
		break;
	case 8:
		strcpy_s(seatCode, SEATID_LENGTH, "E1", SEATID_LENGTH);
		break;
	case 9:
		strcpy_s(seatCode, SEATID_LENGTH, "E2", SEATID_LENGTH);
		break;
	case 10:
		strcpy_s(seatCode, SEATID_LENGTH, "F1", SEATID_LENGTH);
		break;
	case 11:
		strcpy_s(seatCode, SEATID_LENGTH, "F2", SEATID_LENGTH);
		break;
	default:
		break;
	}

	if (!plane->seatArray[seatID].assigned) {	//If no seat is assigned then print 
		printf("SeatID - %s | %s, %s | Assigned: false %c\n", seatCode, plane->seatArray[seatID].lastName, plane->seatArray[seatID].firstName, plane->seatArray[seatID].confirmation);
	}
	else {	//If the seat is assigned 
		printf("SeatID - %s | %s, %s | Assigned: true %c\n", seatCode, plane->seatArray[seatID].lastName, plane->seatArray[seatID].firstName, plane->seatArray[seatID].confirmation);
	}
}

bool abortStatus(char isAbort[]) {	//Returns the value if a passed value is 'abort'

	if ((strcmp(isAbort, "abort") == 0) || (strcmp(isAbort, "Abort") == 0)) {
		printf("------------Aborting------------");
		return true;
	}
	else {
		return false;
	}
}

SEATID getSeatIDFromSeatNum(int seatNum) {	//Returns the value of seatID from a number

	SEATID seatID;

	switch (seatNum) {
	case 0:
		return seatID = A1;
		break;
	case 1:
		return seatID = A2;
		break;
	case 2:
		return seatID = B1;
		break;
	case 3:
		return seatID = B2;
		break;
	case 4:
		return seatID = C1;
		break;
	case 5:
		return seatID = C2;
		break;
	case 6:
		return seatID = D1;
		break;
	case 7:
		return seatID = D2;
		break;
	case 8:
		return seatID = E1;
		break;
	case 9:
		return seatID = E2;
		break;
	case 10:
		return seatID = F1;
		break;
	case 11:
		return seatID = F2;
		break;
	}


}

void printUnconfirmedSeats(PPLANE plane) {	//Prints the seats that are unconfimed

	for (int i = 0; i < NUMER_OF_SEATS; i++) {

		if (plane->seatArray[i].confirmation == CONFIRMATION_SYMBOL_EDIT) {
			printSeat(plane, i);
		}
	}

}



