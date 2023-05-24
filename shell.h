#ifndef _SHELL_H_
#define _SHELL_H_

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/*********** LIBRARIES ***********/
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


#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell"
#define HIST_MAX	4096


char *string_copy(char *dest, char *src, int n);
string_conc - concatenates two strings;
ssize_t _buffer_cmd(info_t *sstr_par, char **buf_addr, size_t *len_addr);
ssize_t get_newline(info_t *str_par);
void signalhandler(__attribute__((unused))int sign_num);
int _getnewline(info_t *str_par, char **ptr, size_t *length);
int exiting_shell(info_t *strc_func);
int process_dir(info_t *strc_func);
int _changdir(info_t *strc_func);
int error_str_int(char *str);
int puts_dec(int input, int fd);
void putserr(info_t *strc_info, char *str_err);
char *clone_itoa(long int num, int base, int arg);
void delete_cmt(char *adress);
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
int conv_str_int(char *str);
int char_alpha(int inchar);
int dlm_string(char check, char *delimetre);
int inter_active(info_t *sdr_address);
char **_getenvironment(info_t *str_func);
_rm_environment(info_t *str_func, char *var);
char *_strchr(char *str, char chr);
char *string_copy(char *destination, char *src, int n);
char *string_conc(char *destination, char *src, int n);
int _set_environment(info_t *info, char *var, char *value);
void _free(info_t *str_adds, int all);
void _clear(info_t *str_addr);
void _setting(info_t *str_adds, char **av);
int rd_history(info_t *info);
int ls_history(info_t *info, char *buf, int linecount);
int ptrfree(void **ptr);
int wr_history(info_t *info);
char *get_history(info_t *info);
int ptrfree(void **ptr);
int _history(info_t *info);



extern char **environment;


/**
 * struct liststring - this function singly linked list
 * @numb: the number field
 * @strg: a string
 * @nxt: points to the next node
 */
typedef struct liststring
{
	int numb;
	char *strg;
	struct liststring *nxt;
} list_t;

/**
 * struct passinf - this function contains pseudo-arguements to
 * pass into a function.
 * @arg: string generated from getline containing arguements
 * @argv: array of strings generated from arg
 * @pat: string pat for the current command
 * @argc: rgument count
 * @ln_count: error count
 * @err_numb: error code for exit()s
 * @lncount_flag: if on count this line of input
 * @fname: the program filename
 * @envr: a linked list local copy of environ
 * @environment: the custom modified copy of environ from LL envr
 * @history: history node
 * @alia: alias node
 * @envr_changed: on if environ was changed
 * @stat: return status of the last exec'd command
 * @cmd_bufr: the address of pointer to cmd_bufr, on if chaining
 * @cmd_bufr_type: CMD_type ||, &&, ;
 * @readfdd: fd from which to read line input
 * @histcount: history line number count
 */
typedef struct passinf
{
	char *arg;
	char **argv;
	char *pat;
	int argc;
	unsigned int ln_count;
	int err_numb;
	int lncount_flag;
	char *fname;
	list_t *envr;
	list_t *histry;
	list_t *alia;
	char **environ;
	int envr_changed;
	int stat;

	char **cmd_bufr;
	int cmd_bufr_type;
	int readfdd;
	int histocount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}



#endif

