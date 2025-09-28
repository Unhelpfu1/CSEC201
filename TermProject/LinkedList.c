#include <stdio.h>
#include <stdlib.h> // Contains the definition of malloc
#include <string.h>
#include "LinkedList.h"

void initialize(struct linkedList* list) {
	// IF we pass in struct linkedList list instead (no *) we would have
	list->size = 0;			// list.size = 0;
	list->head = NULL;		// list.head = NULL;
}

void addItem(struct linkedList* list, char* input) {
	//Goal: create a new node, copy person into node, and add node to linked list

	// Create a new node
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	// Copy person into node
	strcpy(newNode->command, input);

	// Make the new node point at the previous head of the list
	newNode->next = list->head;

	// Set the hash of the current node to the hash of the previous command and hash
	if (list->head != NULL) {
		newNode->hash = hashNode(list->head);
		//printf("%x%x%x%x%x ", newNode->hash[0], newNode->hash[1], newNode->hash[2], newNode->hash[3], newNode->hash[4]);
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

	while (temp != NULL) { // DEBUG
		if (temp->hash != NULL) {
			printf("%x", temp->hash);
		}
		else {
			printf("NULL");
		}

		
		printf("  %s", temp->command);
		
		temp = temp->next;
	}
	printf(" >> NULL\n");

	printf(" >> Validation: %i\n", validateList(listToPrint));

}

unsigned char* hashNode(struct node* node) {
	unsigned char* hash;
	unsigned char seedA = 'a'; // To be given to each 8 bit section of hash
	unsigned char seedB = 'B';
	unsigned char seedC = '3';
	unsigned char seedD = 'd';
	unsigned char seedE = 'E';
	unsigned char* previousHash = (unsigned char*)(node->hash);
	if (previousHash != NULL && &previousHash != NULL) {
		//printf("Previous hash: %x\n", previousHash); // DEBUG
		seedA = seedA & previousHash[0];
		seedB = seedB + previousHash[1];
		seedC = seedC / ~previousHash[2];
		seedD = seedD ^ previousHash[3];
		seedE = seedE * previousHash[4];
	}
	else { // If the node has a null hash (1st node)
		seedA = seedA & (unsigned char)'1';
		seedB = seedB + (unsigned char)'b';
		seedC = seedC / ~(unsigned char)'C';
		seedD = seedD ^ (unsigned char)'4';
		seedE = seedE * (unsigned char)'e';
		printf("null hash"); // DEBUG
	}

	for (int i = 0; i < strlen(node->command); i++) { // Apply transformations to each seed for each letter
		seedA = seedA | ((unsigned char)(node->command[i]) >> 1);
		seedB = seedB & ((unsigned char)(node->command[i]) << 1);
		seedC = seedC ^ ((unsigned char)(node->command[i]) >> 2);
		seedD = ~seedD % ((unsigned char)(node->command[i]) << 2);
		seedE = seedE - ~((unsigned char)(node->command[i]) >> 1);
	}

	hash = (unsigned char*)malloc(sizeof(unsigned char) * 5); // assign 40 bits (8 bit uchar)*5

	hash[0] = seedA; // Set each 8 bit segment of hash to associated seeds
	hash[1] = seedB;
	hash[2] = seedC;
	hash[3] = seedD;
	hash[4] = seedE;
	printf("Hashed Value: %x\n", hash); //DEBUG
	return hash;
}

// 1 for success, 0 for failure, validates hashes of a linkedList
int validateList(struct linkedList* list) {
	if (list->size < 1) { // If there are no items in list
		printf("Small"); // DEBUG
		return 1; // Validation success
	}

	struct node* current = list->head;

	//printf(&current); // DEBUG
	//printf(&next); // DEBUG

	while (current->next != NULL) {
		unsigned char* hashed = hashNode(current->next);
		printf("%x %x\n", current->hash, hashed); // DEBUG
		if (current->hash != hashed) { // If current hash does not match what it should be
			printf("No match"); // DEBUG
			return 0; // Validation failure
		}
		free(hashed);
		// Move along the list
		current = current->next;
	}

	printf("Complete"); // DEBUG
	return 1; // Only reached if there are no failed hashes

}