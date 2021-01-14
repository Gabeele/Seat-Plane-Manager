#pragma once

#include <stdbool.h>
#include <string.h>

#define NAME_LENGTH 100

typedef enum seatID {A1, A2, B1, B2, C1, C2, D1, D2, E1, E2, F1, F2} SEATID;

typedef struct seat {
	SEATID seatID;
	bool assigned;
	char lastName[NAME_LENGTH];
	char firstName[NAME_LENGTH];
	char confirmation;		//Blank is assigned and * if edits have been made

} SEAT, *PSEAT;

SEAT createSeatInfo(SEATID, bool, char[], char[], char);





