#include <stdlib.h>
#include <stdio.h>

int main() {
    int num;
    printf("Input number of int to allocate: ");
    scanf("%d", &num);

    //allocate the memory
    //malloc() return void pointer
    //if fail to allocate memory, return NULL
    int *p = (int *)malloc(sizeof(int) * num);
    printf("*p address is allocated: %p\n", p);

    if (p != NULL) {
        for (int i=0; i<num; i++) {
            p[i] = i;
            printf("%d, %p\n", p[i], &p[i]);
        }        
        //It would cause fail if free() is called more than once with the same address
        //free memory after allocation
        free(p);   
        //after free up, the *p space address does not change, but the content can be garbage;
        printf("*p address after free up: %p\n", p);
        for (int i=0; i<num; i++) {
            printf("garbage %d, %p\n", p[i], &p[i]);
        }      
        //to avoid using garbage data, set p to NULL
        p = NULL;

    } else {
        printf("Failed to allocate memory");
    }


    return 0;
}