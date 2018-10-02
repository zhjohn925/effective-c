#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() 
{
    void *p;
    int iptr[] = {1, 2, 3, 4 };
    double dptr[] = {11.0, 12.0, 13.0};  //a 8-byte double element
    float fptr[] = {21.0, 22.0, 23.0};   //a 4-byte float element
    char *cptr = "hello the world";
    char str[30] = "wonderful sky";

    //1. pointer with a specific data type has
    //   info of address, size, and how to decode;
    //2. void pointer has info of address only 
    //   void pointer can point to any data type of pointers

    printf("point to an int: \n");
    p = iptr;
    //printf("%p: %d", p, *p);  can not read *p directly, since
    //void pointer has no info of size, and how to decode.
    printf("addr=%p: value=%d\n", p, *((int *)p));                                 // addr=0xffffcc00: value=1
    printf("sizeof(p)=%zu, sizeof(*p)=%zu\n", sizeof(p), sizeof(*p));              // sizeof(p)=8, sizeof(*p)=1
    printf("sizeof(iptr)=%zu, sizeof(*iptr)=%zu\n", sizeof(iptr), sizeof(*iptr));  // sizeof(iptr)=16, sizeof(*iptr)=4

    printf("point to a double: \n");
    p = dptr;
    printf("addr=%p: value=%f\n", p, *((double *)p));                              // addr=0xffffcbe0: value=11.000000
    printf("sizeof(p)=%zu, sizeof(*p)=%zu\n", sizeof(p), sizeof(*p));              // sizeof(p)=8, sizeof(*p)=1
    printf("sizeof(dptr)=%zu, sizeof(*dptr)=%zu\n", sizeof(dptr), sizeof(*dptr));  // sizeof(dptr)=24, sizeof(*dptr)=8

    printf("point to a float: \n");
    p = fptr;
    printf("addr=%p: value=%f\n", p, *((float *)p));                               // addr=0xffffcbd4: value=21.000000 
    printf("sizeof(p)=%zu, sizeof(*p)=%zu\n", sizeof(p), sizeof(*p));              // sizeof(p)=8, sizeof(*p)=1
    printf("sizeof(fptr)=%zu, sizeof(*fptr)=%zu\n", sizeof(fptr), sizeof(*fptr));  // sizeof(fptr)=12, sizeof(*fptr)=4

    printf("point to a string: \n");
    p = cptr;
    printf("addr=%p: value=%s\n", p, p);                               // addr=0xffffcbd4: value=21.000000
    printf("addr=%p: value=%s\n", p, (char *)p);        
    printf("sizeof(p)=%zu, sizeof(*p)=%zu\n", sizeof(p), sizeof(*p));              // sizeof(p)=8, sizeof(*p)=1
    printf("sizeof(cptr)=%zu, sizeof(*cptr)=%zu\n", sizeof(cptr), sizeof(*cptr));  // sizeof(fptr)=12, sizeof(*fptr)=4

    ///////////////////////////////////
    //void pointer usage:
    ///////////////////////////////////

    //the first parameter in memset() is void pointer
    memset(str, 'A', 5);  //init 5 bytes to 'A'
    printf("addr=%p: value=%s\n", str, str);  // addr=0xffffcbb0: value=AAAAArful sky

    p = str;
    memset(p, 'B', 5);  //init 5 bytes to 'B'
    printf("addr=%p: value=%s\n", p, p);  // addr=0xffffcbb0: value=BBBBBrful sky

    //Segmentation fault (core dumped)
    //memset() can not use char *cptr
    //memset(cptr, 'C', 5);
    //printf("addr=%p: value=%s\n", cptr, cptr);  // addr=0xffffcbb0: value=AAAAArful sky

    memset(iptr, 0, 8);  //init 8 bytes to 0
    for (int i=0; i<4; i++) {
        printf("%d ", iptr[i]);   // 0 0 3 4
    }
    printf("\n");

    memset(fptr, 0, 8);  //init 8 bytes to 0
    for (int i=0; i<3; i++) {
        printf("%f ", fptr[i]); // 0.000000 0.000000 23.000000
    }
    printf("\n");    

    return 0;
}