#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * clear_inf - this function initializes info_t struct
 * @info: the struct address
 */
void clear_inf(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->pat = NULL;
	info->argc = 0;
}

/**
 * set_inf - this function initializes info_t struct
 * @info: the struct address
 * @av: the argument vector
 */
void set_inf(info_t *info, char **av)
{
	int a = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strgtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strgdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (a = 0; info->argv && info->argv[a]; a++)
			;
		info->argc = a;

		replace_alia(info);
		replace_vars(info);
	}
}

/**
 * free_inf - this function frees info_t struct fields
 * @info: the struct address
 * @alfd: it's true if freeing all fields
 */
void free_inf(info_t *info, int alfd)
{
	flfree(info->argv);
	info->argv = NULL;
	info->pat = NULL;
	if (alfd)
	{
		if (!info->cmd_bufr)
			free(info->arg);
		if (info->envr)
			free_list(&(info->envr));
		if (info->histry)
			free_list(&(info->histry));
		if (info->alia)
			free_list(&(info->alia));
		flfree(info->environ);
			info->environ = NULL;
		bffree((void **)info->cmd_bufr);
		if (info->readfdd > 2)
			close(info->readfdd);
		_ptchar(BUF_FLUSH);
	}
}

