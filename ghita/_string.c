#include "shell.h"

/**
 * _strlen - Function that returns the length of a string.
 * @str: the pointer to a string
 * Return: return length of string
 */

int _strlen(char *str)
{
	int a = 0;

	while (str[a] != '\0')
		a++;
	return (a);
}

/**
 * _strcpy - Function that copy string from
 * the source into the destination string
 * @dest: the pointer to destionation string
 * @src: the pointer to src string
 * Return: return destination string
 */

char *_strcpy(char *dest, char *src)
{
	int a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _strcat - Function that appends src to dest
 * @dest: the pointer to destination string
 * @src: the pointer to src string
 * Return: return destination string
 */

char *_strcat(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	while (dest[a] != '\0')
		a++;
	b = 0;
	while (src[b] != '\0')
	{
		dest[a + b] = src[b];
		b++;
	}
	dest[a + b] = '\0';
	return (dest);
}

/**
 * _strcmp - Function that compares between two strings
 * @s1: the pointer to string
 * @s2: the pointer to string
 * Return: return 0 or s1[a], or s2[a]
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0;

	for (; s1[a] != '\0' && s2[a] != '\0' && s1[a] == s2[a]; a++)
		;

	return (s1[a] - s2[a]);
}

/**
 * _strdup - Function that allocate memory for a new string, and copy the
 * contents of the input string into the newly allocated memory
 * @s1: the string to be duplicated
 * Return: return pointer a pointer to the newly allocated duplicate string
 */

char *_strdup(const char *s1)
{
	char	*dup;
	int		a;

	a = 0;
	while (s1[a])
		a++;
	dup = (char *)malloc(sizeof(char) * a + 1);
	a = 0;
	if (!dup)
		return (NULL);
	while (s1[a])
	{
		dup[a] = s1[a];
		a++;
	}
	dup[a] = '\0';
	return (dup);
}

