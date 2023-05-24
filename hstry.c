#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * get_histry_file - this function gets the history file
 * @info: the parameter struct
 * Return: return allocated string containg history file
 */

char *get_histry_file(info_t *info)
{
	char *bufr, *dr;

	dr = _getenvr(info, "HOME=");
	if (!dr)
		return (NULL);
	bufr = malloc(sizeof(char) * (_strglen(dr) + _strglen(HIST_FILE) + 2));
	if (!bufr)
		return (NULL);
	bufr[0] = 0;
	_strgcpy(bufr, dr);
	_strgcat(bufr, "/");
	_strgcat(bufr, HIST_FILE);
	return (bufr);
}

/**
 * write_histry - this function creates a file, or appends to an existing file
 * @info: parameter struct
 * Return: return 1 on success, or -1
 */
int write_histry(info_t *info)
{
	ssize_t fdd;
	char *flname = get_histry_file(info);
	list_t *nd = NULL;

	if (!flname)
		return (-1);

	fdd = open(flname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(flname);
	if (fdd == -1)
		return (-1);
	for (nd = info->histry; nd; nd = nd->nxt)
	{
		_ptsfdd(nd->strg, fdd);
		_ptfdd('\n', fdd);
	}
	_ptfdd(BUF_FLUSH, fdd);
	close(fdd);
	return (1);
}

/**
 * read_histry - this function reads history from file
 * @info: parameter struct
 * Return: return histcount on success, or 0
 */
int read_histry(info_t *info)
{
	int i, f = 0, lncount = 0;
	ssize_t fdd, rdlen, flsize = 0;
	struct stat st;
	char *bufr = NULL, *flname = get_histry_file(info);

	if (!flname)
		return (0);

	fdd = open(flname, O_RDONLY);
	free(flname);
	if (fdd == -1)
		return (0);
	if (!fstat(fdd, &st))
		flsize = st.st_size;
	if (flsize < 2)
		return (0);
	bufr = malloc(sizeof(char) * (flsize + 1));
	if (!bufr)
		return (0);
	rdlen = read(fdd, bufr, flsize);
	bufr[flsize] = 0;
	if (rdlen <= 0)
		return (free(bufr), 0);
	close(fdd);
	for (i = 0; i < flsize; i++)
		if (bufr[i] == '\n')
		{
			bufr[i] = 0;
			build_histry_list(info, bufr + f, lncount++);
			f = i + 1;
		}
	if (f != i)
		build_histry_list(info, bufr + f, lncount++);
	free(bufr);
	info->histcount = lncount;
	while (info->histcount-- >= HIST_MAX)
		delete_nd_at_index(&(info->histry), 0);
	renumb_histry(info);
	return (info->histcount);
}

/**
 * build_histry_list - this function adds entry to a history linked list
 * @info: the structure containing potential arguments
 * @bufr: hte buffer
 * @lncount: history lncount, histcount
 * Return: return always 0
 */
int build_histry_list(info_t *info, char *bufr, int lncount)
{
	list_t *nd = NULL;

	if (info->histry)
		nd = info->histry;
	add_nd_end(&nd, bufr, lncount);

	if (!info->histry)
		info->histry = nd;
	return (0);
}

/**
 * renumb_histry - this function renumbers the history
 * linked list after changes
 * @info: the structure containing potential arguments
 * Return: return the new histcount
 */
int renumb_histry(info_t *info)
{
	list_t *nd = info->histry;
	int i = 0;

	while (nd)
	{
		nd->numb = i++;
		nd = nd->nxt;
	}
	return (info->histcount = i);
}

