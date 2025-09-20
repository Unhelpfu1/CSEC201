#pragma once
// This will contain type definitions
// And function prototypes for our linked list class

struct node {
	char command[100]; // nodes will store names of size 100 or less
	struct node* next; //pointer to the next node in the list
};

struct linkedList {
	int size; // Will track how big the list is
	struct node* head; // Will track the most recently added item in the list
};

// Function prototype for the initialize function
void initialize(struct linkedList* list);

void addItem(struct linkedList* list, char* input);

void printList(struct linkedList* listToPrint); 