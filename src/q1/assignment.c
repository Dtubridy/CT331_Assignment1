#include <stdio.h>

int i;
int* i2;
long l;
double* d;
char** c;

int main(int arg, char* argc[]){
    
  printf(" Size: %d\n", sizeof(i));
  printf(" Size: %d\n", sizeof(i2));
  printf(" Size: %d\n", sizeof(l));
  printf(" Size: %d\n", sizeof(d));
  printf(" Size: %d", sizeof(c));
   	return 0;
}