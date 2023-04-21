/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str)
{
	if (str != NULL)
	{
		int i = 0, space, k = 0;
		while (str[i] != NULL)
		{
			if (str[i] == ' ')
			{
				space = i;
			}
			++i;
		}
		++space;
		char *last;
		last = (char *)malloc((space)*sizeof(char));
		while (str[space] != NULL)
		{
			last[k++] = str[space++];
		}
		last[k] = '\0';
		return last;
	}
	else
		return NULL;
}
