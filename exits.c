#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 **_strgncpy - this function copies a string
 *@dst: destination string to be copied to
 *@srcs: source string
 *@m: amount of characters to be copied
 *Return: return the concatenated string
 */
char *_strgncpy(char *dst, char *srcs, int m)
{
	int a, b;
	char *st = dst;

	a = 0;
	while (srcs[a] != '\0' && a < m - 1)
	{
		dst[a] = srcs[a];
		a++;
	}
	if (a < m)
	{
		b = a;
		while (b < m)
		{
			dst[b] = '\0';
			b++;
		}
	}
	return (st);
}

/**
 **_strgncat - this function concatenates two strings
 *@dst: first string
 *@srcs: econd string
 *@m: amount of bytes to be maximally used
 *Return: return the concatenated string
 */
char *_strgncat(char *dst, char *srcs, int m)
{
	int a, b;
	char *st = dst;

	a = 0;
	b = 0;
	while (dst[a] != '\0')
		a++;
	while (srcs[b] != '\0' && b < m)
	{
		dst[a] = srcs[b];
		a++;
		b++;
	}
	if (b < m)
		dst[a] = '\0';
	return (st);
}

/**
 **_strgchr - this function locates a character in a string
 *@st: the string to be parsed
 *@ch: the character to look for
 *Return: return (s) a pointer to the memory area s
 */
char *_strgchr(char *st, char ch)
{
	do {
		if (*st == ch)
			return (st);
	} while (*st++ != '\0');

	return (NULL);
}

