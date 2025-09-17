#include <stdio.h>
#include <string.h>

// parsing
void parse(char* first, char* second, char* third) {
	/*char* firstToken = strtok(userInput, " ");
	char* secondToken = strtok(NULL, " ");
	char* thirdToken = strtok(NULL, " ");*/
	printf("%s %s %s", first, second, third);
}


// strtok to split

void main(void) {
	// Ask for user input
	char first[20];
	char second[20];
	char third[20];
	scanf("%s %s %s", first, second, third);
	printf("%s %s %s\n", first, second, third);

	// send input to parse
	parse(first, second, third);

	// print result based on parsing
}