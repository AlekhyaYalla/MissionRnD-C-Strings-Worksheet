/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	int l = 0;
	if (K<0 || str == '\0' || str == "")
		return '\0';
	while (str[l] != '\0')
		l++;
	if (K >= l)
		return '\0';
	else
		return str[l - K - 1];
}
