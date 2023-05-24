#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * bffree - this function frees a pointer and NULLs the address
 * @ptrf: the address of the pointer to free
 * Return: return 1 if freed, otherwise 0
 */
int bffree(void **ptrf)
{
	if (ptrf && *ptrf)
	{
		free(*ptrf);
		*ptrf = NULL;
		return (1);
	}
	return (0);
}

