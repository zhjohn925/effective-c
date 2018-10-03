#include <stdlib.h>
#include <stdio.h>

double d1 = 33.3, d2 = 99.9;

//the upper-level-pointer can be used to change lower-level-pointer
//ie. 2-level-pointer (**pp) is used to change 1-level-pointer
void changePtr(double **pp) {
    *pp = &d2;     // ==> *(*pp) = d2
}

int main() {

    double *p = &d1; 
    //p pointing to d1    
    printf("%p: %f\n", p, *p);  // 0x100402010: 33.300000

    changePtr(&p);  //change p pointing to d2
    printf("after changePtr(), %p: %f\n", p, *p);  // after changePtr(), 0x100402018: 99.900000

    //the upper-level-pointer can be used to change lower-level-pointer
    //p4 --> p3 --> p2 ---> p1 ---> num = 100
    //     (*p4)  (**p4)  (***p4)  (****p4)
    int    numA = 100, numB = 200;
    int    *p1 = &numA;
    int   **p2 = &p1;
    int  ***p3 = &p2;
    int ****p4 = &p3;

    // p4: 0xffffcbf0, 0xffffcbf8, 0xffffcc00, 0xffffcc0c, ****p4 = 100
    // p3: 0xffffcbf8,  ***p3 = 100
    // p2: 0xffffcc00,   **p2 = 100
    // p1: 0xffffcc0c,    *p1 = 100
    printf("p4: %p, %p, %p, %p, ****p4 = %d\n", p4, *p4, **p4, ***p4, ****p4);    
    printf("p3: %p,  ***p3 = %d\n", p3,  ***p3);     
    printf("p2: %p,   **p2 = %d\n", p2,   **p2);     
    printf("p1: %p,    *p1 = %d\n", p1,    *p1);     

    //compiler warning: assignment from incompatible pointer type
    //  p4 = &numA; 
    // *p4 = &numA;
    //**p4 = &numA;

    //The below demo changes 1-level-pointer thru 4-level-pointer
    //p4, p3, p2 do not change address, only p1 pointing to numB
    //Now all pointers pointing to numB (200) at the end
    ***p4 = &numB;
    printf("*(***p4) = %d\n", ****p4);  // *(***p4) = 200

    // p4: 0xffffcbf0, 0xffffcbf8, 0xffffcc00, 0xffffcc08, ****p4 = 200
    // p3: 0xffffcbf8,  ***p3 = 200
    // p2: 0xffffcc00,   **p2 = 200
    // p1: 0xffffcc08,    *p1 = 200
    printf("p4: %p, %p, %p, %p, ****p4 = %d\n", p4, *p4, **p4, ***p4, ****p4);    
    printf("p3: %p,  ***p3 = %d\n", p3,  ***p3);     
    printf("p2: %p,   **p2 = %d\n", p2,   **p2);     
    printf("p1: %p,    *p1 = %d\n", p1,    *p1);  

}