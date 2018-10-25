#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc throws error
    free(e); //release the allocated memory
    return NULL; 
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the passed element
//Returns pointer to new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given element
void deleteAfter(listElement* after){
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

void push(listElement** list, char* data, size_t size)
{

  listElement* newEl = createEl(data, size);
  newEl->next = *list;
  
  
  *list = newEl;
}

listElement* pop(listElement** list)
{
  listElement* l = *list;
  *list = (*list)->next;
  return l;
}





listElement *dequeue(listElement *list) {
    listElement *temp = list;
    
    while((temp-> next)-> next != NULL) {
        temp = temp-> next;
    }
    
    listElement *tailElement = temp-> next;
    temp-> next = NULL;
    
    return tailElement;

}

void enqueue(listElement** list, char* data, size_t size)
{
  listElement* newEl = createEl(data, size);
  newElt->next = *list;
  *list = newEl;
}

