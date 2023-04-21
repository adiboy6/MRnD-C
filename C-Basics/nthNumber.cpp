/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	if (n > 0)
	{
		if (n == 1)
		{
			return 0;
		}
		else if (n == 2)
		{
			return 1;
		}
		else
		{
			int a = 0, b = 1, c;
			while (n != 2)
			{
				c = a + b;
				a = b;
				b = c;
				--n;
			}
			return c;
		}
	}
	else
	{
		return -1;
	}
}

int nthPrime(int num)
{
	int i = 0, j, n;
	if (num > 0)
	{
		for (n = 2; i != num; n++)
		{
			int flag = 1;
			for (j = 2; j < n; j++)
			{
				if (n%j == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				++i;
			}
		}
		return n - 1;
	}
	else
	{
		return -1;
	}
}