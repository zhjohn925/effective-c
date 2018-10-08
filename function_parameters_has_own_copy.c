#include <stdlib.h>
#include <stdio.h>

//Confusing part:
//- &p : address to hold p
//-  p : address pointing to the value
//- *p : the value pointed by p

//function has its own location (&p) to hold p
void changePtr(int *p) {
   *p = 99;
   printf("changePtr():   &p=%p, p=%p, *p=%d\n", &p, p, *p);
}

void takeArray(int *arr) {
   printf("takeArray(), &arr=%p, arr=%p &arr[0]=%p\n", &arr, arr, &arr[0]);
}

//Compiler creates return copy (copy of c)
//Therefore, return copy of c,  not local variable c 
//local variable c was collected by garbage collector.
int add(int a, int b) {
   int c = a + b;
   return c;
}

//Output:
// main() before: &p=0x7ffee85dbaa0, p=0x7ffee85dbaa8, *p=11, &num=0x7ffee85dbaa8
// changePtr():   &p=0x7ffee85dba78, p=0x7ffee85dbaa8, *p=99
// main() after:  &p=0x7ffee85dbaa0, p=0x7ffee85dbaa8, *p=99, &num=0x7ffee85dbaa8

int main() 
{
   int num = 11;
   int *p = &num;
   printf("main() before: &p=%p, p=%p, *p=%d, &num=%p\n", &p, p, *p, &num);
   changePtr(p);
   printf("main() after:  &p=%p, p=%p, *p=%d, &num=%p\n", &p, p, *p, &num);
   
   // before takeArray(), &arr=0x7ffee6613aac, arr=0x7ffee6613aac
   // takeArray(), &arr=0x7ffee6613a68, arr=0x7ffee6613aac &arr[0]=0x7ffee6613aac

   int arr[] = {1, 2, 3};
   printf("before takeArray(), &arr=%p, arr=%p\n", &arr, arr);
   takeArray(arr);
   return 0;
}