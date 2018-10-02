#include <stdio.h>
#include <stdlib.h>

//argc is number of strings when program is executed
//     including program name and its arguments;
//argv is an array pointer (double pointer), each element is pointer to string 

//$ a.out note crc
//output:
//  argc = 3
//  note
//  crc
int main(int argc, char *argv[])
{
   printf("argc = %d\n", argc);  //output 1 if no argument

   //skip the first which is program name
   //print arguments only
   for (int i=1; i<argc; i++) {
      printf("%d : %s\n", i, argv[i]);
   }
   printf("\n");

   while (argc>1) {
      argc--;
      argv++;                //forward the pointer
      printf("%s\n", *argv); //output arguments 
   }

   return 0;
}