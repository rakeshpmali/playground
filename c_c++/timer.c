#include<stdio.h>
#include<stdlib.h>

void addTime(int *ph, int *pm, int *ps, int sin);

void main()
{
    int h = 2, m = 45, s = 52, sin = 0;
    
    printf("Current Time: %d:%d:%d\n",h,m,s);
    printf("Enter Seconds to Add: ");
    scanf("%d",&sin);
    addTime(&h,&m,&s, sin);
    printf("New Time: %d:%d:%d\n",h,m,s);
}

void addTime(int *ph, int *pm, int *ps, int sin)
{
    if (sin == 60)
    {
        (*pm)++;
        *ps = 0;

    } else if (sin < 60)
    {
        int z = *ps + sin;
        
        while (z > 60)
        {
            z = z - 60;
            (*pm)++;
        }

        if (z == 60)
        {
            (*pm)++;
            z = 0;
        }
        
        *ps = z;
    } else if( sin > 60)
    {
        int z = sin;
        while (z > 60)
        {
            z = z - 60;
            (*pm)++;
        }

        z = z + *ps;
        while (z > 60)
        {
            z = z - 60;
            (*pm)++;
        }

        if (z == 60)
        {
            (*pm)++;
        }
        
        *ps = z;
    }  

    if (*pm == 60)
    {
        (*ph)++;
        *pm = 0;
    } else if(*pm > 60)
    {
        int z = *pm;
        while (z > 60)
        {
            z = z - 60;
            (*ph)++;
        }
        *pm = z;
    }
}

