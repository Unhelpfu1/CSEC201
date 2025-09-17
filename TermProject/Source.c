#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// parsing
void parseInput(char* userInput) {
	char* firstToken = strtok(userInput, " ");
	char* secondToken = strtok(NULL, " ");
	char* thirdToken = strtok(NULL, " ");
	//printf(">> Command received: %s %s %s", firstToken, secondToken, thirdToken); // DEBUG

	// Check firstToken against valid input
	if ((strcmp(firstToken, "upload") == 0) || (strcmp(firstToken, "upload\n") == 0)) {

		printf("Received Upload\n");

	} else if ((strcmp(firstToken, "download")) == 0 || (strcmp(firstToken, "download\n") == 0)) {

		printf("download\n");

	}
	else if ((strcmp(firstToken, "delete") == 0) || (strcmp(firstToken, "delete\n") == 0)) {

		printf("delete\n");

	}
	else if ((strcmp(firstToken, "change") == 0) || (strcmp(firstToken, "change\n") == 0)) {

		printf("change\n");

	}
	else if ((strcmp(firstToken, "show") == 0) || (strcmp(firstToken, "show\n") == 0)) {

		printf("show\n");

	}
	else if ((strcmp(firstToken, "history") == 0) || (strcmp(firstToken, "history\n") == 0)) {

		printf("history\n");

	}
	else if ((strcmp(firstToken, "validate") == 0) || (strcmp(firstToken, "validate\n") == 0)) {

		printf("validate\n");

	}
	else if ((strcmp(firstToken, "quit") == 0) || (strcmp(firstToken, "quit\n") == 0)) {

		printf("  >> Quitting\n");

	}
	else if ((strcmp(firstToken, "\\0") == 0) || (strcmp(firstToken, "\n") == 0)) {

		printf("No command received\n");

	}else {
		printf("Command unrecognized\n");
	}

	//Newline for aesthetics
	printf("\n");
}

void main(void) {

	char* userInput[100];

	// Until user quits
	while (strcmp(userInput, "quit\n") != 0) {

		// Ask for user input
		printf("FML> ");
		fgets(userInput, 100, stdin);
		//printf(userInput); // DEBUG

		// send input to parse
		parseInput(userInput);

		// print result based on parsing
	}
}