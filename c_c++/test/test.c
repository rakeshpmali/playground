#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i = 5;
    int j = i++;
    int k = i++ + ++i;
    printf("%d %d %d", i, j, k);
    //printf("\n This is a Test \n");
}
