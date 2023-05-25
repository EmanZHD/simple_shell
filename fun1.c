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
