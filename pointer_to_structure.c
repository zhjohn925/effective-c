#include <stdio.h>
#include <stdlib.h>

int main() 
{
   struct s_info { char name[50]; int age; };
   struct s_info person[5] = {{"alex", 20}, {"john", 26}, {"brad",27},
                             {"crist", 18}, {"bit", 16}};

   //these are equivalent
   for (int i=0; i<5; i++) {
      printf("%d: %s %d\n", i, person[i].name, person[i].age);
   }       
   printf("----------------\n");
   for (int i=0; i<5; i++) {
      printf("%d: %s %d\n", i, (*(person+i)).name, (*(person+i)).age);
   }  
   printf("----------------\n");
   for (int i=0; i<5; i++) {
      printf("%d: %s %d\n", i, (person+i)->name, (person+i)->age);
   }      
   printf("----------------\n");
   for (struct s_info *pp=person; pp<(person+5); pp++) {
      printf("%s %d\n", pp->name, pp->age);
   }                  
   printf("----------------\n");
   for (struct s_info *pp=person; pp<(person+5); pp++) {
      printf("%s %d\n", (*pp).name, (*pp).age);
   }   
   
   return 0;
}