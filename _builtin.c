#include "shell.h"

/**
 * exec_builtin - Function that check if built in and then execute
 * @data: that input struct input
 * Return: return 1 if built in, 0 otherwise
 */
int exec_builtin(input *data)
{

	builtin builtin[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, NULL},
	};
	int a = 0;

	for (a = 0; builtin[a].command; a++)
	{
		if (strcmp(data->av[0], builtin[a].command) == 0)
		{
			builtin[a].f(data);
			return (1);
		}
	}
	return (0);
}

/**
 * builtin_exit - Function that exits the shell
 * @data: that input struct input
 * Return: return void
 */
void builtin_exit(input *data)
{
	int stat = 0;

	if (data->av[1])
		stat = _atoi(data->av[1]);
	free_array(data->av);
	free(data->command);
	free(data);
	exit(stat);
}

/**
 * builtin_env - Function that prints the current environment
 * @data: that input struct input
 * Return: return void
 */
void builtin_env(input *data)
{
	int a = 0;

	(void)data;
	while (environ[a])
	{
		_printf(environ[a]);
		_printf("\n");
		a++;
	}
}

/**
* get_env - Function that retrieves the value of an environment var
* @env_var: the environment variable to retrieve
* Return: return value of the environment variable, or return NULL
*/
char *get_env(char *env_var)
{
	int a = 0;
	char *k;

	while (environ[a])
	{
		k = strtok(environ[a], "=");
		if (_strcmp(env_var, k) == 0)
			return (strtok(NULL, "\n"));
		a++;
	}

	return (NULL);
}
