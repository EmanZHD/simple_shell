#include<shell.h>

/**
 * display_prompt - ...
 */

void display_prompt()
{
printf(">> ");
fflush(stdout);
}

/**
 *execute_command - ...
 *
 *@command: ...
 *@arguments: ...
 *
 *Return:...
 */

void execute_command(const char *command)
{

pid_t pid = fork();

if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(command, command, NULL);
perror("execvp");
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, NULL, 0);
}
}

/**
 * exec_cmd - ...
 * 
 * Return: ...
 */

int exec_cmd()
{
char command[MAX_COMMAND_LENGTH];

while (1)
{
display_prompt();

if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
break;
}
command[strcspn(command, "\n")] = '\0';

int status = execute_command(command);
if (status == -1)
{
fprintf(stderr, "Error occurred while executing the command\n");
}
}
return (0);
}
