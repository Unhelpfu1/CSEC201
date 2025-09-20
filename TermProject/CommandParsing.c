#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CommandParsing.h"

//Parse each individual command for errors
void parseCommandUpload(char* secondToken, char* thirdToken) {
	if (secondToken == NULL || strcmp(secondToken, "") == 0 || thirdToken == NULL || strcmp(thirdToken, "\n") == 0) { // Not enough arguments
		printf("  >> Syntax error: upload <local filename> <remote filename>\n");
	}
	else {
		printf("  >> Upload command received\n");
	}
}

void parseCommandDownload(char* secondToken, char* thirdToken) {
	if (secondToken == NULL || strcmp(secondToken, "") == 0 || thirdToken == NULL || strcmp(thirdToken, "\n") == 0) { // Not enough arguments
		printf("  >> Syntax error: download <local filename> <remote filename>\n");
	}
	else {
		printf("  >> Download command received\n");
	}
}

void parseCommandDelete(char* secondToken, char* thirdToken) {
	if (secondToken == NULL || strcmp(secondToken, "") == 0 || thirdToken == NULL || strcmp(thirdToken, "\n") == 0) { // Not enough arguments
		printf("  >> Syntax error: delete [local/remote] <filename>\n");
	}
	else if (strcmp(secondToken, "local") == 0) {
		printf("  >> Delete Local command received\n");
	}
	else if (strcmp(secondToken, "remote") == 0) {
		printf("  >> Delete Remote command received\n");
	}
	else {

		printf("  >> \'%s\' is not recognized. Valid options are \'local\' and \'remote\'.\n", secondToken);
	}
}

void parseCommandChange(char* secondToken, char* thirdToken) {
	if (secondToken == NULL || strcmp(secondToken, "") == 0 || thirdToken == NULL || strcmp(thirdToken, "\n") == 0) { // Not enough arguments
		printf("  >> Syntax error: change [local/remote] <filepath>\n");
	}
	else if (strcmp(secondToken, "local") == 0) {
		printf("  >> Change Local command received\n");
	}
	else if (strcmp(secondToken, "remote") == 0) {
		printf("  >> Change Remote command received\n");
	}
	else {
		printf("  >> \'%s\' is not recognized. Valid options are \'local\' and \'remote\'.\n", secondToken);
	}
}

void parseCommandShow(char* secondToken, char* thirdToken) {
	if (secondToken == NULL || strcmp(secondToken, "") == 0 || thirdToken == NULL || strcmp(thirdToken, "\n") == 0) { // Not enough arguments
		printf("  >> Syntax error: show [local/remote] [path/files/folders]\n");
	}
	else if (strcmp(secondToken, "local") == 0) {
		if (strcmp(thirdToken, "path\n") == 0) {
			printf("  >> Show local path command received\n");
		}
		else if (strcmp(thirdToken, "files\n") == 0) {
			printf("  >> Show local files command received\n");
		}
		else if (strcmp(thirdToken, "folders\n") == 0) {
			printf("  >> Show local folders command received\n");
		}
		else {
			printf("  >> \'%s\' is not recognized. Valid options are \'path\', \'files\', or \'folders\'.\n", thirdToken);
		}
	}
	else if (strcmp(secondToken, "remote") == 0) {
		if (strcmp(thirdToken, "path\n") == 0) {
			printf("  >> Show remote path command received\n");
		}
		else if (strcmp(thirdToken, "files\n") == 0) {
			printf("  >> Show remote files command received\n");
		}
		else if (strcmp(thirdToken, "folders\n") == 0) {
			printf("  >> Show remote folders command received\n");
		}
		else {
			printf("  >> \'%s\' is not recognized. Valid options are \'path\', \'remote\', or \'folders\'.\n", thirdToken);
		}
	}
	else {
		printf("  >> \'%s\' is not recognized. Valid options are \'local\' and \'remote\'.\n", secondToken);
	}
}

void parseCommandHistory(char* secondToken, char* thirdToken) {
	if (secondToken != NULL || thirdToken != NULL) { // Too many arguments
		printf("  >> Syntax error: \'history\' takes no parameters.\n");
	}
	else {
		printf("  >> history command received\n");
	}
}

void parseCommandValidate(char* secondToken, char* thirdToken) {
	if (secondToken != NULL || thirdToken != NULL) { // Too many arguments
		printf("  >> Syntax error: \'validate\' takes no parameters.\n");
	}
	else {
		printf("  >> validate command received\n");
	}
}

void parseCommandQuit(char* secondToken, char* thirdToken) {
	if (secondToken != NULL || thirdToken != NULL) { // Too many arguments
		printf("  >> Syntax error: \'quit\' takes no parameters.\n");
	}
	else {
		printf("  >> Quitting...\n");
	}
}

// parsing
void parseInput(char* userInput) {
	const char delimiters[] = " \t\n\r";
	char* firstToken = strtok(userInput, delimiters);
	char* secondToken = strtok(NULL, delimiters);
	char* thirdToken = strtok(NULL, delimiters);
	//printf(">> Command received: %s %s %s", firstToken, secondToken, thirdToken); // DEBUG
	if (strtok(NULL, " ") != NULL) {

		printf("  >> Syntax error: Too many arguments\n");

	}
	else {
		// Check firstToken against valid input
		if ((strcmp(firstToken, "upload") == 0) || (strcmp(firstToken, "upload\n") == 0)) {

			parseCommandUpload(secondToken, thirdToken);

		}
		else if ((strcmp(firstToken, "download")) == 0 || (strcmp(firstToken, "download\n") == 0)) {

			parseCommandDownload(secondToken, thirdToken);

		}
		else if ((strcmp(firstToken, "delete") == 0) || (strcmp(firstToken, "delete\n") == 0)) {

			parseCommandDelete(secondToken, thirdToken);

		}
		else if ((strcmp(firstToken, "change") == 0) || (strcmp(firstToken, "change\n") == 0)) {

			parseCommandChange(secondToken, thirdToken);

		}
		else if ((strcmp(firstToken, "show") == 0) || (strcmp(firstToken, "show\n") == 0)) {

			parseCommandShow(secondToken, thirdToken);

		}
		else if ((strcmp(firstToken, "history") == 0) || (strcmp(firstToken, "history\n") == 0)) {

			parseCommandHistory(secondToken, thirdToken);

		}
		else if ((strcmp(firstToken, "validate") == 0) || (strcmp(firstToken, "validate\n") == 0)) {

			parseCommandValidate(secondToken, thirdToken);

		}
		else if ((strcmp(firstToken, "quit") == 0) || (strcmp(firstToken, "quit\n") == 0)) {

			parseCommandQuit(secondToken, thirdToken);

		}
		else if ((strcmp(firstToken, "\\0") == 0) || (strcmp(firstToken, "\n") == 0)) {

			printf("No command received\n");

		}
		else {

			printf("Command unrecognized\n");

		}
	}

	//Newline for aesthetics
	printf("\n");
}