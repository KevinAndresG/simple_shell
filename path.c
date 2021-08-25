#include "shell.h"
#include <unistd.h>
#include <sys/stat.h>

/**
 * get_path - Function that looks for the command entered
 * in the PATH directories.
 * @args: command to search.
 * Return: a pointer to the path where the command is located.
 */

char *get_path(char *args)
{
	char *value_path = NULL;
	char *temp = NULL, **new_path;
	struct stat st = {0};
	int numpath, i;

	if (stat(args, &st) == 0)
		return (args);

	value_path = _getenv("PATH");
	numpath = count_words(value_path, ":");

	new_path = tokenize(value_path, ":");

	for (i = 0; i < numpath; i++)
	{
		temp = _strdup(new_path[i]);
		_strcat(temp, "/");
		_strcat(temp, args);
		if (stat(temp, &st) == 0)
		{
			free(new_path);
			return (temp);
		}
	}
	free(new_path);
	perror(args);
	return (NULL);
}
