/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	if (num >= 0)
	{
		long long int rem, a, hex, m, sum = 0, i = 1;
		int final = 0;
		while (num != 0)
		{
			rem = num % 10;
			switch (rem)
			{
			case 0:a = 0;
				break;
			case 1:a = 1;
				break;
			case 2:a = 10;
				break;
			case 3:a = 11;
				break;
			case 4:a = 100;
				break;
			case 5:a = 101;
				break;
			case 6:a = 110;
				break;
			case 7:a = 111;
				break;
			}
			sum += i*a;
			i *= 1000;
			num /= 10;
		}
		i = 1;
		while (sum != 0)
		{
			hex = sum % 10000;
			switch (hex)
			{
			case 0:m = 0;
				break;
			case 1:m = 1;
				break;
			case 10:m = 2;
				break;
			case 11:m = 3;
				break;
			case 100:m = 4;
				break;
			case 101:m = 5;
				break;
			case 110:m = 6;
				break;
			case 111:m = 7;
				break;
			case 1000:m = 8;
				break;
			case 1001:m = 9;
				break;
			}
			final += m*i;
			i *= 10;
			sum /= 10000;
		}
		return final;
	}
	else
	{
		return 0;
	}
}
float octalToHexadecimalFraction(float num)
{
	int i, deci, hex;
	long double sum = 0, j = 1, a, m;
	float final = 0;
	if (num >= 0)
	{
		i = num;
		deci = octalToHexadecimalFraction(i);
		num -= i;
		while (num != 0)
		{
			num *= 10;
			i = num;
			switch (i)
			{
			case 0:a = 0;
				break;
			case 1:a = 0.001;
				break;
			case 2:a = 0.01;
				break;
			case 3:a = 0.011;
				break;
			case 4:a = 0.1;
				break;
			case 5:a = 0.101;
				break;
			case 6:a = 0.11;
				break;
			case 7:a = 0.111;
				break;
			}
			sum += a / j;
			j *= 1000;
			num *= 10;
			num -= i;
		}
		j = 1;
		while (sum != 0)
		{
			hex = sum * 10000;
			i = hex;
			switch (hex)
			{
			case 0:m = 0;
				break;
			case 1:m = 0.1;
				break;
			case 10:m = 0.2;
				break;
			case 11:m = 0.3;
				break;
			case 100:m = 0.4;
				break;
			case 101:m = 0.5;
				break;
			case 110:m = 0.6;
				break;
			case 111:m = 0.7;
				break;
			case 1000:m = 0.8;
				break;
			case 1001:m = 0.9;
				break;
			}
			final += m / j;
			j *= 10;
			sum *= 10000;
			sum -= i;
		}
		return final + deci;
	}
	else
	{
		return 0;
	}
}