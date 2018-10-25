#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

listElement* createEl(void* data, size_t size, void* printFunction) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		
		return NULL;
	}
	void* dataPointer = malloc(size);
	if (dataPointer == NULL) {
		free(e); 
		return NULL; 
	}
	memmove(dataPointer, data, size);
	e->data = dataPointer;
	e->size = size;
	e->printFunction = printFunction;
	e->next = NULL;
	return e;
}

void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		current->printFunction(current->data);
		current = current->next;
	}
}


void printInt(void* data)
{
	printf("%d\n", *(int*)data);
}
void printLong(void* data)
{
	printf("%ld\n", *(long*)data);
	
}
void printDouble(void* data)
{
	printf("%f\n", *(double*)data);
}
void printFloat(void* data)
{
	printf("%f\n", *(float*)data);
}
void printChar(void* data)
{
	printf("%c\n", *(char*)data);
}
void printString(void* data)
{
	printf("%s\n", (char*)data);
}


listElement* insertAfter(listElement* el, void* data, size_t size, void* printFunction) {
	listElement* newEl = createEl(data, size, printFunction);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


void push(listElement** list, void* data, size_t size, void* printFunction)
{
	listElement* newElement = createEl(data, size, printFunction);
	newElement->next = *list;
	*list = newElement;
}

listElement* pop(listElement** list)
{
	listElement* temp = *list;
	*list = (*list)->next;
	return temp;
}

void enqueue(listElement** list, void* data, size_t size, void* printFunction)
{
	listElement* newElement = createEl(data, size, printFunction);
	newElement->next = *list;
	*list = newElement;
}

listElement* dequeue(listElement* list)
{
	listElement* current = list;
	while ((current->next)->next != NULL)
	{
		current = current->next;
	}
	listElement* temp = current->next;
	current->next = NULL;
	return temp;
}

void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	free(delete->data); 
	free(delete);
}

int length(listElement* list)
{
	listElement* current = list;
	int num = 0;
	while (current != NULL)
	{
		num++;
		current = current->next;
	}
	return num;
}