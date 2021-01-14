#pragma once

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "seat.h"

#define SEATID_LENGTH 6
#define NUMER_OF_SEATS 12	
#define ASSIGNED_VALUE_LENGTH 10
#define YES_NO_LENGTH 2
#define CONFIRMATION_SYMBOL_BLANK ' '
#define CONFIRMATION_SYMBOL_EDIT '*'

typedef struct plane{

	int planeID;
	SEAT seatArray[NUMER_OF_SEATS];

} PLANE, *PPLANE;


PLANE createPlane(int, SEAT[]);

void printSeat(PPLANE, int);

int numOfEmptySeats(PPLANE);

void listEmptySeats(PPLANE);

void alphaListSeats(PPLANE);

void assignSeat(SEATID, bool, char[], char[], char, PPLANE);

bool deleteSeatInfo(SEATID);

bool abortStatus(char[]);

SEATID getSeatIDFromSeatNum(int);

void printUnconfirmedSeats(PPLANE);








