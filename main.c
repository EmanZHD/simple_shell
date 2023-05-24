#include "shell.h"

/****************** Done By Imane ZAHID & Ghita BOUZRBAY ******************/

/**
 * main - this function entry point
 * @ac: the arg count
 * @av: the arg vector
 * Return: return 0 on success, and 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fdd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fdd)
			: "r" (fdd));

	if (ac == 2)
	{
		fdd = open(av[1], O_RDONLY);
		if (fdd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_epts(av[0]);
				_epts(": 0: :( Can't open ");
				_epts(av[1]);
				_eptchar('\n');
				_eptchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfdd = fdd;
	}
	populate_envr_list(info);
	read_histry(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}

