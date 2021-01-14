#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "plane.h"

#define MAX_NUMBER_OF_FLIGHTS 4

#define FLIGHT102 102
#define FLIGHT311 311
#define FLIGHT444 444
#define FLIGHT519 519

typedef struct flight {
	int flightNumber;
	PLANE plane;

}FLIGHT, *PFLIGHT;

static FLIGHT flightArray[MAX_NUMBER_OF_FLIGHTS];

PFLIGHT getFlightFromNumber(int);

FLIGHT createFlight(int, PLANE);

void initFlightArray();





