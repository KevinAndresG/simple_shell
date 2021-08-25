#include "shell.h"

/**
 * main - main function
 * Return: an integer.
 */

int main(void)
{
	char *prompt = "Holbies$ ";
	char *line;
	char **list_args; /*array that save all arguments*/
	char *argv, *path;

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, prompt, strlen(prompt));
		line = read_line(); /* get line written*/
		if (line == NULL)
			exit(0);
		list_args = tokenize(line, " \n"); /*split line for get arguments*/
		argv = list_args[0];

		if (strcmp(argv, "exit") == 0)
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
			p_error();
		}
		execute(path, list_args);
	}
	free(line);
}
