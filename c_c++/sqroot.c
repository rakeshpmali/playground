#include <stdio.h>
#include <stdlib.h>

float sqrt5(const float m)
{
    int j = 0;
   float i=0;
   float x1,x2;
   while( (i*i) <= m )
    {
          i+=0.1f;
            printf("\ni+=0.1f => %f", i);
    }
   x1=i;
            printf("\nx1 => %f", x1);
   for(j=0;j<10;j++)
   {
       x2=m;
            printf("\nx2 => %f", x2);
      x2/=x1;
            printf("\nx2 => %f", x2);
      x2+=x1;
            printf("\nx2 => %f", x2);
      x2/=2;
            printf("\nx2 => %f", x2);
      x1=x2;
            printf("\nx1 => %f", i);
   }
            printf("\nx2 => %f", i);
   return x2;
}  

void main()
{
    printf("\n%f\n", sqrt5(25));
}
