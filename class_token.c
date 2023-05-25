#include "shell.h"

/**
 * **str_tow - ...
 * @str: ...
 * @del: ...
 * Return:...
 */
char **str8tow(char *str, char del)
{
int i, j, k, m, wnum = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
wnum++;
if (wnum == 0)
return (NULL);
s = malloc((1 + wnum) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (str[i] == d && str[i] != d)
i++;
k = 0;
while (str[i + k] != d && str[i + k] && str[i + k] != del)
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

/**
 * **strtow - ...
 * @str: ...
 * @del: ...
 * Return: ...
 */

char **strtow(char *str, char *del)
{
int i, j, k, m;
int wnum = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
if (!del)
del = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], del) && (is_delim(str[i + 1], del) || !str[i + 1]))
wnum++;

if (wnum == 0)
return (NULL);
s = malloc((1 + wnum) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < wnum; j++)
{
while (is_delim(str[i], d))
i++;
k = 0;
while (!is_delim(str[i + k], del) && str[i + k])
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

