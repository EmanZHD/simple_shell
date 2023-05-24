#include "shell.h"

/**
 * _history - ...
 * @info: ...
 *
 * Return: ...
 */
int _history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histocount = i);
}

/**
 * get_history - ...
 * @info: ...
 *
 * Return: ...
 */

char *get_history(info_t *info)
{
	char *buf, *dir;

	dir = get_envronement(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	string_copy(buf, dir);
	string_conc(buf, "/");
	string_conc(buf, HIST_FILE);
	return (buf);
}

/**
 * rd_history - ...
 * @info: ...
 *
 * Return: ...
 */
int rd_history(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		ls_history(info, buf + last, linecount++);
	free(buf);
	info->histocount = linecount;
	while (info->histcount-- >= HIST_MAX)
		remove_node(&(info->history), 0);
	_history(info);
	return (info->histocount);
}

/**
 * wr_history - ...
 * @info: ...
 *
 * Return: ...
 */
int wr_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUFFER_FLUSH, fd);
	close(fd);
	return (1);
}




/**
 * ls_history - ...
 * @info: ...
 * @buf: ...
 * @linecount: ...
 *
 * Return: ...
 */
int ls_history(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}



/**
 * ptrfree - ...
 *
 * @ptr: ...
 *
 * Return: ...
 */
int ptrfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}





