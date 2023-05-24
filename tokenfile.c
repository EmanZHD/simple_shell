#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * **strgtow - this function splits a string into words
 * Repeat delimiters are ignored
 * @strg: input string
 * @del: delimeter string
 * Return: return a pointer to an array of strings,
 * or NULL on failure
 */

char **strgtow(char *strg, char *del)
{
	int i, j, i3, i4, numbwrd = 0;
	char **s;

	if (strg == NULL || strg[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (i = 0; strg[i] != '\0'; i++)
		if (!is_delm(strg[i], del) && (is_delm(strg[i + 1], del) || !strg[i + 1]))
			numbwrd++;

	if (numbwrd == 0)
		return (NULL);
	s = malloc((1 + numbwrd) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numbwrd; j++)
	{
		while (is_delm(strg[i], del))
			i++;
		i3 = 0;
		while (!is_delm(strg[i + i3], del) && strg[i + i3])
			i3++;
		s[j] = malloc((i3 + 1) * sizeof(char));
		if (!s[j])
		{
			for (i3 = 0; i3 < j; i3++)
				free(s[i3]);
			free(s);
			return (NULL);
		}
		for (i4 = 0; i4 < i3; i4++)
			s[j][i4] = strg[i++];
		s[j][i4] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strgtow2 - this function splits a string into words
 * @strg: input string
 * @del: delimeter
 * Return: return a pointer to an array of strings
 * or NULL on failure
 */
char **strgtow2(char *strg, char del)
{
	int i, j, i3, i4, numbwrd = 0;
	char **s;

	if (strg == NULL || strg[0] == 0)
		return (NULL);
	for (i = 0; strg[i] != '\0'; i++)
		if ((strg[i] != del && strg[i + 1] == del) ||
				    (strg[i] != del && !strg[i + 1]) || strg[i + 1] == del)
			numbwrd++;
	if (numbwrd == 0)
		return (NULL);
	s = malloc((1 + numbwrd) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numbwrd; j++)
	{
		while (strg[i] == del && strg[i] != del)
			i++;
		i3 = 0;
		while (strg[i + i3] != del && strg[i + i3] && strg[i + i3] != del)
			i3++;
		s[j] = malloc((i3 + 1) * sizeof(char));
		if (!s[j])
		{
			for (i3 = 0; i3 < j; i3++)
				free(s[i3]);
			free(s);
			return (NULL);
		}
		for (i4 = 0; i4 < i3; i4++)
			s[j][i4] = strg[i++];
		s[j][i4] = 0;
	}
	s[j] = NULL;
	return (s);
}

