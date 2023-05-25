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

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
                0, 0, 0}
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
} pide_t;


void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

int is_cmd(pide_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(pide_t *, char *, char *);

int hsh(pide_t *, char **);
int find_builtin(pide_t *);
void find_cmd(pide_t *);
void fork_cmd(pide_t *);

int loophsh(char **);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int interactive(pide_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int bfree(void **);

int _erratoi(char *);
void print_error(pide_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

int _history(pide_t *);
int _alias(pide_t *);

int _exit(pide_t *);
int _cd(pide_t *);
int _help(pide_t *);

char *_getenv(pide_t *, const char *);
int _environment(pide_t *);

ssize_t get_input(pide_t *);
int _getline(pide_t *, char **, size_t *);
void sigintHandler(int);

void clear_info(pide_t *);
void set_info(pide_t *, char **);
void free_info(pide_t *, int);

int _setenv(pide_t *);
int _usetenv(pide_t *);
int populate_env_list(pide_t *);

char *get_history_file(pide_t *str_pat);
int write_history(pide_t *str_pat);
int read_history(pide_t *str_pat);
int build_history_list(pide_t *str_pat, char *buf, int linecount);
int renumber_history(pide_t *str_pat);

char **get_environ(pide_t *);
int _unsetenv(pide_t *, char *);
int _setenv(pide_t *, char *, char *);

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

int is_chain(pide_t *, char *, size_t *);
void check_chain(pide_t *, char *, size_t *, size_t, size_t);
int replace_alias(pide_t *);
int replace_vars(pide_t *);
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
