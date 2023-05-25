#include "shell.h"

/**
 * init_data - Function that init data
 * @data: the data struct input
 * @shell_name: the string input
 * Return: return void
 */

void init_data(input *data, const char *shell_name)
{
	data->command = NULL;
	data->av = NULL;
	data->shell_name = shell_name;
}

/**
 * child_process - Function that start a new process
 * @data: the data struct input
 * @environ: the environ
 * Return: return void
 */

void child_process(input *data, char **environ)
{
	pid_t child_pid = fork();
	int stat = 0;

	if (child_pid == -1)
		goto free;
	if (child_pid == 0 && execve(data->av[0], data->av, environ) == -1)
		goto free;
	else if (wait(&stat) == -1)
		goto free;
	return;

free:
	perror(data->shell_name);
	free_array(data->av);
	free(data->command);
	exit(EXIT_FAILURE);
}
/**
 * command_line - Function that get the command from
 * the prompt and structure it into data struct
 * @data: the data struct input
 * Return: return void
 */

void command_line(input *data)
{
	size_t sz = 0;
	ssize_t num_of_chars;

	num_of_chars = getline(&data->command, &sz, stdin);

	if (num_of_chars == -1)
	{
		free(data->command);
		free(data);
		exit(EXIT_SUCCESS);
	}

	data->command[num_of_chars - 1] = '\0';
	_white_spaces(data->command);
	h_cmd(data->command);
}

/**
 * _sigint - Function that signal handler function
 * @signal: for int input
 * Return: return void
 */

	void _sigint(int signal)
	{
		const char prompt[] = "\n#csisfun$ ";
		(void)signal;
		_printf(prompt);
	}

/**
 * command_spliter - Function that split a given string by delimiter
 * @data: the data struct input
 * @delim: the string input
 * Return: return void
 */

void command_spliter(input *data, const char *delim)
{
	char *tocken;
	int ntocken = 0;

	data->av = malloc(2 * sizeof(char *));
	if (data->av == NULL)
	{
		free(data->command);
		perror(data->shell_name);
		exit(EXIT_FAILURE);
	}
	data->av[0] = NULL;
	data->av[1] = NULL;

	tocken = strtok(data->command, delim);
	while (tocken)
	{
		data->av = _realloc(data->av, (ntocken + 2) * sizeof(char *));
		if (data->av == NULL)
			goto free;
		data->av[ntocken] = _strdup(tocken);
		if (data->av[ntocken] == NULL)
			goto free;
		ntocken++;
		tocken = strtok(NULL, delim);
	}
	data->av[ntocken] = NULL;
	return;

free:
	free_array(data->av);
	free(data->command);
	perror(data->shell_name);
	exit(EXIT_FAILURE);

}
