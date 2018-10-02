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

    if (p != NULL) {
        for (int i=0; i<num; i++) {
            p[i] = i;
            printf("%d, %p\n", p[i], &p[i]);
        }        
        //It would cause fail if free() is called more than once with the same address
        //free memory after allocation
        free(p);       
    } else {
        printf("Failed to allocate memory");
    }


    return 0;
}