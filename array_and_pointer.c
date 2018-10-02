#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
   //generate array of random integer 
   time_t t;
   srand((unsigned int) time(&t));
   int rnd[10];
   for (int i=0; i<10; i++) {
      rnd[i] = rand() % 100;
      printf("rnd[%d]=%d\n", i, rnd[i]);
   }
   printf("\n");

   //rnd is pointer to the first array element
   //&rnd is pointer to the array
   printf("rnd=%p, &rnd=%p\n", rnd, &rnd);
   printf("%zu, %zu\n", sizeof(*rnd), sizeof(*(&rnd)));  //4, 40

   //num is constant pointer variable(immutable), pointing to the first element address.
   //p is pointer variable, mutable.
   int num[10] = {0,1,2,3,4,5,6,7,8,9};
   int *p = num;
   for (int i=0; i<10; i++) {
      //the below are equivalent
      printf("\n%d, %p", num[i], &num[i]);
      printf(" : %d, %p", *(num+i), num+i);
      printf(" : %d, %p", p[i], &p[i]);
      printf(" : %d, %p", *(p+i), p+i);
   }
   printf("\n");

   //read array by pointer iteration
   for (int *p=num; p<num+10; p++) {
      printf("\n%d, %p", *p, p);
   }
   printf("\n");

   int *ptr_element = num;     //pointer to the first element of array
   int (*ptr_array)[10] = &num;  //pointer to the array
   printf("sizeof(*ptr_element) = %zu\n", sizeof(*ptr_element));  //4
   printf("sizeof(*ptr_array) = %zu\n", sizeof(*ptr_array));      //40

   return 0;
}