///PROG71985 Assignment 4
///Question 2
/// 
///Gavin Abeele
/// 
///November 30, 2020
/// 
///1.0 November 2020: Inital 
///1.1 Novemeber 2020: Refactor
/// 
///Framework for the structure 
/// 
#include "seat.h"


SEAT createSeatInfo(SEATID seatID, bool assigned, char lastName[], char firstName[], char confirmationSymbol)	//Creates a new seat and returns the struct 
{
	SEAT newSeat;

	newSeat.seatID = seatID;

	newSeat.assigned = assigned;

	strcpy_s(newSeat.lastName, NAME_LENGTH, lastName, NAME_LENGTH);

	strcpy_s(newSeat.firstName, NAME_LENGTH, firstName, NAME_LENGTH);

	newSeat.confirmation = confirmationSymbol;

	return newSeat;
}



