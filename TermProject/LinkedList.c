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
		
		printf("  %s", temp->command);
		
		temp = temp->next;
	}
	printf(" >> NULL\n");

}