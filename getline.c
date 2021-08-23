#include "shell.h"

/**
 * read_line - to get the arguments pased by user
 * Return: a pointer to the string obtained
 */

char *read_line(void)
{
	char *line = NULL; /*save the readed line after the prompt*/
	size_t size = 0;   /*number of characters readed*/

	if (getline(&line, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
		free(line);
		return (NULL);
	}
	return (line);
}
