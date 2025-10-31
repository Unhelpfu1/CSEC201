#include <stdio.h>
#include <stdlib.h> // Contains the definition of malloc
#include <string.h>
#include "LinkedList.h"
#include <windows.h> // For DLLs, LoadLibrary and GetProcAddress


// Declare custom function pointer types
	typedef unsigned char*(__stdcall* hashNode)(char*, unsigned char*);

	
	void initialize(struct linkedList* list) {
	// IF we pass in struct linkedList list instead (no *) we would have
	list->size = 0;			// list.size = 0;
	list->head = NULL;		// list.head = NULL;
}

void addItem(struct linkedList* list, char* input) {
	//Goal: create a new node, copy person into node, and add node to linked list

	//Import hashNode
	// Load and point to DLL
	HINSTANCE hashFuncDLL;
	hashFuncDLL = LoadLibrary(L"C:\\[Path Removed]\\HashProject\\x64\\Debug\\HashProject.dll");
	if (hashFuncDLL == NULL) {
		printf("Hash function DLL failed to load\n");
		return 1; // Fail validation, return first in list
	}
	hashNode hashFunc = (hashNode)GetProcAddress(hashFuncDLL, "hashNode");
	if (hashFunc == NULL) {
		printf("Hash function not found in DLL\n");
		return 1; // Fail validation, return first in list
	}

	// Create a new node
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	// Copy person into node
	strcpy(newNode->command, input);

	// Make the new node point at the previous head of the list
	newNode->next = list->head;

	// Set the hash of the current node to the hash of the previous command and hash
	if (list->head != NULL) {
		// 
		if (list->head->next != NULL) {
			newNode->hash = hashFunc(newNode->command, list->head->hash);
		}
		else {
			newNode->hash = hashFunc(newNode->command, NULL);
		}
		//printf("%x%x%x%x%x ", newNode->hash[0], newNode->hash[1], newNode->hash[2], newNode->hash[3], newNode->hash[4]);
	}
	else {
		newNode->hash = NULL; // If first in list, make hash null
	}

	//Make new node be the head
	list->head = newNode;
	//Increment size to reflect change
	list->size++;
}

void printList(struct linkedList* listToPrint) {

	struct node* temp = listToPrint->head; // find the head of the list
	if (temp == NULL) { // if given list is empty
		printf("List is empty\n");
		return;
	}

	while (temp != NULL) { 
		/*if (temp->hash != NULL) { // DEBUG
			printf("%x", temp->hash);
		}
		else {
			printf("NULL");
		}*/

		
		printf("  %s", temp->command);
		
		temp = temp->next;
	}
	printf(" >> NULL\n");

	//Validate list
	int listCode = validateList(listToPrint);

	if (listCode == 0) { // Check if validation was success
		printf(" >> Validation: Success\n");
	}
	else {
		struct node* current = listToPrint->head; // if failed, go to where list failed
		int commandNum = 0;
		while (commandNum < listCode) {
			current = current->next;
			commandNum++;
		}
		if (current->command == NULL) { // if command is null, dont try to print it
			printf(" >> Validation: A Command was NULL\n");
		}
		else {
			char currentCommand[100] = "";
			strcpy(currentCommand, current->command);
			int length = strlen(currentCommand);
			if (length > 0 && currentCommand[length - 1] == '\n') {
				currentCommand[length - 1] = '\0';
			}
			printf(" >> Validation: Failure at command \"%s\"\n", currentCommand); // print which command failed in list
		}
	}
}

// Check for NULL node
// Pass current command and next hash
//unsigned char* hashNode(struct node* node) {
//	unsigned char* hash = (unsigned char*)malloc(sizeof(unsigned char) * 5);
//	if (node == NULL) {
//		return NULL;
//	}
//
//	for (int i = 0; i < 5; i++) {
//		hash[i] = 0;
//	}
//
//	if (node->command != NULL) {
//		for (int i = 0; i < strlen(node->command); i++) {
//			hash[0] ^= node->command[i]; // apply a bunch of transformations
//			hash[i % 2] &= node->command[i];
//			hash[i % 3] |= node->command[i];
//			hash[i % 4] ^= ~(node->command[i]) << 1;
//			hash[i % 5] &= ~node->command[i] >> 1;
//		}
//	}
//	
//
//	if (node->next != NULL) { // If not first in list (redundant check)
//		if (node->next->hash != NULL) { // If next hash isn't null
//			for (int i = 0; i < 5; i++) {
//				hash[i] = hash[i] + node->next->hash[i] % 256;
//			}
//		}
//		else {
//			for (int i = 0; i < 5; i++) {
//				hash[i] = hash[i] + 10 * i % 256; // Default seed values instead of previous hash
//			}
//		}
//		
//	}
//
//	//printf("Hashed Value: %x\n", hash); //DEBUG
//	return hash;
//}

// 1 for success, 0 for failure, validates hashes of a linkedList
int validateList(struct linkedList* list) {
	//if (list->size < 1) { // If there are no items in list
	//	printf("List Too Small"); // DEBUG
	//	return 0; // Validation success
	//}

	//Load hashNode
	// Load and point to DLL
	HINSTANCE hashFuncDLL;
	hashFuncDLL = LoadLibrary(L"C:\\[Path Removed]\\HashProject\\x64\\Debug\\HashProject.dll");
	// if library fails to load
	if (hashFuncDLL == NULL) {
		printf("Hash function DLL failed to load\n");
		return 1; // Fail validation, return first in list
	}
	hashNode hashFunc = (hashNode)GetProcAddress(hashFuncDLL, "hashNode");
	// if function is not found
	if (hashFunc == NULL) {
		printf("Hash function not found in DLL\n");
		return 1; // Fail validation, return first in list
	}


	struct node* current = list->head;
	int commandNum = 1;

	//printf(current); // DEBUG
	//printf(current->next); // DEBUG

	while (current != NULL) {
		unsigned char* hashed;
		if (current->next != NULL) {
			hashed = hashFunc(current->command, current->next->hash);
		}
		else {
			hashed = hashFunc(current->command, NULL);
		}

		if (hashed != NULL && current->hash != NULL) {
			

			//printf("Validating: "); // DEBUG
			//for (int i = 0; i < 5; i++) {
			//	printf("%02x", current->hash[i]);
			//}
			//printf(" == ");
			//for (int i = 0; i < 5; i++) {
			//	printf("%02x", hashed[i]);
			//}
			//printf("\n");


			for (int i = 0; i < 5; i++) {
				if (current->hash[i] != hashed[i]) { // If current hash does not match what it should be
					//printf("No match"); // DEBUG
					free(hashed);
					return commandNum; // Validation failure
				}
			}
		}
		else {
			//printf("Null Hash"); // DEBUG
		}

		
		
		free(hashed);
		current = current->next; // Move along the list
		commandNum++;
	}

	//printf("Complete"); // DEBUG
	return 0; // Only reached if there are no failed hashes

}