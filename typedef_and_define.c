#include <stdio.h>
#include <stdlib.h>

// #define is used to replace any words;
// no ";" at the end, otherwise, ";" is part of replacement
#define FP float *

//void (*X) (int) stands for a function pointer (ie. void print(int age) )
//the macro "FuncPtr(X)" is used to replace "void (*X) (int)"
#define FuncPtr(X) void (*X)(int) 

// typedef is alias to a known data type
// with ";" at the end             
typedef float * fp;  //alias to data types  

typedef void (*p)(int);   //p is alias to function type

void print(int age) {
   printf("You are %d years old.\n", age);
}


int main() {
   FP d1, d2;  //==>  float *d1,  d2;   //d1 is pointer, d2 is float
   fp d3, d4;  //==>  float *d3, *d4;   //both d3 and d4 are pointers

   //DP sizeof(d1)=8, sizeof(d2)=4
   printf("DP sizeof(d1)=%zu, sizeof(d2)=%zu\n", sizeof(d1), sizeof(d2));
   //dp sizeof(d3)=8, sizeof(d4)=8
   printf("dp sizeof(d3)=%zu, sizeof(d4)=%zu\n", sizeof(d3), sizeof(d4)); 

   //alias to function
   p f = print;
   f(10);   // You are 10 years old.

   //directly done by function pointer
   void (*funPtr)(int) = print;
   funPtr(18);  // You are 18 years old.

   //#define Macro
   FuncPtr(funPtr2) = print;
   funPtr2(33);  //You are 33 years old.

   return 0;
}