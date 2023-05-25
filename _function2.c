#include "shell.h"

/**
 *  _white_spaces - Function that remove ' ' and '\t' from all command
 *  @s: for input string
 *  Return: return void
 */

void _white_spaces(char *s)
{
	int a = 0, j = 0;
	int leng = _strlen(s);

	while (a < leng && (s[a] == ' ' || s[a] == '\t'))
		a++;

	while (a < leng)
	{
		s[j] = s[a];
		a++;
		j++;
	}
	s[j] = '\0';

	a = _strlen(s) - 1;
	while (a > 0 && (s[a] == ' ' || s[a] == '\t'))
	{
		s[a] = '\0';
		a--;
	}
}

/**
 * h_cmd - Function that handles and removes comments from command
 * @str: for input string
 * Return: return void
*/

void h_cmd(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		if (str[a] == '#')
		{
			str[a] = '\0';
			break;
		}
		a++;
	}
}

