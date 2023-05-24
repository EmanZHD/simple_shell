#include "shell.h"

/**
 * error_str_int - ...
 *
 * @str: ...
 *
 * Return: ...
 */
int error_str_int(char *str)
{
	int mv = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;
	for (mv = 0;  str[mv] != '\0'; mv++)
	{
		if (str[mv] >= '0' && str[mv] <= '9')
		{
			result *= 10;
			result += (str[mv] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * puts_dec - ...
 *
 * @input: ...
 * @fd:...
 *
 * Return: ...
 */
int puts_dec(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int mv, count = 0;
	unsigned int aad, current;

	if (fd == STDERR_FILENO)
		__putchar = _putchar;
	if (input < 0)
	{
		aad = -input;
		__putchar('-');
		count++;
	}
	else
		aad = input;
	current = aad;
	for (mv = 1000000000; mv > 1; mv /= 10)
	{
		if (aad / mv)
		{
			__putchar('0' + current / mv);
			count++;
		}
		current %= mv;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * putserr - ...
 *
 * @strc_info: ...
 * @str_err: ...
 *
 * Return: ...
 */
void putserr(info_t *strc_info, char *str_err)
{
	_puts(strc_info->filename);
	_puts(": ");
	put_dec(strc_info->line_count, STDERR_FILENO);
	_puts(": ");
	_puts(strc_info->argv[0]);
	_puts(": ");
	_puts(str_err);
}



/**
 * clone_itoa - ...
 *
 * @num: ..
 * @base: ...
 * @arg: ...
 *
 * Return: ...
 */
char *clone_itoa(long int num, int base, int arg)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(arg & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = arg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	while (n != 0)
          {
		*--ptr = array[n % base];
		n /= base;
	}

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * delete_cmt - ...
 *
 * @adress: ...
 *
 * Return: ...
 */
void delete_cmt(char *adress)
{
	int mv;

	for (mv = 0; adress[i] != '\0'; mv++)
		if (adress[mv] == '#' && (!i || adress[mv - 1] == ' '))
		{
			adress[mv] = '\0';
			break;
		}
}

