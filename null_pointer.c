#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL;
    printf("null pointer pointing to %p\n", p);   // null pointer pointing to 0x0
    int num = 99;

    if (p==NULL) {
        printf("pointer is not initialized\n");
        //need to initialize the pointer
        p = &num;
        printf("%p, %d\n", p, *p);
    }

    //it is dangeous if not initialize pointer before using it. 
    int *pp;
    printf("pp address: %p\n", pp);   // no problem to print the address
    //it fails when read *pp
    //printf("*pp = %d\n", *pp);   // Segmentation fault (core dumped)
}