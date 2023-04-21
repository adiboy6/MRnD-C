/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int isSTRMatched(char *str1, char *str2){
	int i = 0, j = 0, len1 = 0, len2 = 0, k = 0, res = 0, n = 0;
	char *temp1, *temp2;
	temp1 = (char*)malloc(10000 * sizeof(char) + 1);
	temp2 = (char*)malloc(10000 * sizeof(char) + 1);
	if (str1 == NULL || str2 == NULL)
		return 1;

	while (str1[i] != '\0')
	{
		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			temp1[j] = ' ';
			j++;
			i++;
			len1++;
		}
		else if (str1[i] >= '1' && str1[i] <= '9')
		{
			while (str1[i] >= '0' && str1[i] <= '9')
			{
				k = str1[i] - '0';
				res = (res * 10) + k;
				i++;
			}
			len1 = len1 + res;
			for (n = 1; n <= res; n++)
			{
				temp1[j] = ' ';
				j++;
			}
			res = 0;
		}
		else
		{
			return 0;
		}
	}
	temp1[j] = '\0';
	i = 0;
	j = 0;

	while (str2[i] != '\0')
	{
		if (str2[i] >= 'a' && str2[i] <= 'z')
		{
			temp2[j] = ' ';
			j++;
			i++;
			len2++;
		}
		else if (str2[i] >= '1' && str2[i] <= '9')
		{
			while (str2[i] >= '0' && str2[i] <= '9')
			{
				k = str2[i] - '0';
				res = (res * 10) + k;
				i++;
			}
			len2 = len2 + res;
			for (n = 1; n <= res; n++)
			{
				temp2[j] = ' ';
				j++;
			}
			res = 0;
		}
		else
		{
			return 0;
		}
	}
	temp2[j] = '\0';
	i = 0;
	if (len1 != len2)
		return 0;
	while (i != len1)
	{
		if (temp1[i] == temp2[i] || temp1[i] == ' ' || temp2[i] == ' ')
			i++;
		else
			return 0;
	}
	return 1;
}