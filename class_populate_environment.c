#include "shell.h"

/**
 * environment - ...
 * @strc_func: ...
 *
 * Return: ...
 */
int environment(info_t *strc_func)
{
	put_ls(strc_func->env);
	return (0);
}

/**
 * get_environement - ...
 *
 * @strc_func: ...
 * @name: ...
 *
 * Return: ...
 */
char *get_environement(info_t *strc_func, const char *name)
{
	list_t *node = strc_func->env;
	char *pip;

	while (node)
	{
		pip = _start(node->str, name);
		if (pip && *pip)
			return (pip);
		node = node->next;
	}
	return (NULL);
}

/**
 * set_environement - ...
 *
 * @strc_func: ...
 *
 *  Return: ...
 */
int set_environement(info_t *strc_func)
{
	if (strc_func->argc != 3)
	{
		_puts("Incorrect number of arguements\n");
		return (1);
	}
	if (set_environement(strc_func, strc_func->argv[1], strc_func->argv[2]))
		return (0);
	return (1);
}

/**
 * rm_environment - ...
 *
 * @strc_func: ...
 *
 * Return: ...
 */
int rm_rnvironment(info_t *strc_func)
{
	int mv;

	if (strc_func->argc == 1)
	{
		_puts("Too few arguements.\n");
		return (1);
	}
	for (mv = 1; mv <= strc_func->argc; mv++)
		set_environement(strc_func, strc_func->argv[mv]);

	return (0);
}

/**
 * ls_environment - ...
 *
 * @strc_func: ...
 *
 * Return: ...
 */
int ls_environment(info_t *strc_func)
{
	list_t *node = NULL;
	size_t mv;

	for (mv = 0; env[mv]; mv++)
		node_in_end(&node, env[mv], 0);
	strc_func->env = node;
	return (0);
}
