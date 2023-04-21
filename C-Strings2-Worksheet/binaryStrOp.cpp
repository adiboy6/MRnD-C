/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>


char *performOperation(char *str1, char *str2, char *operation){

	if (str1 != NULL&&str2 != NULL)
	{
		int i, max, j = 0, k = 0, l1 = 0, l2 = 0;
		char *a;
		for (l1 = 0; str1[l1] != '\0'; l1++);
		for (l2 = 0; str2[l2] != '\0'; l2++);
		i = l1 - 1;
		j = l2 - 1;
		if (l1 >= l2){
			a = (char*)malloc(l1*sizeof(char));
			max = l1;
			k = max - 1;
		}
		else
		{
			max = l2;
			k = max - 1;
			a = (char*)malloc(l2*sizeof(char));
		}
		if (operation[0] == 65)
		{
			while (i >= 0 && j >= 0)
			{
				if (str1[i] - 48 == 1 && str2[j] - 48 == 1)
				{
					a[k] = 49;
					k--;
					i--;
					j--;
				}
				else if (str1[i] - 48 == 0 || str2[j] - 48 == 0)
				{
					a[k] = 48;
					k--;
					i--;
					j--;
				}
			}
			if (i >= 0)
			{
				while (k >= 0)
				{
					a[k] = 48;
					k--;

				}
			}
			else if (j >= 0)
			{
				while (k >= 0)
				{
					a[k] = 48;
					k--;
				}
			}
		}
		else if (operation[0] == 'O')
		{
			while (i >= 0 && j >= 0)
			{
				if (str1[i] - 48 == 1 || str2[j] - 48 == 1)
				{
					a[k] = 49;
					k--;
					i--;
					j--;
				}
				else if (str1[i] - 48 == 0 && str2[j] - 48 == 0)
				{
					a[k] = 48;
					k--;
					i--;
					j--;
				}
			}
			if (i >= 0)
			{
				while (i >= 0)
				{
					a[k] = str1[i];
					k--;
					i--;
				}
			}
			else if (j >= 0)
			{
				while (j >= 0)
				{
					a[k] = str2[j];
					k--;
					j--;
				}
			}
		}
		else if (operation[0] == 'X')
		{
			while (i >= 0 && j >= 0)
			{
				if (str1[i] - 48 == str2[j] - 48)
				{
					a[k] = 48;
					k--;
					i--;
					j--;
				}
				else
				{
					a[k] = 49;
					k--;
					j--;
					i--;
				}
			}
			if (i >= 0)
			{
				while (i >= 0)
				{
					a[k] = str1[i];
					k--;
					i--;
				}
			}
			else if (j >= 0)
			{
				while (j >= 0)
				{
					a[k] = str2[j];
					k--;
					j--;
				}
			}
		}
		else if (operation[0] == 'N')
		{
			while (i >= 0 && j >= 0)
			{
				if (str1[i] - 48 == 0 && str2[j] - 48 == 0)
				{
					a[k] = 49;
					k--;
					i--;
					j--;
				}
				else {
					a[k] = 48;
					k--;
					j--;
					i--;
				}
			}
			if (i >= 0)
			{
				while (i >= 0)
				{
					if (str1[i] - 48 == 1){
						a[k] = 48;
						k--;
						i--;
					}
					else {
						a[k] = 49;
						k--;
						i--;
					}
				}
			}
			else if (j >= 0)
			{
				while (j >= 0)
				{
					if (str2[j] - 48 == 1){
						a[k] = 48;
						k--;
						j--;
					}
					else
					{
						a[k] = 49;
						k--;
						j--;
					}
				}
			}
		}
		else
			return 0;
		a[max] = '\0';
		return a;
	}
	else 
		return NULL;
}