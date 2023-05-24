#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * is_cmd - this function determines if a file is an executable command
 * @info: info struct
 * @pat: the path to the file
 * Return: return 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *pat)
{
	struct stat st;

	(void)info;
	if (!pat || stat(pat, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - this function duplicates characters
 * @patstrg: the PATH string
 * @begi: starting index
 * @end: stopping index
 * Return: return pointer to new buffer
 */
char *dup_chars(char *patstrg, int begi, int end)
{
	static char bufr[1024];
	int a = 0, j = 0;

	for (j = 0, a = begi; a < end; a++)
		if (patstrg[a] != ':')
			bufr[j++] = patstrg[a];
	bufr[j] = 0;
	return (bufr);
}

/**
 * fnd_pat - this function finds this cmd in the PATH string
 * @info: info struct
 * @patstrg: PATH string
 * @cmd: the cmd to find
 * Return: full pat of cmd if found or NULL
 */
char *fnd_pat(info_t *info, char *patstrg, char *cmd)
{
	int a = 0, curr_pos = 0;
	char *pat;

	if (!patstrg)
		return (NULL);
	if ((_strglen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!patstrg[a] || patstrg[a] == ':')
		{
			pat = dup_chars(patstrg, curr_pos, a);
			if (!*pat)
				_strgcat(pat, cmd);
			else
			{
				_strgcat(pat, "/");
				_strgcat(pat, cmd);
			}
			if (is_cmd(info, pat))
				return (pat);
			if (!patstrg[a])
				break;
			curr_pos = a;
		}
		a++;
	}
	return (NULL);
}

