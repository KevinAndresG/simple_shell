#include "shell.h"

/**
 * main - main function
 * Return: an integer.
 */

int main(void)
{
	char *line;
	char **list_args; /*array that save all arguments*/
	char *argv, *path;
	int count = 0;

	signal(SIGINT, _sign);
	while (1)
	{
		line = read_line(); /* get line written*/
		count++;
		if (line != NULL && line[0] != '\n')
		{
			list_args = tokenize(line, " \n"); /*split line for get arguments*/
			argv = list_args[0];

			if (_strcmp(argv, "exit") == 0)
			{
				if (count_words(line, " ") > 1)
				{
					perror("1: exit: Illegal number: args");
				}
				else
				{
					return (0);
				}
			}
			path = get_path(argv);
			if (path == NULL)
			{
				p_error(argv, count);
			}
			if (path != NULL)
			{
				execute(path, list_args);
			}
		}
	}
	free(line);
}
