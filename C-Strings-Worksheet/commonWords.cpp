/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2)
{
	int len1, len2, wlen1, wlen2, m = 0, n = 0, c = 0, word, k, l;
	char **output;
	output = (char **)malloc(2);
	if (str1 == NULL || str2 == NULL || (str1[0] == str2[0] && str1[0] == ' ' && str2[0] == ' '))
	{
		return NULL;
	}

	for (len1 = 0; str1[len1] != '\0'; len1++);
	for (len2 = 0; str2[len2] != '\0'; len2++);
	for (int i = 0; i <= len1; i++)
	{
		if (str1[i] == ' ' || str1[i] == '\0')
		{
			wlen1 = i - m;
			m = i + 1;
			n = 0;
			for (int j = 0; j <= len2; j++)
			{
				if (str2[j] == ' ' || str2[j] == '\0')
				{
					wlen2 = j - n;
					n = j + 1;
					if (wlen1 == wlen2)
					{
						++c;
						output = (char**)realloc(output, sizeof(*output));
						output[c - 1] = (char*)malloc(SIZE*sizeof(char));
						word = 0;
						k = i - wlen1;
						l = j - wlen2;
						while (str1[k] == str2[l] && (word < wlen1 || word < wlen2))
						{
							output[c - 1][word] = str1[k];
							++word;
							++k;
							++l;
						}
						if (word == wlen1)
						{
							output[c - 1][word] = '\0';
							break;
						}
						else if (word > 0 && word != wlen1)
						{
							while (word >= 0)
							{
								output[c - 1][word] = NULL;
								--word;

							}
							--c;
						}
						else
						{
							--c;
						}
					}
				}
			}
		}
	}
	if (c != 0)
	{
		return output;
	}
	else return NULL;
}