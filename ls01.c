#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * list_len - this function determines length of linked list
 * @fn: the pointer to first node
 * Return: return size of list
 */
size_t list_len(const list_t *fn)
{
	size_t sz = 0;

	while (fn)
	{
		fn = fn->nxt;
		sz++;
	}
	return (sz);
}

/**
 * list_to_strings - this function returns
 * an array of strings of the list->str
 * @headpt: the pointer to first node
 * Return: return array of strings
 */
char **list_to_strings(list_t *headpt)
{
	list_t *nd = headpt;
	size_t sz = list_len(headpt), i;
	char **strgs;
	char *strg;

	if (!headpt || !sz)
		return (NULL);
	strgs = malloc(sizeof(char *) * (sz + 1));
	if (!strgs)
		return (NULL);
	for (sz = 0; nd; nd = nd->nxt, sz++)
	{
		strg = malloc(_strglen(nd->strg) + 1);
		if (!strg)
		{
			for (i = 0; i < sz; i++)
				free(strgs[i]);
			free(strgs);
			return (NULL);
		}

		strg = _strgcpy(strg, nd->strg);
		strgs[sz] = strg;
	}
	strgs[sz] = NULL;
	return (strgs);
}


/**
 * prnt_list - this function prints all elements of a list_t linked list
 * @fn: the pointer to first node
 * Return: return size of list
 */
size_t prnt_list(const list_t *fn)
{
	size_t sz = 0;

	while (fn)
	{
		_pts(cnvrt_numb(fn->numb, 10, 0));
		_ptchar(':');
		_ptchar(' ');
		_pts(fn->strg ? fn->strg : "(nil)");
		_pts("\n");
		fn = fn->nxt;
		sz++;
	}
	return (sz);
}

/**
 * nd_starts_with - this function returns node whose string starts with prefix
 * @nd: the pointer to list head
 * @prfix: the string to match
 * @ch: the next character after prefix
 * Return: return match nod or null
 */
list_t *nd_starts_with(list_t *nd, char *prfix, char ch)
{
	char *pt = NULL;

	while (nd)
	{
		pt = starts_with(nd->strg, prfix);
		if (pt && ((ch == -1) || (*pt == ch)))
			return (nd);
		nd = nd->nxt;
	}
	return (NULL);
}

/**
 * get_nd_index - this function gets the index of a node
 * @headpt: the pointer to list head
 * @nd: the pointer to the node
 * Return: return index of node or -1
 */
ssize_t get_nd_index(list_t *headpt, list_t *nd)
{
	size_t sz = 0;

	while (headpt)
	{
		if (headpt == nd)
			return (sz);
		headpt = headpt->nxt;
		sz++;
	}
	return (-1);
}

