#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

double add(int num, ...) {
   double res = 0.0;
   va_list argp;   //#define va_list char *
   va_start(argp, num);   //read number of parameters
   for (int i=0; i<num; i++) {
      res += va_arg(argp, double);
   }   
   va_end(argp);
   return res;
}

int main()
{
   double sum = add(3, 1.2, 2.2, 3.3);
   printf("sum = %f\n", sum);
   return 0;
}