#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * add_nd - this function adds a node to the start of the list
 * @headnd: the address of pointer to headnd node
 * @strt: the strg field of node
 * @numb: the node index used by history
 * Return: return size of list
 */
list_t *add_nd(list_t **headnd, const char *strg, int numb)
{
	list_t *new_headnd;

	if (!headnd)
		return (NULL);
	new_headnd = malloc(sizeof(list_t));
	if (!new_headnd)
		return (NULL);
	_memset((void *)new_headnd, 0, sizeof(list_t));
	new_headnd->numb = numb;
	if (strg)
	{
		new_headnd->strg = _strgdup(strg);
		if (!new_headnd->strg)
		{
			free(new_headnd);
			return (NULL);
		}
	}
	new_headnd->nxt = *headnd;
	*headnd = new_headnd;
	return (new_headnd);
}

/**
 * add_nd_end - this function adds a node to the end of the list
 * @headnd: the address of pointer to headnd node
 * @strg: the strg field of node
 * @numb: the node index used by history
 * Return: return size of list
 */
list_t *add_nd_end(list_t **headnd, const char *strg, int numb)
{
	list_t *new_nd, *nd;

	if (!headnd)
		return (NULL);

	nd = *headnd;
	new_nd = malloc(sizeof(list_t));
	if (!new_nd)
		return (NULL);
	_memset((void *)new_nd, 0, sizeof(list_t));
	new_nd->numb = numb;
	if (strg)
	{
		new_nd->strg = _strgdup(strg);
		if (!new_nd->strg)
		{
			free(new_nd);
			return (NULL);
		}
	}
	if (nd)
	{
		while (nd->nxt)
			nd = nd->nxt;
		nd->nxt = new_nd;
	}
	else
		*headnd = new_nd;
	return (new_nd);
}

/**
 * print_list_strg - this function prints only the strg element of a list_t linked list
 * @h: the pointer to first node
 * Return: return size of list
 */
size_t print_list_strg(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->strg ? h->strg : "(nil)");
		_puts("\n");
		h = h->nxt;
		i++;
	}
	return (i);
}

/**
 * delete_nd_at_index - this function deletes node at given index
 * @headnd: the address of pointer to first node
 * @index: the index of node to delete
 * Return: return 1 on success, and 0 on failure
 */
int delete_nd_at_index(list_t **headnd, unsigned int index)
{
	list_t *nd, *prev_nd;
	unsigned int i = 0;

	if (!headnd || !*headnd)
		return (0);

	if (!index)
	{
		nd = *headnd;
		*headnd = (*headnd)->nxt;
		free(nd->strg);
		free(nd);
		return (1);
	}
	nd = *headnd;
	while (nd)
	{
		if (i == index)
		{
			prev_nd->nxt = nd->nxt;
			free(nd->strg);
			free(nd);
			return (1);
		}
		i++;
		prev_nd = nd;
		nd = nd->nxt;
	}
	return (0);
}

/**
 * free_list - this function frees all nodes of a list
 * @headnd_ptr: the address of pointer to headnd node
 * Return: return void
 */
void free_list(list_t **headnd_ptr)
{
	list_t *nd, *nxt_nd, *headnd;

	if (!headnd_ptr || !*headnd_ptr)
		return;
	headnd = *headnd_ptr;
	nd = headnd;
	while (nd)
	{
		nxt_nd = nd->nxt;
		free(nd->strg);
		free(nd);
		nd = nxt_nd;
	}
	*headnd_ptr = NULL;
}

