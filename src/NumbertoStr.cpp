/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<stdlib.h>
int to_str(char *, int, int, int);
void dec_str(char *, float, int, int);

void number_to_str(float number, char *str, int afterdecimal){
	int n, i = 0, f1 = 0;
	float d;
	n = (int)number;
	if (n<0)
	{
		n = n*(-1);
		f1++;
		d = (-number) - n;
	}
	else
		d = number - n;
	i = to_str(str, n, f1, i);
	if (d<1 && afterdecimal>0)
	{
		str[i++] = '.';
		dec_str(str, d, afterdecimal, i);
	}
}
int to_str(char *str, int n, int f, int i)
{
	int r, m = n;
	char c;
	while (m>0)
	{
		m = m / 10;
		i++;
	}
	m = i;
	if (f == 1)
		i++;
	while (n >= 1 && i >= 0)
	{
		r = n % 10;
		c = r + 48;
		str[i - 1] = c;
		n = n / 10;
		i--;
	}
	if (f == 1)
	{
		str[i - 1] = '-';
		m++;
	}
	str[m] = '\0';
	return m;
}
void dec_str(char *str, float n, int afterdecimal, int i)
{
	int m;
	while (n<1 && afterdecimal>0)
	{
		m = n * 10;
		str[i] = m + 48;
		afterdecimal--;
		i++;
		n = (n * 10) - m;
	}
	str[i] = '\0';
}
