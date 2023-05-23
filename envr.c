#include "shell.h"

/**
 * _myenvr - this function prints the current environment
 * @info: the structure containing potential arguments.
 * this used to maintain constant function prototype
 * Return: return always 0
 */
int _myenvr(info_t *info)
{
	prnt_list_strg(info->envr);
	return (0);
}

/**
 * _getenvr - this function gets the value of an environ variable
 * @info: the structure containing potential arguments. this used to maintain
 * @vname: envr var name
 * Return: return the value
 */
char *_getenvr(info_t *info, const char *vname)
{
	list_t *nd = info->envr;
	char *pt;

	while (nd)
	{
		pt = starts_with(nd->strg, vname);
		if (pt && *pt)
			return (pt);
		nd = nd->nxt;
	}
	return (NULL);
}

/**
 * _mysetenvr - this function initialize a new environment variable,
 * or modify an existing one
 * @info: the structure containing potential arguments.
 * this used to maintain constant function prototype
 * Return: return always 0
 */
int _mysetenvr(info_t *info)
{
	if (info->argc != 3)
	{
		_epts(" :( Incorrect number\n");
		return (1);
	}
	if (_setenvr(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenvr - this function remove an environment variable
 * @info: the tructure containing potential arguments.
 * this used to maintain constant function prototype
 * Return: return always 0
 */
int _myunsetenvr(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_epts(" it's too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenvr(info, info->argv[i]);

	return (0);
}

/**
 * populate_envr_list - this function populates env linked list
 * @info: the structure containing potential arguments.
 * this used to maintain constant function prototype
 * Return: return always 0
 */
int populate_envr_list(info_t *info)
{
	list_t *nd = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_nd_end(&nd, environ[i], 0);
	info->envr = nd;
	return (0);
}

