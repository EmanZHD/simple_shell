#include "shell.h"

/**
 * _set_environment - ...
 * @info: ...
 * @var: ...
 * @value: ...
 *  Return: ...
 */
int _set_environment(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	string_copy(buf, var);
	string_conc(buf, "=");
	string_conc(buf, value);
	node = info->env;
	while (node)
	{
		p = _start(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->chang_env = 1;
			return (0);
		}
		node = node->next;
	}
	node_to_end(&(info->env), buf, 0);
	free(buf);
	info->chang_env = 1;
	return (0);
}


/**
 * _rm_environment - ...
 *
 * @str_func: ...
 * @var: ...
 *
 *Return: ...
 */
int _rm_environment(info_t *str_func, char *var)
{
	list_t *node = str_func->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = _start(node->str, var);
		if (p && *p == '=')
		{
			str_func->chang_env = remove_node(&(str_func->env), i);
			i = 0;
			node = str_func->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->chang_env);
}


/**
 * _getenvironment - ...
 *
 * @str_func: ...
 *
 * Return: ...
 */
char **_getenvironment(info_t *str_func)
{
	if (!info->environ || str_func->chang_env)
	{
		str_func->environment = list_to_strings(str_func->env);
		str_func->chang_env = 0;
	}

	return (str_func->environment);
}

