#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct structa_tag
{
   char        c;
   short int   s;
} structa_t;
 
// structure B
typedef struct structb_tag
{
   short int   s;
   char        c;
   int         i;
} structb_t;
 
// structure C
typedef struct structc_tag
{
   char        c;
   double      d;
   int         s;
} structc_t;
 
// structure D
typedef struct structd_tag
{
   double      d;
   int         s;
   char        c;
} structd_t;

typedef struct
{
    int iData;
    char chStr[6];
} stTest;
 
int main()
{
    printf("sizeof(structa_t) = %d\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %d\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %d\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %d\n", sizeof(structd_t));

    stTest st1 = {1, "Test1"}; 
    stTest st2 = {2, "Test2"};

    st1 = st2;

    st2.iData = 0;
    strcpy(st2.chStr,"NULL");

    printf("St1: %d\t%s\n", st1.iData, st1.chStr); 
    printf("St2: %d\t%s\n", st2.iData, st2.chStr); 



    return 0;
}
