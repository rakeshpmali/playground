#include <stdio.h>

int main(void)
{
    int i = 10;
    const int j = 20;  
    int *iptr = &i;
    int *jptr = &j;   // Compilation Warning: initialization discards ‘const’ qualifier from pointer target type [enabled by default] 

    const int *ptr1 = &i, *ptr2 = &j;   // OR int const *ptr1 = &i, *ptr2 = &j;
    int *const ptrA = &i, ptrB = &j;    // Compilation Warning: initialization makes integer from pointer without a cast [enabled by default] 
 
    printf("Before:\t i=%d\t j=%d\n", i, j);
    *iptr = 100;    *jptr = 200;
    printf("After:\t i=%d\t j=%d\n", i, j);
   
    /* 
    *ptr1 = 500;    // Compilation Error: assignment of read-only location ‘*ptr1’
    *ptr2 = 500;    // Compilation Error: assignment of read-only location ‘*ptr2’
    printf("After:\t i=%d\t j=%d\n", i, j);
    */
   
    ptr1++;    // Allowed as ptr1 is not const pointer & it points to an integer i
    ptr2++;    // Allowed as ptr2 is not const pointer & it points to a const integer j
    
    /*
    *ptrA = 1000;    // Compilation Error: invalid type argument of unary ‘*’ (have ‘int’)
    *ptrB = 1000;    // Compilation Error: invalid type argument of unary ‘*’ (have ‘int’)
    */
    
    /*
    ptrA++;     // Compilation Error: increment of read-only variable ‘ptrA’
                // NOT Allowed as ptrA is const pointer (& it points to an integer i)
    ptrB++;     // Compilation Error: increment of read-only variable ‘ptrB’
                // NOT Allowed as ptrB is const pointer (& it points to a const integer j)
    */

    return 0;
}

/*  IMP Info (Read it backwards):

    int* - pointer to int
    int const * - pointer to const int
    int * const - const pointer to int
    int const * const - const pointer to const int

Now the first const can be on either side of the type so:

    const int * == int const *
    const int * const == int const * const

If you want to go really crazy you can do things like these:

    int ** - pointer to pointer to int
    int ** const - a const pointer to a pointer to an int
    int * const * - a pointer to a const pointer to an int
    int const ** - a pointer to a pointer to a const int
    int * const * const - a const pointer to a const pointer to an int
*/
