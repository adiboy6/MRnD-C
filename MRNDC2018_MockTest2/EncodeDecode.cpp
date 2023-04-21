/*
ProblemCode : EncodeDecode

An instructor is running a coding course online for hundreds of students, He frequently conducts online tests for 
students to keep them up to date with new questions etc. But he is repeatedly observing that some group of students
are always copying and are submitting same solutions. As he has no other option left he decided to conduct final test
at a offline center where he can personally invigilate so that no one copies. He allows access for net so that 
students can get some theory concepts cleared during test time, but as expected Ram and Sham of the students are
again planning on sharing their answers through net.
Based on previous experiences, the instructor is sure that they will copy no matter how many times "Dont Copy" 
instructions were given etc. So he installed spoofers which will track their net usage and see if any meaningfull
data is being shared etc So that they can be caught.

Ram and Sham being very smart, started to design a encryption algorithm with which they can communicate with each
other without being detected. They also have designed decryption algortihm to know actual message.

Their message is simple, They want to pass the code (String) without being detected over network.
Like if ram wants to send abcde he will send it as cbdae to Sham, Sham decodes it again back to abcde.

Encryption/Encoding Algortihm : 
-> Initially encoded string will be empty;
-> Given an String, Each time the middle char of string will be picked, and appened to encoded string.
Ie if string is sanji, First n will be picked.
EncodedStr will be "n", Remaning message is "saji", "a" will be picked (In case of even letters, left most middle will be picked)
EncodedStr will be "na", Remaining message is "sji"."j" will be picked.
Encoded Str is "naj", Remaining Msg is "si". "s" will be picked. followed by i.
Final encoded str will be "najsi".

Similarly for Franky, Encoded Str will be anrkfy.

Decoding Algorithm : 
-> Opposite of above. Given "anrkfy" as initial message, it will be decoded to franky.

Some more examples :
-> luffy ----[Enc]---> fufly ---- [Dec]--> luffy

Your aim of this question is to help your friends Ram and Sham by implementing encode and decode functions so that they can pass
the exam :D.

Marks : 7 for Encode, 8 for decode . You need to write a O(n) solution to fetch full marks.

Notes : Return Empty Strings for Null inputs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decode(char *);
char *encode(char *);

void testEncodeDecode() {
	char * message = "luffy";
	char * encoded = encode(message);
	printf("Message : %s, Encoded : %s\n", message, encoded);
	printf("ReEncoding from Decoded String is %s\n", decode(encoded));
	//Write your sample inputs and outputs here.
}

char * encode(char *str) {
	if (str==NULL)
		return NULL;
	char *a,*s1;
	int i = 0,j=0,k=0, len1 = 0;
	for (; str[len1] != NULL; len1++);
	a = (char *)malloc(sizeof(char)*len1);
	s1 = (char *)malloc(sizeof(char)*len1);
	while (str[j] != NULL)
		s1[k++] = str[j++];
	s1[k] = NULL;
	while (len1 != 0)
	{
		if (len1 % 2 == 1)
		{

			a[i++] = s1[len1 / 2];
			for (int m = len1 / 2; s1[m] != NULL; m++)
				s1[m] = s1[m + 1];
		}
		else
		{
			a[i++] = s1[len1 / 2 - 1];
			for (int n = len1 / 2 - 1; s1[n] != NULL; n++)
				s1[n] = s1[n + 1];
		}
		--len1;
	}
	a[i] = NULL;
	return a;
}

char* decode(char *str) {
	if (str==NULL)
	return NULL;
	int len2 = strlen(str);
	char *b;
	int p = 0, q = 0, s;
	q = len2 - 1;
	s = len2 - 1;
	b = (char *)malloc(sizeof(char)*len2);
	for (int r = 1; r <= len2; r++)
	{
		if (r % 2)
			b[q--] = str[s--];
		else
			b[p++] = str[s--];
	}
	b[len2] = NULL;
	return b;
}