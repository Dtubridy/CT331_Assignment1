#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct{
    char *data;
    size_t size;
    struct listElementStruct *next;
} listElement;

typedef struct listElementStruct listElement;

	listElement* createEl(char* data, size_t size);

void traverse(listElement* start);

	listElement* insertAfter(listElement* after, char* data, size_t size);

void deleteAfter(listElement* after);

int length(listElement *list);

void push(listElement **list, char *data, size_t size);

	listElement *pop(listElement **list);

void enqueue(listElement **list, char *data, size_t   size);

	listElement *dequeue(listElement *list);

	listElement* createEl(char* data, size_t size);

void traverse(listElement* start);

	listElement* insertAfter(listElement* after, char* data, size_t size);

void deleteAfter(listElement* after);

#endif