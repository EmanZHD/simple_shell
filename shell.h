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

/*** BUFFERS ***/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*** COMMAND ***/
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/*** CONVERT ***/
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/*** 1 FOR getline() ***/
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


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
 * @environ: the custom modified copy of environ from LL envr
 * @histry: history node
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

	char **cmd_bufr; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_bufr_type; /* CMD_type ||, &&, ; */
	int readfdd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct built - this function contains a builtin
 * string and related function
 * @type: builtin command flag
 * @funct: function
 */
typedef struct built
{
	char *type;
	int (*funct)(info_t *);
} builtin_table;


/*** FOR shloop.c ***/
int hsh(info_t *, char **);
int fnd_builtin(info_t *);
void fnd_cmd(info_t *);
void fork_cmd(info_t *);

/*** FOR prsr.c ***/
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *fnd_pat(info_t *, char *, char *);

/*** FOR loophsh.c ***/
int loophs(char **);

/*** FOR errs00.c ***/
void _epts(char *);
int _eptchar(char);
int _ptfdd(char c, int fdd);
int _ptsfdd(char *strg, int fdd);

/*** FOR str00.c ***/
int _strglen(char *);
int _strgcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strgcat(char *, char *);

/*** FOR str01.c ***/
char *_strgcpy(char *, char *);
char *_strgdup(const char *);
void _pts(char *);
int _ptchar(char);

/*** FOR exits.c ***/
char *_strgncpy(char *, char *, int);
char *_strgncat(char *, char *, int);
char *_strgchr(char *, char);

/*** FOR tokenfile.c ***/
char **strgtow(char *, char *);
char **strgtow2(char *, char);

/*** FOR realloc.c ***/
char *_memset(char *, char, unsigned int);
void flfree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/*** FOR memfile.c ***/
int bffree(void **);

/*** FOR atoi.c ***/
int intractive(info_t *);
int is_delm(char, char *);
int _alpha(int);
int _atoi(char *);

/*** FOR errs01.c ***/
int _erratoi(char *);
void prnt_error(info_t *, char *);
int prnt_d(int, int);
char *cnvrt_numb(long int, int, int);
void rmv_comments(char *);

/*** FOR built00.c ***/
int _forexit(info_t *);
int _forchd(info_t *);
int _forhelp(info_t *);

/*** FOR built01.c ***/
int _myhistry(info_t *);
int _myalia(info_t *);

/*** FOR getln.c ***/
ssize_t get_inpt(info_t *);
int _getln(info_t *, char **, size_t *);
void sigintHandler(int);

/*** FOR getinf.c ***/
void clear_inf(info_t *);
void set_inf(info_t *, char **);
void free_inf(info_t *, int);

/*** FOR envr.c ***/
char *_getenvr(info_t *, const char *);
int _myenvr(info_t *);
int _mysetenvr(info_t *);
int _myunsetenvr(info_t *);
int populate_envr_list(info_t *);

/*** FOR getenvr.c ***/
char **get_environ(info_t *);
int _unsetenvr(info_t *, char *);
int _setenvr(info_t *, char *, char *);

/*** FOR hstry.c ***/
char *get_histry_file(info_t *info);
int write_histry(info_t *info);
int read_histry(info_t *info);
int build_histry_list(info_t *info, char *bufr, int lncount);
int renumb_histry(info_t *info);

/*** FOR ls00.c ***/
list_t *add_nd(list_t **, const char *, int);
list_t *add_nd_end(list_t **, const char *, int);
size_t prnt_list_strg(const list_t *);
int delete_nd_at_index(list_t **, unsigned int);
void free_list(list_t **);

/*** FOR ls01.c ***/
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t prnt_list(const list_t *);
list_t *nd_starts_with(list_t *, char *, char);
ssize_t get_nd_index(list_t *, list_t *);

/*** FOR varfile.c ***/
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alia(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif

