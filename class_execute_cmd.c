#include "shell.h"

/**
 * find_builtin - ...
 * @str_pat: ...
 *
 * Return: ...
 */
int find_builtin(pide_t *str_pat)
{
int i, built_in_ret = -1;
builtin_t builtintbl[] = {
{"exit", _exit},
{"env", _environment},
{"help", _help},
{"history", _history},
{"setenv", _setenv},
{"unsetenv", _usetenv},
{"cd", _cd},
{"alias", _alias},
{NULL, NULL}
};

for (i = 0; builtintbl[i].type; i++)
if (_strcmp(str_pat->argv[0], builtintbl[i].type) == 0)
{
str_pat->line_count++;
built_in_ret = builtintbl[i].func(str_pat);
break;
}
return (built_in_ret);
}

/**
 * hsh - ...
 * @str_pat: ...
 * @argv: ...
 *
 * Return: ...
 */
int hsh(pide_t *str_pat, char **argv)
{
ssize_t r = 0;
int builtin_ret = 0;

while (r != -1 && builtin_ret != -2)
{
clear_info(str_pat);
if (interactive(str_pat))
_puts("$ ");
_eputchar(BUF_FLUSH);
r = get_input(str_pat);
if (r != -1)
{
set_info(str_pat, argv);
builtin_ret = find_builtin(str_pat);
OA
if (builtin_ret == -1)
find_cmd(str_pat);
}
else if (interactivestr_pat))
_putchar('\n');
free_info(str_pat, 0);
}
write_history(str_pat);
free_info(str_pat, 1);
if (!interactive(str_pat) && str_pat->status)
exit(str_pat->status);
if (builtin_ret == -2)
{
if (str_pat->err_num == -1)
exit(str_pat->status);
exit(str_pat->err_num);
}
return (builtin_ret);
}



/**
 * find_cmd - ...
 * @str_pat: ...
 *
 */
void find_cmd(pide_t *str_pat)
{
char *path = NULL;
int i, k;

str_pat->path = str_pat->argv[0];
if (str_pat->linecount_flag == 1)
{
str_pat->line_count++;
str_pat->linecount_flag = 0;
}
for (i = 0, k = 0; str_pat->arg[i]; i++)
if (!is_delim(str_pat->arg[i], " \t\n"))
k++;
if (!k)
return;

path = find_path(str_pat, _getenv(str_pat, "PATH="), str_pat->argv[0]);
if (path)
{
str_pat->path = path;
fork_cmd(str_pat);
}
else
{
if ((interactive(str_pat) || _getenv(str_pat, "PATH=")
|| str_pat->argv[0][0] == '/') && is_cmd(str_pat, str_pat->argv[0]))
fork_cmd(str_pat);
else if (*(str_pat->arg) != '\n')
{
str_pat->status = 127;
print_error(str_pat, "not found\n");
}
}
}

/**
 * fork_cmd - ...
 * @str_pat: ...
 *
 */
void fork_cmd(pide_t *str_pat)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(str_pat->path, str_pat->argv, get_environ(str_pat)) == -1)
{
free_info(str_pat, 1);
if (errno == EACCES)
exit(126);
exit(1);
}

}
else
{
wait(&(str_pat->status));
if (WIFEXITED(str_pat->status))
{
str_pat->status = WEXITSTATUS(str_pat->status);
if (str_pat->status == 126)
print_error(str_pat, "Permission denied\n");
}
}
}
