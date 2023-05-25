#include "shell.h"

/**
 * _realloc - Function that changes the size of memory
 *  @ptr: for pointer to pointer
 *  @size: the size
 *  Return: keep
*/

char **_realloc(char **ptr, size_t size)
{
int leng;
char **keep;

leng = 0;
if (ptr == NULL)
{
keep = malloc(sizeof(char *) * 2);
keep[0] = NULL;
keep[1] = NULL;
return (keep);
}

keep = malloc(size);
while (ptr[leng])
{
keep[leng] = _strdup(ptr[leng]);
free(ptr[leng]);
leng++;
}
free(ptr);
keep[leng++] = NULL;
keep[leng] = NULL;
return (keep);
}

/**
 * free_array - Function that free an array of pointer
 * @array: the array of pointer
 * Return: return void
 */

void free_array(char **array)
{
int a;

if (!array)
return;

for (a = 0; array[a]; a++)
free(array[a]);

free(array);
}

