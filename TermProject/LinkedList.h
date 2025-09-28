#pragma once
// This will contain type definitions
// And function prototypes for our linked list class

struct node {
	char command[100]; // nodes will store names of size 100 or less
	struct node* next; //pointer to the next node in the list
	unsigned char* hash; // Hash of the previous node
};

struct linkedList {
	int size; // Will track how big the list is
	struct node* head; // Will track the most recently added item in the list
};

// Function prototype for the initialize function
void initialize(struct linkedList*);

void addItem(struct linkedList*, char*);

void printList(struct linkedList*); 

unsigned char* hashNode(struct node*);

int validateList(struct linkedList*);