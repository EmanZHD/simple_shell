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

/**
 * struct coordinate - contains pseudo-arguements to pass into a function,
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
 * @histcount: the history line number count
 */
typedef struct coordinate
{
int err_num;
int linecount_flag;
char *fname;
char **cmd_buf;
int cmd_buf_type;
int readfd;
int histcount;
list_t *history;
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
list_t *alias;
char **environ;
int env_changed;
int status;
list_t *env;
} pid_t;


void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

int is_cmd(pid_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(pid_t *, char *, char *);

int hsh(pid_t *, char **);
int find_builtin(pid_t *);
void find_cmd(pid_t *);
void fork_cmd(pid_t *);

int loophsh(char **);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int interactive(pid_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int bfree(void **);

int _erratoi(char *);
void print_error(pid_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

int _myhistory(pid_t *);
int _myalias(pid_t *);

int _myexit(pid_t *);
int _mycd(pid_t *);
int _myhelp(pid_t *);

char *_getenv(pid_t *, const char *);
int _myenv(pid_t *);

ssize_t get_input(pid_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

void clear_info(pid_t *);
void set_info(pid_t *, char **);
void free_info(pid_t *, int);

int _mysetenv(pid_t *);
int _myunsetenv(pid_t *);
int populate_env_list(pid_t *);

char *get_history_file(pid_t *info);
int write_history(pid_t *info);
int read_history(pid_t *info);
int build_history_list(pid_t *info, char *buf, int linecount);
int renumber_history(pid_t *info);

char **get_environ(pid_t *);
int _unsetenv(pid_t *, char *);
int _setenv(pid_t *, char *, char *);

size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

int is_chain(pid_t *, char *, size_t *);
void check_chain(pid_t *, char *, size_t *, size_t, size_t);
int replace_alias(pid_t *);
int replace_vars(pid_t *);
int replace_string(char **, char *);

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
char *type;
int (*func)(pid_t *);
} builtin_t;


#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
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



#endif
