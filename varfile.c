#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * is_chain - this function test if current char in buffer is a chain delimeter
 * @info: parameter struct
 * @bufr: char buffer
 * @ads: the address of current position in bufr
 * Return: return 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *bufr, size_t *ads)
{
	size_t i = *ads;

	if (bufr[i] == '|' && bufr[i + 1] == '|')
	{
		bufr[i] = 0;
		i++;
		info->cmd_bufr_type = CMD_OR;
	}
	else if (bufr[i] == '&' && bufr[i + 1] == '&')
	{
		bufr[i] = 0;
		i++;
		info->cmd_bufr_type = CMD_AND;
	}
	else if (bufr[i] == ';')
	{
		bufr[i] = 0;
		info->cmd_bufr_type = CMD_CHAIN;
	}
	else
		return (0);
	*ads = i;
	return (1);
}

/**
 * check_chain - this function checks we should
 * continue chaining based on last status
 * @info: parameter struct
 * @bfr: char buffer
 * @ads: the address of current position in bfr
 * @ps: the starting position in bfr
 * @leng: the length of bfr
 * Return: return void
 */
void check_chain(info_t *info, char *bfr, size_t *ads, size_t ps, size_t leng)
{
	size_t j = *ads;

	if (info->cmd_bufr_type == CMD_AND)
	{
		if (info->stat)
		{
			bfr[ps] = 0;
			j = leng;
		}
	}
	if (info->cmd_bufr_type == CMD_OR)
	{
		if (!info->stat)
		{
			bfr[ps] = 0;
			j = leng;
		}
	}

	*ads = j;
}

/**
 * replace_alia - this function replaces an aliases in the tokenized string
 * @info: parameter struct
 * Return: return 1 if replaced, 0 otherwise
 */
int replace_alia(info_t *info)
{
	int i;
	list_t *nd;
	char *ads;

	for (i = 0; i < 10; i++)
	{
		nd = nd_starts_with(info->alia, info->argv[0], '=');
		if (!nd)
			return (0);
		free(info->argv[0]);
		ads = _strgchr(nd->strg, '=');
		if (!ads)
			return (0);
		ads = _strgdup(ads + 1);
		if (!ads)
			return (0);
		info->argv[0] = ads;
	}
	return (1);
}

/**
 * replace_vars - this function replaces vars in the tokenized string
 * @info: parameter struct
 * Return: return 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *nd;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strgcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strgdup(cnvrt_numb(info->stat, 10, 0)));
			continue;
		}
		if (!_strgcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strgdup(cnvrt_numb(getpid(), 10, 0)));
			continue;
		}
		nd = nd_starts_with(info->envr, &info->argv[i][1], '=');
		if (nd)
		{
			replace_string(&(info->argv[i]),
					_strgdup(_strgchr(nd->strg, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strgdup(""));

	}
	return (0);
}

/**
 * replace_string - this function replaces string
 * @olds: the address of old string
 * @news: the new string
 * Return: return 1 if replaced, 0 otherwise
 */
int replace_string(char **olds, char *news)
{
	free(*olds);
	*olds = news;
	return (1);
}

