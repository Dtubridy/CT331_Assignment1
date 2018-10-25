#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

genericListElement* createEl(void* data, size_t size, printData print) {
	genericListElement* e = malloc(sizeof(genericListElement));
	if (e == NULL) {
		
		return NULL; 
	}
	void* dataPointer = malloc(size);
	if (dataPointer == NULL) {
		free(e); 
		return NULL; 
	}
	e->print = print;
	memmove(dataPointer, data, size);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	return e;
}
void traverse(genericListElement* start) {
	genericListElement* current = start;
	while (current != NULL) {
		current->print(current->data);
		current = current->next;
	}
}

genericListElement* insertAfter(genericListElement* el, void* data, size_t size, printData print) {
	genericListElement* newEl = createEl(data, size, print);
	genericListElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}

void deleteAfter(genericListElement* after) {
	genericListElement* delete = after->next;
	genericListElement* newNext = delete->next;
	after->next = newNext;

	free(delete->data);
	free(delete);
}

int length(genericListElement* list) {
	int len = 0;
	genericListElement* curr = list;
	while (curr != NULL) {
		len++;
		curr = curr->next;
	}
	return len;
} 

void push(genericListElement** list, void* data, size_t size, printData print) {
	genericListElement* newEl = createEl(data, size, print);
	newEl->next = *list;
	*list = newEl;
}

genericListElement* pop(genericListElement** list) {
	if (length(*list) == 0) {
		return *list;
	}
	genericListElement* top = *list;
	*list = top->next;
	return top;
}

void enqueue(genericListElement** list, void* data, size_t size, printData print) {
	push(list, data, size, print);
}


genericListElement* dequeue(genericListElement* list) {
	genericListElement* curr = list;
	while ((curr->next)->next != NULL)
	{
		curr = curr->next;
	}
	genericListElement* temp = curr->next;
	curr->next = NULL;
	return temp;
}