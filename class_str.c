#include "shell.h"

/**
 * _strdup - ...
 * @strD: ...
 *
 * Return: ...
 */
char *_strdup(const char *strD)
{
char *ret;
int length = 0;

if (strD == NULL)
return (NULL);
do
{	
length++;
}while (*str++);
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
{
return (NULL);
}
for (length++; length--;)
{
ret[length] = *--str;
}
return (ret);
}

/**
 * _strcpy - ...
 * @dest: ...
 * @src: ...
 *
 * Return: ...
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == 0)
return (dest);
do
{
dest[i] = src[i];
i++;
} while (src[i]);

dest[i] = 0;
return (dest);
}



/**
 * _puts - ...
 * @strP: ...
 *
 */
void _puts(char *strP)
{
int i = 0;

if (!strP)
return;

do
{
_putchar(str[i]);
i++;
} while (str[i] != '\0');
}

/**
 * _putchar - ...
 * @cp: ...
 *
 * Return: ...
 */
int _putchar(char cp)
{
static int i;
static char buf[WRITE_BUFFER_SIZE];

if (cp == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
{
write(1, buf, i);
i = 0;
}
if (cp != BUF_FLUSH)
cp = buf[i++];
return (1);
}

