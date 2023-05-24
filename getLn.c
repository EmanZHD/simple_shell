#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * input_bufr - this function buffers chained commands
 * @info: the parameter struct
 * @bufr: the address of buffer
 * @lenvr: the address of len var
 * Return: return bytes read
 */
ssize_t input_bufr(info_t *info, char **bufr, size_t *lenvr)
{
	ssize_t s = 0;
	size_t lenvr_p = 0;

	if (!*lenvr)
	{
		free(*bufr);
		*bufr = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		s = getln(bufr, &lenvr_p, stdin);
#else
		s = _getln(info, bufr, &lenvr_p);
#endif
		if (s > 0)
		{
			if ((*bufr)[s - 1] == '\n')
			{
				(*bufr)[s - 1] = '\0';
				s--;
			}
			info->lncount_flag = 1;
			rmv_comments(*bufr);
			build_histry_list(info, *bufr, info->histcount++);
			{
				*lenvr = s;
				info->cmd_bufr = bufr;
			}
		}
	}
	return (s);
}

/**
 * get_inpt - this function gets a line minus the newline
 * @info: the parameter struct
 * Return: return bytes read
 */
ssize_t get_inpt(info_t *info)
{
	static char *bufr;
	static size_t a, b, lenvr;
	ssize_t s = 0;
	char **bufr_p = &(info->arg), *pt;

	_ptchar(BUF_FLUSH);
	s = input_bufr(info, &bufr, &lenvr);
	if (s == -1)
		return (-1);
	if (lenvr)
	{
		b = a;
		pt = bufr + a;

		check_chain(info, bufr, &b, a, lenvr);
		while (b < lenvr)
		{
			if (is_chain(info, bufr, &b))
				break;
			b++;
		}

		a = b + 1;
		if (a >= lenvr)
		{
			a = lenvr = 0;
			info->cmd_bufr_type = CMD_NORM;
		}

		*bufr_p = pt;
		return (_strglen(pt));
	}

	*bufr_p = bufr;
	return (s);
}

/**
 * read_bufr - this function reads a buffer
 * @info: the parameter struct
 * @bufr: the buffer
 * @sz: size
 * Return: return n
 */
ssize_t read_bufr(info_t *info, char *bufr, size_t *sz)
{
	ssize_t n = 0;

	if (*sz)
		return (0);
	n = read(info->readfdd, bufr, READ_BUF_SIZE);
	if (n >= 0)
		*sz = n;
	return (n);
}

/**
 * _getln - this function gets the next line of input from STDIN
 * @info: the parameter struct
 * @ptradd: the address of pointer to buffer, preallocated or NULL
 * @lengt: the size of preallocated ptradd buffer if not NULL
 * Return: m
 */
int _getln(info_t *info, char **ptradd, size_t *lengt)
{
	static char bufr[READ_BUF_SIZE];
	static size_t i, leng;
	size_t sz;
	ssize_t n = 0, m = 0;
	char *pt = NULL, *new_pt = NULL, *ch;

	pt = *ptradd;
	if (pt && lengt)
		m = *lengt;
	if (i == leng)
		i = leng = 0;

	n = read_bufr(info, bufr, &leng);
	if (n == -1 || (n == 0 && leng == 0))
		return (-1);

	ch = _strgchr(bufr + i, '\n');
	sz = ch ? 1 + (unsigned int)(ch - bufr) : leng;
	new_pt = _realloc(pt, m, m ? m + sz : sz + 1);
	if (!new_pt)
		return (pt ? free(pt), -1 : -1);

	if (m)
		_strgncat(new_pt, bufr + i, sz - i);
	else
		_strgncpy(new_pt, bufr + i, sz - i + 1);

	m += sz - i;
	i = sz;
	pt = new_pt;

	if (lengt)
		*lengt = m;
	*ptradd = pt;
	return (m);
}

/**
 * sigintHandler - this function blocks ctrl-C
 * @sig_numb: signal number
 * Return: return void
 */
void sigintHandler(__attribute__((unused))int sig_numb)
{
	_pts("\n");
	_pts("$ ");
	_ptchar(BUF_FLUSH);
}

