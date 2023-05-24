#include "shell.h"

/**
 * inter_active - ...
 *
 * @sdr_address: ...
 *
 * Return: ...
 */
int inter_active(info_t *sdr_address)
{
	return (isatty(STDIN_FILE) && sdr_address->reading_fd <= 2);
}

/**
 * dlm_string - ...
 *
 * @check: ...
 * @delimetre: ...
 *
 * Return: ...
 */
int dlm_string(char check, char *delimetre)
{
	while (*delimetre)
		if (*delimetre++ == check)
			return (1);
	return (0);
}

 
/**
 * char_alpha - ...
 *
 * @inchar: ...
 *
 * Return: ...
 */

int char_alpha(int inchar)
{
	if ((inchar >= 'a' && inchar <= 'z') || (inchar >= 'A' && inchar <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * conv_str_int - ...
 *
 * @str: ...
 *
 * Return: ...
 */

int conv_str_int(char *str)
{
	int arg, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (arg = 0; str[arg] != '\0' && flag != 2; arg++)
	{
		if (str[arg] == '-')
			sign *= -1;

		if (str[arg] >= '0' && str[arg] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[arg] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}


