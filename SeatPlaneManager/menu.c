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
/// Feedback Received: No feedback 
/// 
///Prints the menu and provides the user to enter in values for the programs features. 

#include "menu.h"

void flightMenu() {
			bool shouldQuit = false;	//Allows the user to quit from the program.
			char menuInput;

	do {
		PFLIGHT seletedFlight;	

		printf("\n-------------------------Select Flight Menu-----------------------------\n");
		printf("\nTo choose a flight, enter the letter label:\n\n");

		printf("a) Flight 102\n");
		printf("b) Flight 311\n");
		printf("c) Flight 444\n");
		printf("d) Flight 519\n");
		printf("e) Exit\n");

		scanf_s(" %c[^\n]", &menuInput, MENU_INPUT_LENGTH);

		switch (menuInput)
		{
		case 'a':
			seletedFlight = getFlightFromNumber(FLIGHT102);		//Selected the flight pointer
			optionMenu(seletedFlight);		//  passess the flight pointer through to the options menu for control over the selected flight
			break;
		case 'b':
			seletedFlight = getFlightFromNumber(FLIGHT311);	
			optionMenu(seletedFlight);
			break;
		case 'c':
			seletedFlight = getFlightFromNumber(FLIGHT444);
			optionMenu(seletedFlight);
			break;
		case 'd':
			seletedFlight = getFlightFromNumber(FLIGHT519);
			optionMenu(seletedFlight);
			break;
		case 'e':
			printf("Exiting...\n");
			shouldQuit = true;
			break;
		default:
			printf("Incorrect output.\n");
			break;
		}

	} while (!shouldQuit);

}

void optionMenu(PFLIGHT flight) {

	char menuInput;
	bool shouldQuit = false;	//Allows the user to quit from the program.

	do {
		printf("\n--------------------Flight %d Options Menu-----------------------------\n", flight->flightNumber);
		printf("\nTo choose a function, enter the letter label:\n");
		printf("Type abort to cancel any function.\n\n");
		printf("a) Show number of empty seats\n");
		printf("b) Show list of empty seats\n");
		printf("c) Show alphabetical list of seats\n");
		printf("d) Assign a Customer to a seat\n");
		printf("e) Delete a seat assignment\n");
		printf("f) Confirm seat assignment\n");
		printf("g) Back\n");


		scanf_s(" %c[^\n]", &menuInput, MENU_INPUT_LENGTH);

		switch (menuInput)
		{
		case 'a':
			printf("There are %d empty seats.\n", numOfEmptySeats(&flight->plane));		//Passess through the plane pointer 
			break;
		case 'b':
			listEmptySeats(&flight->plane);
			break;
		case 'c':
			alphaListSeats(&flight->plane);
			break;
		case 'd':
			printCabinView();
			assignSeatInput(&flight->plane);
			break;
		case 'e':
			printCabinView();
			deleteSeatInput(&flight->plane);
			break;
		case 'f':
			printUnconfirmedSeats(&flight->plane);	
			confimSeatSelection();
			break;
		case 'g':
			readFile();		//Reloads the arrays to the previous state
			shouldQuit = true;
			break;
				break;
		default:
			printf("Incorrect output.");
			break;
		}
	} while (!shouldQuit);

}

void printCabinView() {		//Prints a view of the cabin

	printf("         __   __\n");
	printf("        |F1   F2|\n");
	printf("        |E1   E2|\n");
	printf("        |D1   D2|\n");
	printf("        |C1   C2|\n");
	printf("        |B1   B2|\n");
	printf("        |A1   A2|\n");
	printf("        |__   __|\n");

}

void printTitle() {		//Prints the title

	printf("Colossus Airlines Fleet Seat Manager\n\n");

	printf("                            __|__\n");
	printf("                __|__    *---oOo---*\n");
	printf("    __|__    *---oOo---*\n");
	printf(" *---oOo---*\n");

}	 //Prints the title 

