#include "shell.h"

/**
 * _lshistory - ...
 *
 * @strc_func: ...
 *
 *  Return: ...
 */
int _lshistory(info_t *strc_func)
{
	put_ls(strc_func->history);
	return (0);
}

/**
 * set_alias - ...
 *
 * @strc_func: ...
 * @str: ...
 *
 * Return: ...
 */
int set_alias(info_t *strc_func, char *str)
{
	char *pip, crh;
	int mv;

	p = str_char(str, '=');
	if (!pip)
		return (1);
	crh = *p;
	*pip = 0;
	mv = remove_node(&(strc_func->alias),
		get_node(strc_func->alias, start_node(strc_func->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * setting_alias - ...
 *
 * @strc_func: ...
 * @str: ...
 *
 * Return: ...
 */
int setting_alias(info_t *strc_func, char *str)
{
	char *pip;

	pip = str_char(str, '=');
	if (!pip)
		return (1);
	if (!*++pip)
		return (set_alias(strc_func, str));

	set_alias(strc_func, str);
	return (node_in_end(&(strc_func->alias), str, 0) == NULL);
}

/**
 * put_alias - ...
 *
 * @node: ...
 *
 * Return: ...
 */
int put_alias(list_t *node)
{
	char *pip = NULL, *alias = NULL;

	if (node)
	{
		pip = str_char(node->str, '=');
		for (alias = node->str; alias <= pip; a++)
		_putchar(*alias);
		_putchar('\'');
		_puts(pip + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _mimics - ...
 * @strc_func: ...
 *
 *  Return: ...
 */
int _mimics(info_t *strc_func)
{
	int arg = 0;
	char *pip = NULL;
	list_t *node = NULL;

	if (strc_func->argc == 1)
	{
		node = strc_func->alias;
		while (node)
		{
			put_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (arg = 1; strc_func->argv[i]; arg++)
	{
		pip = str_chaipr(strc_func->argv[arg], '=');
		if (pip)
			setting_alias(strc_func, strc_func->argv[arg]);
		else
			put_alias(node_starts_with(strc_func->alias, strc_func->argv[arg], '='));
	}

	return (0);
}

