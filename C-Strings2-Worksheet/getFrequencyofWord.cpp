/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int count_word_in_str_way_1(char *str, char *word)
{
	if (str != NULL)
	{
		int count = 0, wlen, k, j;
		for (wlen = 0; word[wlen] != '\0'; wlen++);
		for (int i = 0; str[i] != '\0'; i++)
		{
			k = 0;
			j = i;
			while (str[j] == word[k] && word[k] != '\0')
			{
				if (j - i == wlen-1)
				{
					++count;
					i += wlen-1;
				}
				++k;
				++j;
			}
		}
		return count;
	}
	else
		return NULL;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

