#include<stdio.h>
#include<strings.h>

void main()
{
    union uTest
    {
        int iVar;
        char cVar[15];
    } uTestVar;

    printf("\nSize of int = %d", sizeof(int));
    printf("\nSize of char = %d\n", sizeof(char));
    printf("\nSize of uTestVar = %d", sizeof(uTestVar));

    uTestVar.iVar = 65;
    printf("\niVar = %d", uTestVar.iVar);
    printf("\ncVar = %s", uTestVar.cVar);

    strcpy(uTestVar.cVar,"TEST");
    printf("\niVar = %d", uTestVar.iVar);
    printf("\ncVar = %s\n", uTestVar.cVar);

    struct stTest
    {
        int iVar;
        char cVar[15];
    } stTestVar;
    
    printf("\nSize of stTestVar = %d", sizeof(stTestVar));

    stTestVar.iVar = 65;
    printf("\niVar = %d", stTestVar.iVar);
    printf("\ncVar = %s", stTestVar.cVar);

    strcpy(stTestVar.cVar,"TEST");
    printf("\niVar = %d", stTestVar.iVar);
    printf("\ncVar = %s\n", stTestVar.cVar);


    typedef struct {
        int iVar;
        char cVar[10];
    } S_TEST;

    S_TEST stTestVar1 = {10, "TYPEDEF"};
    printf("\nSize of stTestVar1 = %d", sizeof(stTestVar1));

    printf("\niVar = %d", stTestVar1.iVar);
    printf("\ncVar = %s\n", stTestVar1.cVar);
} 
