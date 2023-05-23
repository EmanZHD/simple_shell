#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * _forexit - this function exits the shell
 * @info: the structure containing potential arguments. Used to maintain
 * constant function prototype
 * Return: return exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _forexit(info_t *info)
{
	int check;

	if (info->argv[1])
	{
		check = _erratoi(info->argv[1]);
		if (check == -1)
		{
			info->stat = 2;
			prnt_error(info, ":( Illegal number: ");
			_epts(info->argv[1]);
			_eptchar('\n');
			return (1);
		}
		info->err_numb = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_numb = -1;
	return (-2);
}

/**
 * _forchd - this function changes the current directory of the process
 * @info: the tructure containing potential arguments. this used to maintain
 * constant function prototype
 * Return: return always 0
 */
int _forchd(info_t *info)
{
	char *st, *dr, buffer[1024];
	int chdr_ret;

	st = getcwd(buffer, 1024);
	if (!st)
		_pts("TODO: >>failure emsg here<<\n");
	if (!info->argv[1])
	{
		dr = _getenvr(info, "HOME=");
		if (!dr)
			chdr_ret =
				chdir((dr = _getenvr(info, "PWD=")) ? dr : "/");
		else
			chdr_ret = chdir(dr);
	}
	else if (_strgcmp(info->argv[1], "-") == 0)
	{
		if (!_getenvr(info, "OLDPWD="))
		{
			_pts(st);
			_ptchar('\n');
			return (1);
		}
		_pts(_getenvr(info, "OLDPWD=")), _ptchar('\n');
		chdr_ret =
			chdir((dr = _getenvr(info, "OLDPWD=")) ? dr : "/");
	}
	else
		chdr_ret = chdir(info->argv[1]);
	if (chdr_ret == -1)
	{
		prnt_error(info, " :( can't cd to ");
		_epts(info->argv[1]), _eptchar('\n');
	}
	else
	{
		_setenvr(info, "OLDPWD", _getenvr(info, "PWD="));
		_setenvr(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _forhelp - this function changes the current directory of the process
 * @info: the structure containing potential arguments. this used to maintain
 * constant function prototype
 * Return: return always 0
 */
int _forhelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_pts(" :( Function not yet implemented \n");
	if (0)
		_pts(*arg_arr);
	return (0);
}

