/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>
void count_vowels_and_consonants(char *str, int *consonants, int *vowels)
{
	int i = 0, ch;
	if (str==NULL)
	{
		*consonants = 0;
		*vowels = 0;
		return;
	}
	*consonants = 0;
	*vowels = 0;
	while (str[i] != NULL)
	{
		ch = str[i];
		if ((ch >= 66 && ch <= 68) || (ch >= 70 && ch <= 72) || (ch >= 74 && ch <= 78) || (ch >= 80 && ch <= 84) || (ch >= 86 && ch <= 90) || (ch >=98  && ch <= 100) || (ch >= 102 && ch <= 104) || (ch >= 106 && ch <= 110) || (ch >= 112 && ch <= 116) || (ch >= 118 && ch <= 122) )
		{
			++(*consonants);
		}
		if (ch == 65 || ch == 69 || ch == 73 || ch == 79 || ch == 85 || ch == 97 || ch == 101 || ch == 105 || ch == 117)
		{
			++(*vowels);
		}
		++i;
	}
}
