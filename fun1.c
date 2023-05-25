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

int execute_command(char *command, char *arguments[])
{

  execvp(command, arguments);
  return (-1);
}
