#pragma once
#include <stdio.h>
#include <stdbool.h>

#include "flight.h"
#include "plane.h"
#include "seat.h"

#define MENU_INPUT_LENGTH 2

void optionMenu(PFLIGHT);

void flightMenu();

void printTitle();

void printCabinView();

void assignSeatInput(PPLANE);

void deleteSeatInput(PPLANE);

void confimSeatSelection();



