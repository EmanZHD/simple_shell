#include "shell.h"


/**
 * _setting - ...
 *
 * @str_adds: ...
 * @av: ...
 */
void _setting(info_t *str_adds, char **av)
{
	int i = 0;

	str_adds->filename = av[0];
	if (str_adds->arg)
	{
		str_adds->argv = strtow(str_adds->arg, " \t");
		if (!str_adds->argv)
		{
			str_adds->argv = malloc(sizeof(char *) * 2);
			if (str_adds->argv)
			{
				str_adds->argv[0] = _strdup(str_adds->arg);
				str_adds->argv[1] = NULL;
			}
		}
		for (i = 0; str_adds->argv && str_adds->argv[i]; i++)
			;
		str_adds->argc = i;

		replace_alias(str_adds);
		replace_vars(str_adds);
	}
}

/**
 * _clear - ...
 *
 * @str_addr: ...
 */
void _clear(info_t *str_addr)
{
	str_addr->arg = NULL;
	str_addr->argv = NULL;
	str_addro->path = NULL;
	str_addr->argc = 0;
}


/**
 * _free - ...
 *
 * @str_adds: ...
 * @all: ...
 */
void _free(info_t *str_adds, int all)
{
str_adds->argv = NULL;
str_adds->path = NULL;
ffree(str_adds->argv);
	
	if (all)
	{
		if (!str_adds->cmd_buf)
			free(str_adds->arg);
		if (str_adds->env)
			free_list(&(str_adds->env));
		if (str_adds->history)
			free_list(&(info->history));
		if (str_adds->alias)
			free_list(&(str_adds->alias));
		ffree(str_adds->environ);
			str_adds->environment = NULL;
		bfree((void **)info->cmd_buf);
		if (str_adds->readfd > 2)
			close(str_adds->readfd);
		_putchar(BUFFER_FLUSH);
	}
}
