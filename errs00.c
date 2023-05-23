#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * _epts - this function prints an input string
 * @strg: string to be printed
 * Return: return nothing
 */
void _epts(char *strg)
{
	int a = 0;

	if (!strg)
		return;
	while (strg[a] != '\0')
	{
		_eptchar(strg[a]);
		a++;
	}
}

/**
 * _eptchar - this functino writes the character c to stderr
 * @ch: character to print
 * Return: return on success 1
 * and on error, -1 is returned, and errno is set appropriately
 */
int _eptchar(char ch)
{
	static int a;
	static char bufr[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, bufr, a);
		a = 0;
	}
	if (ch != BUF_FLUSH)
		bufr[a++] = ch;
	return (1);
}

/**
 * _ptfd - this function writes the character c to given fd
 * @ch: character to print
 * @fdd: filedescriptor to write to
 * Return: return n success 1
 * and on error, -1 is returned, and errno is set appropriately
 */
int _ptfd(char ch, int fdd)
{
	static int a;
	static char bufr[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fdd, bufr, a);
		a = 0;
	}
	if (ch != BUF_FLUSH)
		bufr[a++] = ch;
	return (1);
}

/**
 * _ptsfdd - this function prints an input string
 * @strg: string to be printed
 * @fdd: filedescriptor to write to
 * Return: return the number of chars put
 */
int _ptsfdd(char *strg, int fdd)
{
	int a = 0;

	if (!strg)
		return (0);
	while (*strg)
	{
		a += _ptfdd(*strg++, fdd);
	}
	return (a);
}

