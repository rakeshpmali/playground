#include<stdio.h>

void main()
{
    int x = 0x00000008;
    unsigned int y = 0x00000008;
    printf("%x\n", x >> 1); //sign extension occurs (Arithmetic Shift)
    printf("%x\n", y >> 1); //no sign extension (Logical Shift)

    printf("%x\n", x << 1);
    printf("%x\n", y << 1);


}