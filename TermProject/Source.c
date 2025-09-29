#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CommandParsing.h"
#include "LinkedList.h"

void main(void) {

	char userInput[100];

	char inputCopy[100];
	struct linkedList* commandHistory = (struct linkedList*)malloc(sizeof(struct linkedList));
	initialize(commandHistory);

	// Until user quits
	while (1) {

		// Ask for user input
		printf("FML> ");
		fgets(userInput, 100, stdin);
		//printf("%s\n", userInput); // DEBUG

		//make a copy of input to avoid destruction
		strcpy(inputCopy, userInput);

		
		//if (strcmp(userInput, "linkedList test\n") == 0) { // Hashing validation test DEBUG
		//	commandHistory->head->next->next->next->hash[0] = 'Z';
		//}
		
		
		// send input to parse
		parseInput(userInput, commandHistory);
		// print result based on parsing

		// add command to history
		addItem(commandHistory, inputCopy);

		// Escape when user enters 'quit'
		if (strcmp(userInput, "quit\n") == 0 || strcmp(userInput, "quit") == 0) {
			break;
		}
	}
}