#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int x = 0, var = 111;
int fun1()
{
   return x;
}

int fun2()
{
   int x = 100;
   return fun1();
}

void statTest()
{
    static int iStat = 20;
}

int main()
{
//Block-main
    printf("x = %d\n", fun2());

    {
    //Block-1
        int x = 10, y  = 20;
        {
        //Block-2
            // The Block-1 contains declaration of x and y, so
            // following statement is valid and prints 10 and 20
            printf("x = %d, y = %d\n", x, y);
            {
            //Block-3
                int y = 40;
                // y is declared again in Block-3, 
                // so Block-2 y is not accessible in this block

                x++;  // changes Block-1 x to 11
                y++;  // Changes Block-3 y to 41

                printf("x = %d, y = %d\n", x, y);
            }

            // This statement accesses only Block-1 variables
            printf("x = %d, y = %d\n", x, y);
        }
    }
    
    // Block-main does not have any decleration of variable x
    // So, this statement accesses only global x
    printf("x = %d\n", x);

    {
    //Block-4
        int z =100;
    }
    {
    //Block-5
        /* This line gives complilation error: "'z' undeclared (first use in this function)" as Block-5 cannot access z from Block-4
        printf("z = %d\n", z);
        */
    }

    // global var
    printf("var = %d\n", var);

    int var = var;
    //First var is declared, then value is assigned to it. 
    //As soon as var is declared as a local variable, it hides the global variable var.
    //Here, var will be garbage value
    printf("var = %d\n", var);

    /*
    register int iVar = 10;
    int *iPtr = &iVar; // compilation error: address of register variable ‘iVar’ requested
    printf("%d", *iPtr);
    */

    int iVar = 10;
    register int *iPtr = &iVar;
    printf("*iPtr = iVar = %d\n", *iPtr);

    static int iStat = 10;
    statTest();
    printf("iStat = %d\n", iStat);

    return 0;
}
