#include <stdio.h>
#include <stdlib.h>

//stack - zhan
//- Do not return pointer to the stack (zhan) memory
//- the space is garbage collected by system after function exit 
int * pointer_to_stack() {
   int a = 10;
   int *p = &a;
   printf("value in stack: %d", *p);
   return p;
}

//heap - zhui
//- heap can be referenced among different functions, once
//  the space is allocated, will be there until free() is called  
char * pointer_to_heap() {
   //allocate one byte in heap
   char *p = (char *)malloc(sizeof(char));
   *p = 'A';
   return p;
}

int main() {
   int *ptr_to_stack = pointer_to_stack();
   printf("\n");
   printf("value in stack was garbage collected = %d\n", *ptr_to_stack);

   char *ptr_to_heap = pointer_to_heap();
   printf("\n");
   printf("value in heap is unchanged: %c\n", *ptr_to_heap);
   free(ptr_to_heap);
}