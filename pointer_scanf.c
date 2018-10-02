#include <stdlib.h>
#include <stdio.h>

int main()
{
   int num1 = 100;
   int num2 = 200;
   printf("%p, %p\n", &num1, &num2);
   
   //important to put NULL, otherwise, 
   //it is possible to get wild pointer
   int *p = NULL;  

   //input one of addresses (&num1, or &num2)
   //to init p
   scanf("%p", &p);
   printf("%p : %d\n", p, *p);
   return 0;
}