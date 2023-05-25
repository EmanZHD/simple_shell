#include "shell.h"

/**
 * _getenv - Function that retrieves the value
 * of an environment var
 * @name: the string input
 * Return: return value of an environment var
 */

char *_getenv(char *name)
{
	int a = -1;
	size_t name_leng;

	if (name == NULL || *name == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	name_leng = _strlen(name);

	while (environ[++a])
	{
		if (!_strncmp(environ[a], name, name_leng) && environ[a][name_leng] == '=')
		{
			return (environ[a] + name_leng + 1);
		}
	}
	return (NULL);
}

/**
 * path_handling - Function that locat the executable
 * file associated with a given command
 * @data: the string input
 * Return: return void
 */
int path_handling(input *data)
{
	char *tocken, *pat,
		*pats = malloc(_strlen(_getenv("PATH") ? _getenv("PATH") : "") + 1);
	size_t tocken_len;
	int chek = -1;

	if (!_getenv("PATH"))
		goto free;
	_strcpy(pats, _getenv("PATH"));
	if (pats == NULL)
		goto free;
	tocken = strtok(pats, ":");
	while (tocken)
	{
		tocken_len = _strlen(tocken) + _strlen(data->av[0]) + 2;
		pat = malloc(tocken_len);
		if (pat == NULL)
			return (chek);
		_strcpy(pat, tocken);
		_strcat(pat, "/");
		_strcat(pat,  data->av[0]);
		if (access(pat, F_OK) == 0)
		{
			free(data->av[0]);
			data->av[0] = _strdup(pat);
			free(pat);
			chek = 0;
			break;
		}
		free(pat);
		tocken = strtok(NULL, ":");
	}
free:
	free(pats);
	return (chek);
}

