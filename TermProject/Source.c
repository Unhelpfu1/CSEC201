#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CommandParsing.h"

void main(void) {

	char userInput[100];

	// Until user quits
	while (1) {

		// Ask for user input
		printf("FML> ");
		fgets(userInput, 100, stdin);
		//printf("%s\n", userInput); // DEBUG

		// send input to parse
		parseInput(userInput);
		// print result based on parsing
		

		// Escape when user enters 'quit'
		if (strcmp(userInput, "quit\n") == 0 || strcmp(userInput, "quit") == 0) {
			break;
		}
	}
}