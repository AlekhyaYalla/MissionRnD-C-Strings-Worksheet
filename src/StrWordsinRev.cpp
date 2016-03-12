/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
char* reverse(char*, int);
void str_words_in_rev(char *input, int len){
	char *p, *q;
	int i = 0;
	input = reverse(input, len);
	p = input;
	while (*p != '\0')
	{
		q = p;
		i = 0;
		while (*p != ' '&&*p != '\0')
		{
			i++;
			p++;
		}
		q = reverse(q, i);
		if (*p != '\0')
			p++;
	}
}
char* reverse(char *s, int n)
{
	char *a, *b, t;
	a = s;
	b = &s[n - 1];
	while (a <= b)
	{
		t = *a;
		*a = *b;
		*b = t;
		a++;
		b--;
	}
	return s;
}
