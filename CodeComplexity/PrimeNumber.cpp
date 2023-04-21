/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

Way 1 : For Brute Force method, I took from 2 to (number - 1) and checked whether a number is prime or not. This wasn't the most efficient as it took a lot of time to complete the task; 

Way 2 : Using the square root method, it was a bit efficient as it took comapritively less time when compared to the Brute Force method. Square Root is kind of similar to halving the number but here we are dividing the number with root of its own. Hence we are decreasing the number steps less than half.

Way 3: Only odd numbers are primes except 2. Hence, in optimized method, we are eliminating the even number upto the square root of that number and this optimizesmuch more.

Conclusion : The optimized square root method decreases the time complexity and was the most most efficient way when compared with other two.
*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not.
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number)
{
	for (int i = 2; i < number-1; i++)
	{
		if (number%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

/*
Is checking division till number neccesary? 

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
int isPrimeSquareRoot(int number)
{
	double y = number;
	int x = sqrt(y);
	for (int i = 2; i <= x; i++)
	{
		if (number%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

/*
Add more optimizations you like, 
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number)
{
	double y = number;
	int x = sqrt(y);
	if (number % 2 == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 3; i <= x; i += 2)
		{
			if (number%i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
}