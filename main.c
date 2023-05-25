#include "shell.h"

/**
 *  main - Function that entry point
 *  @argc: for counter args
 *  @argv: for array of args
 *  Return: return 0
*/

int main(__attribute__((unused))int argc, char **argv)
{
const char prompt[11] = "#cisfun$ ";
const char delim[10] = " \t\r\n";
input *data;

data = malloc(sizeof(input));

init_data(data, argv[0]);


signal(SIGINT, _sigint);
while (1)
{

if (isatty(STDIN_FILENO))
_printf(prompt);
else
write(STDERR_FILENO, "", 0);
		
command_line(data);
if (_strlen(data->command) != 0)
{
command_spliter(data, delim);
if (!exec_builtin(data))
{
path_handling(data);
if (access(data->av[0], F_OK || X_OK) == -1)
perror(data->shell_name);
else
child_process(data, environ);
}
free_array(data->av);
}
free(data->command);
}
free(data);
return (0);
}

