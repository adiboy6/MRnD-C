/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	char temp;
	int i = 0, j, k = 0, c, flag = 0;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
		{
			flag = 1;
		}
		++i;
	}
	len = i;
	j = i - 1;
	i = 0;
	while (i < j && flag == 1)
	{
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		i++;
		j--;
	}
	i = 0;
	while (input[i] != '\0' && flag == 1)
	{
		j = i - 1;
		if (i == len - 1)
		{
			j = len - 1;
		}
		if (input[i] == ' ' || i == len - 1)
		{
			c = j;
			while (k < j)
			{
				temp = input[k];
				input[k] = input[j];
				input[j] = temp;
				k++;
				j--;
			}
			k = c + 2;
		}
		++i;
	}
}