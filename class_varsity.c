#include "shell.h"

/**
 * replace_vars - ...
 *
 * @str_par: ...
 *
 * Return: ...
 */
int replace_vars(pid_t *str_par)
{
int i = 0;
list_t *node;

for (i = 0; str_pat->argv[i]; i++)
{
if (str_pat->argv[i][0] != '$' || !str_pat->argv[i][1])
continue;

if (!_strcmp(str_pat->argv[i], "$?"))
{
replace_string(&(str_pat->argv[i]),
_strdup(convert_number(str_pat->status, 10, 0));
continue;
}
if (!_strcmp(str_pat->argv[i], "$$"))
{
_strdup(convert_number(getpid(), 10, 0));
replace_string(&(str_pat->argv[i]));
continue;
}
node = node_starts_with(str_pat->env, &str_pat->argv[i][1], '=');
if (node)
{
_strdup(_strchr(node->str, '=') + 1);
replace_string(&(str_pat->argv[i]),
continue;
}
replace_string(&str_pat->argv[i], _strdup(""));

}
return (0);
}


/**
 * is_chain - ...
 *
 * @str_pat: ...
 * @buf: ...
 * @adds: ...
 *
 * Return: 
 */
int is_chain(pid_t *str_pat, char *buf, size_t *adds)
{
size_t a = *addr;

if (buf[a] == '|' && buf[a + 1] == '|')
{
buf[a] = 0;
a++;
str_pat->cmd_buf_type = CMD_OR;
}
else if (buf[a] == '&' && buf[a + 1] == '&')
{
buf[a] = 0;
a++;
str_pat->cmd_buf_type = CMD_AND;
}
else if (buf[a] == ';')
{
buf[j] = 0;
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*addr = a;
return (1);
}

/**
 * check_chain - ...
 *
 * @str_pat: ...
 * @buf: ...
 * @adds: ...
 * @sp: ...
 * @lenght: ...
 *
 */
void check_chain(pid_t *str_pat, char *buf, size_t *adds, size_t sp, size_t lenght)
{
size_t a = *adds;

if (str_pat->cmd_buf_type == CMD_AND)
{
if (str_pat->status)
{
buf[sp] = 0;
a = lenght;
}
}
if (str_pat->cmd_buf_type == CMD_OR)
{
if (!str_pat->status)
{
buf[sp] = 0;
a = lenght;
}
}

*adss = a;
}

/**
 * replace_string - ...
 *
 * @old: ...
 * @newstr: ...
 *
 * Return: ...
 */
int replace_string(char **old, char *newstr)
{
free(*old);
*old = newstr;
return (1);
}


/**
 * replace_alias - ...
 *
 * @str_pat: ...
 *
 * Return: ...
*/
int replace_alias(pid_t *str_pat)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
node = node_starts_with(str_pat->alias, str_pat->argv[0], '=');
if (!node)
{
return (0);
}
free(str_pat->argv[0]);
p = _strchr(node->str, '=');
if (!p)
{
return (0);
}
p = _strdup(p + 1);
if (!p)
{
return (0);
}
str_pat->argv[0] = p;
}
	
return (1);
}

