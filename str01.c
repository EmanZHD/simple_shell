#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * _strgcpy - this function copies a string
 * @dst: destination
 * @sr: source
 * Return: return pointer to destination
 */
char *_strgcpy(char *dst, char *sr)
{
	int a = 0;

	if (dst == sr || sr == 0)
		return (dst);
	while (sr[a])
	{
		dst[a] = sr[a];
		a++;
	}
	dst[a] = 0;
	return (dst);
}

/**
 * _strgdup - this function duplicates a string
 * @strg: string to duplicate
 * Return: return pointer to the duplicated string
 */
char *_strgdup(const char *strg)
{
	int leng = 0;
	char *r;

	if (strg == NULL)
		return (NULL);
	while (*strg++)
		leng++;
	r = malloc(sizeof(char) * (leng + 1));
	if (!r)
		return (NULL);
	for (leng++; leng--;)
		r[leng] = *--strg;
	return (r);
}

/**
 * _pts - this function prints an input string
 * @strg: string to be printed
 * Return: return Nothing
 */
void _pts(char *strg)
{
	int a = 0;

	if (!strg)
		return;
	while (strg[a] != '\0')
	{
		_ptchar(strg[a]);
		a++;
	}
}

/**
 * _ptchar - this function writes the character c to stdout
 * @ch: character to print
 * Return: return on success 1, and on error,
 * -1 is returned, and errno is set appropriately
 */
int _ptchar(char ch)
{
	static int a;
	static char bufr[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, bufr, a);
		a = 0;
	}
	if (ch != BUF_FLUSH)
		bufr[a++] = ch;
	return (1);
}

