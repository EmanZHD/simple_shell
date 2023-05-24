#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * _memset - this function fills memory with a constant byte
 * @pm: pointer to the memory area
 * @bt: byte to fill *pm with
 * @am: amount of bytes to be filled
 * Return: return (pm) a pointer to the memory area pm
 */
char *_memset(char *pm, char bt, unsigned int am)
{
	unsigned int i;

	for (i = 0; i < am; i++)
		pm[i] = bt;
	return (pm);
}

/**
 * flfree - this function frees a string of strings
 * @ss: the string of strings
 */
void flfree(char **ss)
{
	char **a = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(a);
}

/**
 * _realloc - this function reallocates a block of memory
 * @pr: the pointer to previous malloc'ated block
 * @pre_size: the byte size of previous block
 * @new_size: the byte size of new block
 * Return: return pointer
 */
void *_realloc(void *pr, unsigned int pre_size, unsigned int new_size)
{
	char *a;

	if (!pr)
		return (malloc(new_size));
	if (!new_size)
		return (free(pr), NULL);
	if (new_size == pre_size)
		return (pr);

	a = malloc(new_size);
	if (!a)
		return (NULL);

	pre_size = pre_size < new_size ? pre_size : new_size;
	while (pre_size--)
		a[pre_size] = ((char *)pr)[pre_size];
	free(pr);
	return (a);
}

