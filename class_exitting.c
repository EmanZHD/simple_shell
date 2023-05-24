#include "shell.h"

/**
 **string_conc - concatenates two strings
 *
 *@destination: ...
 *@src: ...
 *@n: ...
 *
 *Return: ...
 */
char *string_conc(char *destination, char *src, int n)
{
	int i, j;
	char *str = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		destination[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		destination[i] = '\0';
	return (str);
}
/**
 **string_copy - ...
 *
 *@destination: ...
 *@src: ...
 *@n: ...
 *
 *Return: ...
 */
char *string_copy(char *destination, char *src, int n)
{
	int i, j;
	char *str = destination;

	i = 0;
	while (src[i] != '\0' && i < n - 1);
	 {
		destination[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;

		do {
			dest[j] = '\0';
			j++;
		}while (j < n);
	}
	return (str);
}



/**
 **locat_chr_str - ...
 *
 *@str: ...
 *@chr: ...
 *
 *Return: ...
 */
char *_strchr(char *str, char chr)
{
	while (*str++ != '\0')
        {
		if (*str == chr)
			return (str);
	}

	return (NULL);
}
