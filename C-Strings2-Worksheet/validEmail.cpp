/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>


int isValidEmail(char *email)
{
	// variable email is in form of "name something@domain.server"
	int i = 0, flag = 0, fspace, space, atrate, atrate_c = 0, dot_c = 0, natrate, f, k, j, l, space_c = 0;
	while (email[i] != NULL)
	{
		if (email[i] == ' ')
		{
			if (flag == 0)
			{
				fspace = i;
				flag = 1;
			}
			++space_c;
			if (email[i + 1] != ' ' && email[i+1]!=NULL)
			{
				space = i;
			}
		}
		if (email[i] == '<' || email[i] == '>' || email[i] == '(' || email[i] == ')' || email[i] == '[' || email[i] == ']' || email[i] == ';' || email[i] == ':' || email[i] == ',' || email[i] == 92)
		{
			return 0;
		}
		if (email[i] == '@')
		{
			atrate = i;
			++atrate_c;
			if (atrate_c > 1)
			{
				return 0;
			}
		}
		if (email[i] == '.')
		{
			++dot_c;
		}
		++i;
	}
	if (atrate_c < 1 || space_c<1)
	{
		return 0;
	}
	if (dot_c < 1 || i>254 || email[atrate + 1] == '.' || email[space + 1] == '-' || email[space + 1] == '_' || email[space + 1] == '.' || email[atrate - 1] == '-' || email[atrate - 1] == '_' || email[atrate - 1] == '.')
	{
		return 0;
	}
	f = fspace;
	while (f < space)
	{
		if (email[f] != ' ')
		{
			return 0;
		}
		++f;
	}
	natrate = atrate + 1;
	while (natrate < i)
	{
		if ((email[natrate] == email[natrate + 1] && email[natrate] == '.') )
		{
			return 0;
		}
		++natrate;
	}
	for (j = space + 1; j < atrate; j++)
	{
		k = 0;
		l = j;
		while ((email[k] == email[l] || email[k] == email[l] + 32 || email[k] + 32 == email[l]) && k < fspace)
		{
			if (k == l - j && (j - 1 == space || l + 1 == atrate) && k + 1== fspace)
			{
				return 2;
			}
			++k;
			++l;
		}
	}
	return 1;
}