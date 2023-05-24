#include "shell.h"

/**
 * _buffer_cmd - ...
 *
 * @str_par: ...
 * @buf_addr: ...
 * @len_addr: ...
 *
 * Return: ...
 */
ssize_t _buffer_cmd(info_t *str_par, char **buf_addr, size_t *len_addr)
{
	ssize_t r = 0;
	size_t len_pip = 0;

	if (!*len_addr) 
	{
		
		free(*buf_addr);
		*buf_addr = NULL;
		signal(SIGINT, signal_handler);
#if USE_GETLINE
		r = getline(buf_addr, &len_pip, stdin);
#else
		r = getnewline(str_par, buf_addr, &len_pip);
#endif
		if (r > 0)
		{
			if ((*buf_addr)[r - 1] == '\n')
			{
				(*buf_addr)[r - 1] = '\0'; 
				r--;
			}
			str_par->linecount_flag = 1;
			delete_cmt(*buf_addr);
			ls_history(str_par, *buf_addr, str_par->histocount++);
			
			{
				*len_addr = r;
				str_par->cmd_buf = buf_addr;
			}
		}
	}
	return (r);
}

/**
 * signalhandler - ...
 *
 * @sign_num: ...
 *
 */
void signalhandler(__attribute__((unused))int sign_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFFER_FLUSH);
}

/**
 * rd_buffer - ...
 *
 * @str_par: ...
 * @buf: ...
 * @size: ...
 *
 * Return: ...
 */
ssize_t rd_buffer(info_t *str_par, char *buf, size_t *size)
{
	ssize_t rd = 0;

	if (*size)
		return (0);
	rd = read(str_par->readfd, buf, READ_BUFFER_SIZE);
	if (rd >= 0)
		*size = rd;
	return (rd);
}


/**
 * get_newline - ...
 *
 * @str_par: ...
 *
 * Return: ...
 */
ssize_t get_newline(info_t *str_par)
{
	static char *buf; 
	static size_t i, j, len;
	ssize_t a = 0;
	char **buf_pip = &(str_par->arg), *p;

	_putchar(BUFFER_FLUSH);
	a = input_buf(str_par, &buf, &len);
	if (a == -1) 
{
		return (-1);
}
	if (len) 
	{
		j = i;
		a = buf + i;

		check_chain(str_par, buf, &j, i, len);

		do {
			if (is_chain(str_par, buf, &j))
				break;
			j++;
		}while (j < len);

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			str_par->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (a);
}


/**
 * _getnewline - ...
 *
 * @str_par: ...
 * @ptr: ...
 * @length: ...
 *
 * Return: 
 */
int _getnewline(info_t *str_par, char **ptr, size_t *length)
{
	static char buf[READ_BUFFER_SIZE];
	static size_t i, len;
	size_t j;
	ssize_t rd = 0, a = 0;
	char *p = NULL, *pip = NULL, *chr;

	p = *ptr;
	if (p && length)
		a = *length;
	if (i == len)
		i = len = 0;

	rd = read_buf(str_par, buf, &len);
	if (rd == -1 || (rd == 0 && len == 0))
		return (-1);

	chr = _strchr(buf + i, '\n');
	j = chr ? 1 + (unsigned int)(chr - buf) : len;
	pip = _realloc(p, a, a ? a + j : j + 1);
	if (!pip)
		return (p ? free(p), -1 : -1);

	if (a)
		string_couc(pip, buf + i, j - i);
	else
		string_copy(pip, buf + i, k - i + 1);

	a += j - i;
	i = j;
	p = pip;

	if (length)
		*length = a;
	*ptr = p;
	return (a);
}