void assignSeatInput(PPLANE plane) {	//Takes in user input and passes the values to the assigned 
	char fName[NAME_LENGTH], lName[NAME_LENGTH], seatSelected[SEATID_LENGTH];	//Assigns values for the first and last name, as well as the string seatID 
	bool isAssigned = true, shouldAbort = false;	//isAssigned for the creation of the seat, and shouldAbort is the determine to break the loop
	SEATID seatID;

	do {
		do {
			printf("\nSeatID (A1): ");
			scanf_s("%s", seatSelected, SEATID_LENGTH);

			shouldAbort = abortStatus(seatSelected);	//Checks if the user input is 'abort' and breaks the loops. 
			if (shouldAbort) {
				break;
			}

			//Converts the input string to the seatID
			if (strcmp(seatSelected, "A1") == 0) {
				seatID = A1;
				break;
			}
			else if (strcmp(seatSelected, "A2") == 0) {
				seatID = A2;
				break;
			}
			else if (strcmp(seatSelected, "B1") == 0) {
				seatID = B1;
				break;
			}
			else if (strcmp(seatSelected, "B2") == 0) {
				seatID = B2;
				break;
			}
			else if (strcmp(seatSelected, "C1") == 0) {
				seatID = C1;
				break;
			}
			else if (strcmp(seatSelected, "C2") == 0) {
				seatID = C2;
				break;
			}
			else if (strcmp(seatSelected, "D1") == 0) {
				seatID = D1;
				break;
			}
			else if (strcmp(seatSelected, "D2") == 0) {
				seatID = D2;
				break;
			}
			else if (strcmp(seatSelected, "E1") == 0) {
				seatID = E1;
				break;
			}
			else if (strcmp(seatSelected, "E2") == 0) {
				seatID = E2;
				break;
			}
			else if (strcmp(seatSelected, "F1") == 0) {
				seatID = F1;
				break;
			}
			else if (strcmp(seatSelected, "F2") == 0) {
				seatID = F2;
				break;
			}
			else {
				printf("Invalid entery");
			}
		} while (true);

		if (shouldAbort) {
			break;
		}

		printf("\nFirst Name: ");
		scanf_s("%s", fName, NAME_LENGTH);

		shouldAbort = abortStatus(fName);
		if (shouldAbort) {
			break;
		}

		printf("\nLast Name: ");
		scanf_s("%s", lName, NAME_LENGTH);

		shouldAbort = abortStatus(lName);
		if (shouldAbort) {
			break;
		}

		assignSeat(seatID, isAssigned, lName, fName, CONFIRMATION_SYMBOL_EDIT, plane);	//Creates the new seat
		printf("\n");
		printSeat(plane, seatID);

		break;

	} while (!shouldAbort);

}

void deleteSeatInput(PPLANE plane) {	//Takes in user input and deletes corrisponding seat
	char deleteSeat[SEATID_LENGTH];		//String of seatID from the user
	SEATID seatID;
	bool shouldAbort = false;	//ShouldAbort to determine if the function should break

	do {
		do {

			printf("\nEnter in a seatID to remove customer: ");
			scanf_s("%s", deleteSeat, SEATID_LENGTH);

			shouldAbort = abortStatus(deleteSeat);
			if (shouldAbort) {
				break;
			}

			if (strcmp(deleteSeat, "A1") == 0) {
				seatID = A1;
				break;
			}
			else if (strcmp(deleteSeat, "A2") == 0) {
				seatID = A2;
				break;
			}
			else if (strcmp(deleteSeat, "B1") == 0) {
				seatID = B1;
				break;
			}
			else if (strcmp(deleteSeat, "B2") == 0) {
				seatID = B2;
				break;
			}
			else if (strcmp(deleteSeat, "C1") == 0) {
				seatID = C1;
				break;
			}
			else if (strcmp(deleteSeat, "C2") == 0) {
				seatID = C2;
				break;
			}
			else if (strcmp(deleteSeat, "D1") == 0) {
				seatID = D1;
				break;
			}
			else if (strcmp(deleteSeat, "D2") == 0) {
				seatID = D2;
				break;
			}
			else if (strcmp(deleteSeat, "E1") == 0) {
				seatID = E1;
				break;
			}
			else if (strcmp(deleteSeat, "E2") == 0) {
				seatID = E2;
				break;
			}
			else if (strcmp(deleteSeat, "F1") == 0) {
				seatID = F1;
				break;
			}
			else if (strcmp(deleteSeat, "F2") == 0) {
				seatID = F2;
				break;
			}
			else {
				printf("Invalid entery");
			}

		} while (true);

		if (shouldAbort) {
			break;
		}

		//Passes the seatID value and if returns true then the seat is deleted
		if (deleteSeatInfo(seatID, plane)) {

			printf("Deletion successful.\n");
		}
		else {
			printf("There is no data to delete.\n");
		}

		break;

	} while (!shouldAbort);
}

void confimSeatSelection() {	//Confirms the seat edits 
	char yesNoInput;


	printf("\nConfim seat selection? (y/n): ");
	scanf_s(" %c", &yesNoInput, YES_NO_LENGTH);

	if (yesNoInput == 'y' || yesNoInput == 'Y') {

		writeToFile();	//Saves the seats to the file
		printf("Seats confimered.\n");
		readFile();		//Reloads data into the system
	}
	else {
		printf("Canceled.\n");

	}

}






