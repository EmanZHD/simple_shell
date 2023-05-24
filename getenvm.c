#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * get_environ - this function returns the string array copy of our environ
 * @info: the structure containing potential arguments.
 * this used to maintain constant function prototype
 * Return: return always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->envr_changed)
	{
		info->environ = list_to_strings(info->envr);
		info->envr_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenvr - this function remove an environment variable
 * @info: the structure containing potential arguments.
 * this used to maintain constant function prototype
 * Return: return 1 on delete, 0 otherwise
 * @varenv: string env var property
 */
int _unsetenvr(info_t *info, char *varenv)
{
	list_t *nd = info->envr;
	size_t a = 0;
	char *pt;

	if (!nd || !varenv)
		return (0);

	while (nd)
	{
		pt = starts_with(nd->strg, varenv);
		if (pt && *pt == '=')
		{
			info->envr_changed = delete_nd_at_index(&(info->envr), a);
			a = 0;
			nd = info->envr;
			continue;
		}
		nd = nd->nxt;
		a++;
	}
	return (info->envr_changed);
}

/**
 * _setenvr - Initialize a new environment variable
 * or modify an existing one
 * @info: the tructure containing potential arguments.
 * this used to maintain constant function prototype.
 * @varenv: string envr varenv property
 * @val: string envr varenv value
 * Return: return this always 0
 */
int _setenvr(info_t *info, char *varenv, char *val)
{
	char *bufr = NULL;
	list_t *nd;
	char *pt;

	if (!varenv || !val)
		return (0);

	bufr = malloc(_strglen(varenv) + _strglen(val) + 2);
	if (!bufr)
		return (1);
	_strgcpy(bufr, varenv);
	_strgcat(bufr, "=");
	_strgcat(bufr, val);
	nd = info->envr;
	while (nd)
	{
		pt = starts_with(nd->strg, varenv);
		if (pt && *pt == '=')
		{
			free(nd->strg);
			nd->strg = bufr;
			info->envr_changed = 1;
			return (0);
		}
		nd = nd->nxt;
	}
	add_nd_end(&(info->envr), bufr, 0);
	free(bufr);
	info->envr_changed = 1;
	return (0);
}

