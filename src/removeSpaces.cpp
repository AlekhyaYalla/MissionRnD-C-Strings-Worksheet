/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char* mov_str(char *);
char removeSpaces(char *str) {

	int i = 0;
	char *p;
	if (str == '\0')
		return '\0';
	while (str[i] != '\0')
	{
		while (str[i] != ' '&&str[i] != '\0')
			i++;
		p = &str[i];
		if (str[i] == ' ')
		{
			p = mov_str(p);
			i++;
		}
	}
}
char* mov_str(char *p)
{
	int i = 0, j = i;
	while (p[i] != '\0')
	{
		while (p[i + 1] == ' ')
			i++;
		p[j] = p[i + 1];
		i++;
		j++;
	}
	return p;
}