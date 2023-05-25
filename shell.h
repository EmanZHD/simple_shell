#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct input - Function that holds the main data
 * @av: the array
 * @command: the command line
 * @shell_name: name of the shell program
 */

typedef struct input
{
	char **av;
	char *command;
	const char *shell_name;
} input;

/**
 * struct builtin - Function that holds the main data
 * @command: to built in command
 * @f: the function of builtin command
 */
typedef struct builtin
{
	const char *command;
	void (*f)(input *data);
} builtin;

int	_putchar(char c);
int exec_builtin(input *data);
int path_handling(input *data);
int _atoi(char *s);
char	*_strdup(const char *s1);
char	*_strcat(char	*dest, char	*src);
int	_strcmp(char	*s1, char	*s2);
int	_strncmp(char *s1, char *s2, unsigned int n);
int	_strlen(char	*str);
void _white_spaces(char *s);
void h_cmd(char *str);
void _printf(const char *str);
void init_data(input *data, const char *shell_name);
void command_line(input *d);
char	*_strcpy(char	*dest, char	*src);
void command_spliter(input *data, const char *delim);
void child_process(input *data, char **environ);
void builtin_exit(input *data);
void builtin_env(input *data);
void _sigint(int signal);
void free_array(char **array);
char **_realloc(char **ptr, size_t size);
char *get_env(char *env_var);

#endif
