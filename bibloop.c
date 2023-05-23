#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * hsh - function main shell loop
 * @info: parameter & return info struct
 * @av: argument vector from main()
 * Return: return 0 on success
 * and 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t n = 0;
	int built_ret = 0;

	while (n != -1 && built_ret != -2)
	{
		clear_info(info);
		if (intractive(info))
			_pts("$ ");
		_eptchar(BUF_FLUSH);
		n = get_inpt(info);
		if (n != -1)
		{
			set_info(info, av);
			built_ret = fnd_builtin(info);
			if (built_ret == -1)
				fnd_cmd(info);
		}
		else if (intractive(info))
			_ptchar('\n');
		free_info(info, 0);
	}
	write_histry(info);
	free_info(info, 1);
	if (!intractive(info) && info->stat)
		exit(info->stat);
	if (built_ret == -2)
	{
		if (info->err_numb == -1)
			exit(info->stat);
		exit(info->err_numb);
	}
	return (built_ret);
}

/**
 * fnd_builtin - this function finds a builtin command
 * @info: parameter & return info struct
 * Return: return -1 if built not found,
 * 0 if built executed successfully,
 * 1 if built found but not successful,
 * 2 if built signals exit()
 */
int fnd_builtin(info_t *info)
{
	int r, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _forexit},
		{"envr", _myenvr},
		{"help", _forhelp},
		{"histry", _myhistry},
		{"setenvr", _mysetenvr},
		{"unsetenvr", _myunsetenvr},
		{"cd", _forchd},
		{"alia", _myalia},
		{NULL, NULL}
	};

	for (r = 0; builtintbl[r].type; r++)
		if (_strgcmp(info->argv[0], builtintbl[r].type) == 0)
		{
			info->ln_count++;
			built_in_ret = builtintbl[r].funct(info);
			break;
		}
	return (built_in_ret);
}

/**
 * fnd_cmd - this function finds a command in PATH
 * @info: parameter & return info struct
 * Return: return void
 */
void fnd_cmd(info_t *info)
{
	char *pat = NULL;
	int r, j;

	info->pat = info->argv[0];
	if (info->lncount_flag == 1)
	{
		info->ln_count++;
		info->lncount_flag = 0;
	}
	for (r = 0, j = 0; info->arg[r]; r++)
		if (!is_delm(info->arg[r], " \t\n"))
			j++;
	if (!j)
		return;

	pat = fnd_pat(info, _getenvr(info, "PATH="), info->argv[0]);
	if (pat)
	{
		info->pat = pat;
		fork_cmd(info);
	}
	else
	{
		if ((intractive(info) || _getenvr(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->stat = 127;
			prnt_error(info, ":) not found\n");
		}
	}
}

/**
 * fork_cmd - this function forks a an exec thread to run cmd
 * @info: parameter & return info struct
 * Return: return void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{

		perror(" :) Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->pat, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}

	}
	else
	{
		wait(&(info->stat));
		if (WIFEXITED(info->stat))
		{
			info->stat = WEXITSTATUS(info->stat);
			if (info->stat == 126)
				prnt_error(info, "This permission denied\n");
		}
	}
}

