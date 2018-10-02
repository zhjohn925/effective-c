#include <stdlib.h>
#include <stdio.h>

int add(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }
int mul(int a, int b) { return a*b; }
int divide(int a, int b) { return a/b; }
int mod(int a, int b) { return a%b; }

int main() {

   int (*px)[5];
   *(px[0]) = 1;

   //function pointer
   int (*p)(int, int) = add;
   //p = add;
   printf("(*p)(100, 20) = %d\n", (*p)(100, 20));
   
   //array of function pointers:
   //pn is array of pointers (each element is a pointer to a function)
   int (*pn[5])(int, int);// = {add, sub, mul, divide, mod};
   //OR:
   pn[0] = add;    //function name is address pointing to function entry
   pn[1] = sub;
   pn[2] = mul;
   pn[3] = divide;
   pn[4] = mod;
/*
   //reference by indice
   for (int i = 0; i<5; i++) {
      printf("(pn[%d])(100, 20) = %d\n", i, (pn[i])(100, 20));
   }
   //reference by double pointers
   for (int (**pp)(int, int)=pn; pp<pn+5; pp++) {
      printf("(*pp)(100, 20) = %d\n", (*pp)(100, 20));
   }
*/
   return 0;
}