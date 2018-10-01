#include <stdio.h>
#include <stdlib.h>

int main() 
{
    void *p;
    int iptr[] = {1, 2, 3, 4 };
    double dptr[] = {11.0, 12.0, 13.0};
    float fptr[] = {21.0, 22.0, 23.0};
    char *cptr = "hello the world";

    //1. pointer with a specific data type has
    //   info of address, size, and how to decode;
    //2. void pointer has info of address only 
    //   void pointer can point to any data type of pointers

    p = iptr;
    //printf("%p: %d", p, *p);  can not read *p directly, since
    //void pointer has no info of size, and how to decode.
    printf("addr=%p: value=%d\n", p, *((int *)p));                                 // addr=0xffffcc00: value=1
    printf("sizeof(p)=%zu, sizeof(*p)=%zu\n", sizeof(p), sizeof(*p));              // sizeof(p)=8, sizeof(*p)=1
    printf("sizeof(iptr)=%zu, sizeof(*iptr)=%zu\n", sizeof(iptr), sizeof(*iptr));  // sizeof(iptr)=16, sizeof(*iptr)=4

    p = dptr;
    printf("addr=%p: value=%f\n", p, *((double *)p));                              // addr=0xffffcbe0: value=11.000000
    printf("sizeof(p)=%zu, sizeof(*p)=%zu\n", sizeof(p), sizeof(*p));              // sizeof(p)=8, sizeof(*p)=1
    printf("sizeof(dptr)=%zu, sizeof(*dptr)=%zu\n", sizeof(dptr), sizeof(*dptr));  // sizeof(dptr)=24, sizeof(*dptr)=8

    p = fptr;
    printf("addr=%p: value=%f\n", p, *((float *)p));                               // addr=0xffffcbd4: value=21.000000
    printf("sizeof(p)=%zu, sizeof(*p)=%zu\n", sizeof(p), sizeof(*p));              // sizeof(p)=8, sizeof(*p)=1
    printf("sizeof(fptr)=%zu, sizeof(*fptr)=%zu\n", sizeof(fptr), sizeof(*fptr));  // sizeof(fptr)=12, sizeof(*fptr)=4

    printf("point to a string: \n");
    p = cptr;
    printf("addr=%p: value=%s\n", p, *((char *)p));                               // addr=0xffffcbd4: value=21.000000
    printf("sizeof(p)=%zu, sizeof(*p)=%zu\n", sizeof(p), sizeof(*p));              // sizeof(p)=8, sizeof(*p)=1
    printf("sizeof(cptr)=%zu, sizeof(*cptr)=%zu\n", sizeof(cptr), sizeof(*cptr));  // sizeof(fptr)=12, sizeof(*fptr)=4

    return 0;
}