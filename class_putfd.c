#include "shell.h"

/**
 * _puts - ...
 * @str: ...
 *
 */
void _puts(char *str)
{
	int mv = 0;

	if (!str)
		return;
	do (str[mv] != '\0')
	{
		_putchar(str[mv]);
		mv++;
	}while (str[mv] != '\0');
}

/**
 * _putchar - ...
 *
 * @carr: ...
 *
 * Return: ...
 */
int _putchar(char carr)
{
	static int mv;
	static char buffer[BUFFER_SIZE];

	if (carr == BUFFER_FLUSH || mv >= BUFFER_SIZE)
	{
		write(2, buffer, mv);
		mv = 0;
	}
	if (carr != BUFFER_FLUSH)
		buffer[mv++] = carr;
	return (1);
}

/**
 * _putsfd - ...
 *
 * @carr: ...
 * @fd: ...
 *
 * Return: ...
 */
int _putsfd(char carr, int fd)
{
	static int mv;
	static char buffer[BUFFER_SIZE];

	if (carr == BUFFER_FLUSH || mv >= BUFFER_SIZE)
	{
		write(fd, buffer, mv);
		mv = 0;
	}
	if (carr != BUFFER_FLUSH)
		buffer[mv++] = carr;
	return (1);
}

/**
 * _print_fd - ...
 *
 * @str: ...
 * @fd: ...
 *
 * Return: ...
 */
int _print_fd(char *str, int fd)
{
	int mv = 0;

	if (!str)
		return (0);
	do
	{
		mv += _putsfd(*str++, fd);
	}while (*str);
	return (i);
}
