#include "shell.h"

/**
 * exiting_shell - ...
 *
 * @strc_func: ...
 *
 * Return: ...
 */
int exiting_shell(info_t *strc_func)
{
	int processing;

	if (strc_func->argv[1]) 
	{
		processing = _error(strc_func->argv[1]);
		if (processing == -1)
		{
			strc_func->status = 2;
			put_error(strc_func, "Illegal number: ");
			_puts(strc_func->argv[1]);
			_putchar('\n');
			return (1);
		}
		strc_func->e_number = _error(strc_func->argv[1]);
		return (-2);
	}
	strc_func->e_number = -1;
	return (-2);
}

/**
 * process_dir - ...
 *
 * @strc_func: ...
 *
 * Return: ...
 */
int process_dir(info_t *strc_func)
{
	char *string, *dir, buffer[1024];
	int cdir;

	string = getcwd(buffer, 1024);
	if (!string)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!strc_func->argv[1])
	{
		dir = get_environement(strc_func, "HOME=");
		if (!dir)
			cdir = chdir((dir = get_environement(info, "PWD=")) ? dir : "/");
		else
			cdir = chdir(dir);
	}
	else if (_strcmp(strc_func->argv[1], "-") == 0)
	{
		if (!get_environement(strc_func, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(get_environement(strc_func, "OLDPWD=")), _putchar('\n');
		cdir = chdir((dir = get_environement(info, "OLDPWD=")) ? dir : "/");
	}
	else
		cdir = chdir(info->argv[1]);
	if (cdir == -1)
	{
		put_err(strc_func, "can't cd to ");
		_puts(strc_func->argv[1]), _putchar('\n');
	}
	else
	{
		set_environement(strc_func, "OLDPWD", get_environement(strc_func, "PWD="));
		set_environement(strc_func, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _changdir - ...
 *
 * @strc_func: ...
 * 
 * Return: ...
 */
int _changdir(info_t *strc_func)
{
	char **argA;

	argA = strc_func->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argA); 
	return (0);
}



