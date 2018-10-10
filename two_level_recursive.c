#include <stdlib.h>
#include <stdio.h>

//calculate 1+1*2+1*2*3+...+(1*2*3*...n)

//the first recursive
int mul_recur(int n) {
   if (n==1) return 1;
   return n*mul_recur(n-1);
}

int add_recur(int n) {
   if (n==1) return 1;
   return mul_recur(n) + add_recur(n-1); 
}

int main() {
   int n = 4;
   printf("two_level_recur: %d\n", add_recur(n));
}