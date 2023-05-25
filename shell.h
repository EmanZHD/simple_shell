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
#include<string.h>

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define BUF_FLUSH -1
#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024

#define USE_GETLINE 0
#define USE_STRTOK 0

#define CONVERT_UNSIGNED	2
#define CONVERT_LOWERCASE	1


#define HIST_MAX	4096
#define HIST_FILE	".simple_shell"

extern char **environment;


int exiting_shell(info_t *strc_func);
int process_dir(info_t *strc_func);
int _changdir(info_t *strc_func);
int error_str_int(char *str);
int puts_dec(int input, int fd);
void putserr(info_t *strc_info, char *str_err);
char *clone_itoa(long int num, int base, int arg);
void delete_cmt(char *adress);
int _set_environment(info_t *info, char *var, char *value);
int _rm_environment(info_t *str_func, char *var);
char **_getenvironment(info_t *str_func);
char *string_conc(char *destination, char *src, int n);
char *string_copy(char *destination, char *src, int n);
char *_strchr(char *str, char chr);
ssize_t _buffer_cmd(info_t *str_par, char **buf_addr, size_t *len_addr);
void signalhandler(__attribute__((unused))int sign_num);
ssize_t rd_buffer(info_t *str_par, char *buf, size_t *size);
ssize_t get_newline(info_t *str_par);
int _getnewline(info_t *str_par, char **ptr, size_t *length);
void _setting(info_t *str_adds, char **av);
void _clear(info_t *str_addr);
void _free(info_t *str_adds, int all);
int _history(info_t *info);
char *get_history(info_t *info);
int rd_history(info_t *info);
int wr_history(info_t *info);
int ls_history(info_t *info, char *buf, int linecount);
int ptrfree(void **ptr);
int _lshistory(info_t *strc_func);
int set_alias(info_t *strc_func, char *str);
int setting_alias(info_t *strc_func, char *str);
int put_alias(list_t *node);
int _mimics(info_t *strc_func);
int environment(info_t *strc_func);
char *get_environement(info_t *strc_func, const char *name);
int set_environement(info_t *strc_func);
int rm_rnvironment(info_t *strc_func);
int ls_environment(info_t *strc_func);
void _puts(char *str);
int _putchar(char carr);
int _putsfd(char carr, int fd);
int _print_fd(char *str, int fd);





#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histocount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num, linecount_flag;
	char *fname;
	list_t *env, *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histocount;
} info_t;

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;
