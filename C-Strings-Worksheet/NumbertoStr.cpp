/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void number_to_str(float number, char *str,int afterdecimal)
{
	if (number > 0)
	{
		float point;
		int n, len = 0, p, lenx;
		n = number;
		while (n)
		{
			n /= 10;
			++len;
		}
		lenx = len;
		n = number;
		while (n)
		{
			str[len - 1] = n % 10 + '0';
			n /= 10;
			--len;
		}
		n = number;
		if (afterdecimal != 0)
		{
			str[lenx] = '.';
			point = number - n;
			point *= 10;
			p = point;
			while (point != 0 && afterdecimal != 0)
			{
				++lenx;
				str[lenx] = p + '0';
				point = point - p;
				point *= 10;
				p = point;
				--afterdecimal;
			}
			str[++lenx] = '\0';
		}
		else
		{
			str[lenx] = '\0';
		}
	}
	if (number < 0)
	{
		number = -number;
		float point;
		int n, len = 0, p, lenx;
		n = number;
		while (n)
		{
			n /= 10;
			++len;
		}
		lenx = len + 1;
		n = number;
		while (n)
		{
			str[len] = n % 10 + '0';
			n /= 10;
			--len;
		}
		str[0] = '-';
		n = number;
		if (afterdecimal != 0)
		{
			str[lenx] = '.';
			point = number - n;
			point *= 10;
			p = point;
			while (point != 0 && afterdecimal != 0)
			{
				++lenx;
				str[lenx] = p + '0';
				point = point - p;
				point *= 10;
				p = point;
				--afterdecimal;
			}
			str[++lenx] = '\0';
		}
		else
		{
			str[lenx] = '\0';
		}
	}
}
