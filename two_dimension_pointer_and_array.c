#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   
   //two dimension array : each element holding a string
   char arr[3][9] = {"calc", "abc", "notepad"};
   //array pointer: each element holding a pointer to a string
   char *arrPtr[3] = {"alex", "david", "hello"};

   printf("%s\n", arr[0]);        //"calc"
   printf("%s\n", arrPtr[0]);     //"alex" 
   printf("%c, %c\n", arr[0][0], *(arr[0]));     //"c, c"
   printf("%c, %c\n", arrPtr[0][0], *(arrPtr[0]));  //"a, a" 
 
   //difference 1:
   // 3 * 9 = 27, each element holding a string (9B allocation) 
   printf("size of arr = %zu\n", sizeof(arr));
   // 3 * 8 = 24, each element holding a pointer to string 
   // 64-bit os has 8 bytes pointer
   printf("size of arrPtr = %zu\n", sizeof(arrPtr));

   //Note: modify string in pointer array, compile ok;
   //      but gets "Bus error: 10" when read the string
   //arrPtr[0][0] = 'A';
   //printf("%s\n", arrPtr[0]);     //fail
   
   //however, the pointers in pointer array are mutable
   //example to exchange two elements
   char *tmp = NULL;
   tmp = arrPtr[0];
   arrPtr[0] = arrPtr[1];
   arrPtr[1] = tmp; 
   printf("%s\n", arrPtr[0]);     //"david" 
   printf("%s\n", arrPtr[1]);     //"alex" 

   //Note: It is not OK to modify array address
   //this cause compile error:
   //arr[0] = arr[1];

   //However, it is ok to modify the string in 2D array
   arr[0][0] = 'C';
   printf("%s\n", arr[0]);        //"Calc"



   //the string in 2D array can be modified (mutable),
   //but string in pointer array can not be modified.
   printf("arr[0] = %s\n", arr[0]);  //"calc"
   arr[0][3] = '\0';
   printf("arr[0] = %s\n", arr[0]);  //"cal" 

   //randomization
   time_t ts; 
   srand((unsigned int)time(&ts));

   //do not use pointer before initialization !
   //otherwise, the *p can point to the protected area and
   //make program crash.
   //int *p;

   return 0;
}