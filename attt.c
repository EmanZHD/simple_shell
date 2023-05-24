#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * intractive - this function returns true if shell is interactive mode
 * @info: struct address
 * Return: return 1 if interactive mode,and 0 otherwise
 */
int intractive(info_t *info)
{
        return (isatty(STDIN_FILENO) && info->readfdd <= 2);
}

/**
 * is_delm - this function checks if character is a delimeter
 * @ch: char to check
 * @delm: delimeter string
 * Return: return 1 if true,and 0 if false
 */
int is_delm(char ch, char *delm)
{
        while (*delm)
                if (*delm++ == ch)
                        return (1);
        return (0);
}

/**
 * _alpha - this function checks for alphabetic character
 * @ch: character to input
 * Return: return 1 if ch is alphabetic,and 0 otherwise
 */

int _alpha(int ch)
{
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                return (1);
        else
                return (0);
}

/**
 * _atoi - this function converts a string to an integer
 * @st: string to be converted
 * Return: return 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *st)
{
        int i, sig = 1, flg = 0, output;
        unsigned int result = 0;

        for (i = 0; st[i] != '\0' && flg != 2; i++)
        {
                if (st[i] == '-')
                        sig *= -1;

                if (st[i] >= '0' && st[i] <= '9')
                {
                        flg = 1;
                        result *= 10;
                        result += (st[i] - '0');
                }
                else if (flg == 1)
                        flg = 2;
        }

        if (sig == -1)
                output = -result;
        else
                output = result;

        return (output);
}
