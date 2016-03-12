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
int length_str(char *, int);
char ** commonWords(char *str1, char *str2) {

	char *p, *q, **s;
	int i, j = 0, k, n, l = 0, l1 = 0, l2 = 0;
	s = (char**)calloc(l1, sizeof(char));
	if (str1 == NULL || str2 == NULL)
		return NULL;
	l1 = length_str(str1, l1);
	l2 = length_str(str2, l2);
	if (l1>l2)
	{
		p = &str1[0];
		q = &str2[0];
	}
	else
	{
		q = &str1[0];
		p = &str2[0];
	}
	while (*p != '\0')
	{
		while (*p == ' ')
			p++;
		while (*q == ' ')
			q++;
		if (*p == '\0' || *q == '\0')
			return NULL;
		while (*p != *q&&*q != '\0'&&*p != '\0')
			q++;
		if (*p == *q)
		{
			n = 0;
			while (*p != ' '&&*q != ' '&&*p != '\0'&&*q != '\0')
			{
				if (*p == *q)
					n++;
				else
					break;
				p++;
				q++;
			}
			if ((*p == ' '&&*q == ' ') || (*p == '\0'&&*q == '\0') || (*p == ' '&&*q == '\0') || (*p == '\0'&&*q == ' '))
			{
				k = 0;
				i = 0;
				while (i<n)
				{
					i++;
					p--;
				}
				n--;
				s[l] = (char*)calloc(n, sizeof(char));
				while (k <= n&&*p != ' ')
				{
					s[l][k] = *p;
					p++;
					k++;
				}
				s[l][k] = '\0';
				p++;
				l++;
				if (l1>l2)
					q = str2;
				else
					q = str1;
			}
			else
			{
				p = p - n;
				while (*q != ' '&&*q != '\0')
					q++;
				if (*q == ' ')
					q++;
				if (*q == '\0')
				{
					if (l1>l2)
						q = str2;
					else
						q = str1;
					while (*p != ' ')
						p++;
				}
			}
		}
		else if (*p != '\0')
		{
			while (*p != ' '&&*(p + 1) != '\0')
				p++;
			p++;
			if (l1>l2)
				q = str2;
			else
				q = str1;
		}
	}
	return s;
}
int length_str(char *s, int l)
{
	while (s[l] != '\0')
		l++;
	return l;
}
