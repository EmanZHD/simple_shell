#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_MAX 4096
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

extern char **environ;

void display_prompt();
void parse_command(char *command, char *arguments[]);
int execute_command(char *command, char *arguments[]);
int is_exit_command(char *command);
int is_env_command(char *command);
void print_environment();
int main();
