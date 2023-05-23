#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * _myhistry - this function displays the history list,
 * one command by line, preceded with line numbers, starting at 0
 * @info: the structure containing potential arguments. this used to maintain
 * constant function prototype
 * Return: return always 0
 */
int _myhistry(info_t *info)
{
	prnt_list(info->histry);
	return (0);
}

/**
 * unset_alia - this function sets alias to string
 * @info: the parameter struct
 * @strg: string alias
 * Return: return always 0 on success, and 1 on error
 */
int unset_alia(info_t *info, char *strg)
{
	char *pt, ch;
	int r;

	pt = _strgchr(strg, '=');
	if (!pt)
		return (1);
	ch = *pt;
	*pt = 0;
	r = delete_nd_at_index(&(info->alia),
		get_nd_index(info->alia, nd_starts_with(info->alia, strg, -1)));
	*pt = ch;
	return (r);
}

/**
 * set_alia - this function sets alias to string
 * @info: the parameter struct
 * @strg: string alias
 * Return: return always 0 on success, and 1 on error
 */
int set_alia(info_t *info, char *strg)
{
	char *pt;

	pt = _strgchr(strg, '=');
	if (!pt)
		return (1);
	if (!*++pt)
		return (unset_alia(info, strg));

	unset_alia(info, strg);
	return (add_nd_end(&(info->alia), strg, 0) == NULL);
}

/**
 * print_alia - this function prints an alias string
 * @nd: alias node
 * Return: return always 0 on success, and 1 on error
 */
int print_alia(list_t *nd)
{
	char *pt = NULL, *f = NULL;

	if (nd)
	{
		pt = _strgchr(nd->strg, '=');
		for (f = nd->strg; f <= pt; f++)
		_ptchar(*f);
		_ptchar('\'');
		_pts(pt + 1);
		_pts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalia - this function mimics the alias builtin (man alias)
 * @info: the structure containing potential arguments. Used to maintain
 * constant function prototype
 * Return: return always 0
 */
int _myalia(info_t *info)
{
	int k = 0;
	char *pt = NULL;
	list_t *nd = NULL;

	if (info->argc == 1)
	{
		nd = info->alia;
		while (nd)
		{
			print_alia(nd);
			nd = nd->nxt;
		}
		return (0);
	}
	for (k = 1; info->argv[k]; k++)
	{
		pt = _strgchr(info->argv[k], '=');
		if (pt)
			set_alia(info, info->argv[k]);
		else
			print_alia(nd_starts_with(info->alia, info->argv[k], '='));
	}

	return (0);
}

