#include "shell.h"

/**
* _putchar - Function that writes the character
* c to stdout
* @c: character to print
* Return: return 1 for succes, -1 otherwise
*/
int	_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Function that writes string to stdout
 * @s1: string to print
 * Return: return on success 1
*/

void _printf(const char *s1)
{
	int a = 0;

	while (s1[a] != '\0')
	{
		_putchar(s1[a]);
		a++;
	}
}

