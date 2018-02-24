#include<stdio.h>

void printBinary(int n)
{
	unsigned i;
    for (i = 1 << 16; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
	printf("\n");
}

void main()
{
	unsigned int num = 2707, i = 0b101010010011, j = 0xA93, k = 05223;

	printf("\n%d\t", num);	
	printBinary(num);

	printf("\n%d\t", i);	
	printBinary(i);

	printf("\n%x\t", j);	
	printBinary(j);

	printf("\n%o\t", k);	
	printBinary(j);

	unsigned int num1 = 0b0101, num2 = 0b0010, result = 0;
	
	printf("\nnum1 = %d\t", num1);
	printBinary(num1);
	printf("\nnum2 = %d\t", num2);
	printBinary(num2);

	result = num1 & num2;       
	printf("\nnum1 & num2 = %d\t", result);	
	printBinary(result);

	result = num1 | num2;       
	printf("\nnum1 | num2 = %d\t", result);	
	printBinary(result);

	result = num1 ^ num2;       
	printf("\nnum1 ^ num2 = %d\t", result);	
	printBinary(result);

	result = ~num1;
	printf("\n~num1 = %d\t", result);
	printBinary(result);
	
	result = ~num2;
	printf("\n~num2 = %d\t", result);
	printBinary(result);

	result = num1 << 1;       
	printf("\nnum1 << 1 = %d\t", result);	
	printBinary(result);

	result = num1 >> 1;       
	printf("\nnum1 >> 1 = %d\t", result);	
	printBinary(result);

	signed char a=-8;
    printf("%d\t",a);
	printBinary(a);
    signed char b= a >> 1;
    printf("%d\t",b);
	printBinary(b);

	unsigned char c=-8;
    printf("%d\t",c);
	printBinary(c);
    signed char d= c >> 1;
    printf("%d\t",d);
	printBinary(d);
}
