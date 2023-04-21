/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	if (num >= 0)
	{
		int i = 1, sum = 0, rem;
		while (num != 0)
		{
			rem = num % 8;
			sum += rem*i;
			num /= 8;
			i *= 10;
		}
		return sum;
	}
	else
	{
		return 0;
	}
}

float decimalToOctalFraction(float num)
{
	if (num >= 0)
	{
		int i, deci;
		float sum = 0, j = 1;
		i = num;
		deci = decimalToOctal(i);
		num -= i;
		while (num != 0 && j != 100000)
		{
			num *= 8;
			i = num;
			num -= i;
			sum += i / j;
			j *= 10;
		}
		return sum + deci;
	}
	else
	{
		return 0;
	}
}