#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i1DArr[] = {10,50,20,60,30,70,40,80};
    int i2DArr[3][3] = {{10,50,20},{60,30,70},{40,80,90}};
    int i=0, j=0;
    
    //system("cls");

    printf("\n1 D Array - Subscript & Pointer Notation:\n"); 
    for(i=0;i<8;i++) 
    {
        printf("i1DArr[%d] = %d\t", i, i1DArr[i]);
        printf("*(i1DArr+%d) = %d\n", i, *(i1DArr+i));
    }
    
    printf("\n2 D Array - Subscript & Pointer Notation:\n"); 
    for(i=0;i<3;i++) 
    {
        for(j=0;j<3;j++) 
        {
            printf("i2DArr[%d][%d] = %d\t", i, j, i2DArr[i][j]);
            printf("*(i2DArr[%d]+%d) = %d\t", i, j, *(i2DArr[i]+j));
            printf("*(*(i2DArr+%d)+%d) = %d\n", i, j, *(*(i2DArr+i)+j));
            
            //printf("**(i2DArr+%d) = %d\n", i, **(i2DArr+i));
        }   
    }
}
