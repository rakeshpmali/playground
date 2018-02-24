#include<stdio.h>
#include<stdlib.h>

int main()
{
    int array[] = {23,65,11,35,98,72,51,84,27,44};
    int i = 0, j = 0, ncount = 10, temp = 0;

    printf("\nInput Array: \n");

    for(i=0;i<ncount;i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    //BUBBLE SORT
    for(i=0; i<ncount; i++)
    {
        for(j=0; j<ncount-1; j++)
        {
            if(array[j]>array[j+1])
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("\n\nSorted Array: \n");

    for(i=0;i<ncount;i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    printf("\n");
    return 0;
}
