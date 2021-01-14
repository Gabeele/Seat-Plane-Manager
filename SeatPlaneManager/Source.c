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
///Program for managing seat reservation for flights on Colossus Airlines

#include <stdio.h>
#include "menu.h"


int main(void) {		//Calling the nessessary functions to start the program

	readFile();
	printTitle();
	flightMenu();
	writeToFile();

	return 0;
}




