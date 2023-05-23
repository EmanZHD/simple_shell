#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * _erratoi - this function converts a string to an integer
 * @str: string to be converted
 * Return: return 0 if no numbers in string
 * converted number otherwise -1 on error
 */
int _erratoi(char *str)
{
	int a = 0;
	unsigned long int rslt = 0;

	if (*str == '+')
		str++;
	for (a = 0;  str[a] != '\0'; a++)
	{
		if (str[a] >= '0' && str[a] <= '9')
		{
			rslt *= 10;
			rslt += (str[a] - '0');
			if (rslt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rslt);
}

/**
 * prnt_error - this function prints an error message
 * @info: parameter & return info struct
 * @estr: the string containing specified error type
 * Return: return 0 if no numbers in string
 * converted number otherwise -1 on error
 */
void prnt_error(info_t *info, char *estr)
{
	_epts(info->fname);
	_epts(": ");
	prnt_d(info->ln_count, STDERR_FILENO);
	_epts(": ");
	_epts(info->argv[0]);
	_epts(": ");
	_epts(estr);
}

/**
 * prnt_d - this function prints a decimal (integer) number (base 10)
 * @input: input
 * @fdd:filedescriptor to write to
 * Return: return number of characters printed
 */
int prnt_d(int input, int fdd)
{
	int (*__ptchar)(char) = _ptchar;
	int a, count = 0;
	unsigned int _abs_, current;

	if (fdd == STDERR_FILENO)
		__ptchar = _eptchar;
	if (input < 0)
	{
		_abs_ = -input;
		__ptchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / a)
		{
			__ptchar('0' + current / a);
			count++;
		}
		current %= a;
	}
	__ptchar('0' + current);
	count++;

	return (count);
}

/**
 * cnvrt_number - this function converter function
 * a clone of itoa
 * @numb: the number
 * @base: the base
 * @flag: the argument flags
 * Return: return string
 */
char *cnvrt_number(long int numb, int base, int flag)
{
	static char *array;
	static char buffer[50];
	char signl = 0;
	char *pt;
	unsigned long m = numb;

	if (!(flag & CONVERT_UNSIGNED) && numb < 0)
	{
		m = -numb;
		signl = '-';

	}
	array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buffer[49];
	*pt = '\0';

	do	{
		*--pt = array[m % base];
		m /= base;
	} while (m != 0);

	if (signl)
		*--pt = signl;
	return (pt);
}

/**
 * rmv_comments - this function replaces first instance of '#' with '\0'
 * @bufr: the address of the string to modify
 * Return: return always 0;
 */
void rmv_comments(char *bufr)
{
	int a;

	for (a = 0; bufr[a] != '\0'; a++)
		if (bufr[a] == '#' && (!a || bufr[a - 1] == ' '))
		{
			bufr[a] = '\0';
			break;
		}
}

