#include "shell.h"

/**
 * _atoi - Function that converts string to int.
 * @s: that pointer to string
 * Return: return convert value
 */

int _atoi(char *s)
{
int a;
int b, c;

b = 0;
c = -1;
for (a = 0; s[a] != '\0'; a++)
{
if (s[a] == '-')
c *= -1;

if (s[a] > 47 && s[a] < 58)
{
if (b < 0)
b = (b * 10) - (s[a] - '0');
else
b = (s[a] - '0') * -1;

if (s[a + 1] < 48 || s[a + 1] > 57)
break;
}
}
if (c < 0)
b *= -1;

return (b);
}

/**
 * _strncmp - Function that comares the first n chars between two strings
 * @s1: that pointer to string
 * @s2: that pointer to string
 * @n: the number of characters
 * Return: integer
 */

int _strncmp(char *s1, char *s2, unsigned int n)
{
unsigned int a = 0;

while (a < n && (s1[a] != '\0' || s2[a] != '\0'))
{
if (s1[a] != s2[a])
return (s1[a] - s2[a]);
a++;
}
return (0);
}

