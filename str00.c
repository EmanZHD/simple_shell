#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * _strglen - this function returns the length of a string
 * @st: string whose length to check
 * Return: return integer length of string
 */
int _strglen(char *st)
{
	int a = 0;

	if (!st)
		return (0);

	while (*st++)
		a++;
	return (a);
}

/**
 * _strgcmp - this function performs lexicogarphic comparison of two strangs
 * @frst: first strang
 * @scnd: second strang
 * Return: return negative if  < scnd, positive if frst > scnd,
 * zero if frst == scnd
 */
int _strgcmp(char *frst, char *scnd)
{
	while (*frst && *scnd)
	{
		if (*frst != *scnd)
			return (*frst - *scnd);
		frst++;
		scnd++;
	}
	if (*frst == *scnd)
		return (0);
	else
		return (*frst < *scnd ? -1 : 1);
}

/**
 * starts_with - this function checks if needle starts with haystack
 * @haystack: the string to search
 * @needle: substring to find
 * Return: return address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strgcat - this function concatenates two strings
 * @destb: destination buffer
 * @srcb: source buffer
 * Return: return pointer to destination buffer
 */
char *_strgcat(char *destb, char *srcb)
{
	char *r = destb;

	while (*destb)
		destb++;
	while (*srcb)
		*destb++ = *srcb++;
	*destb = *srcb;
	return (r);
}

