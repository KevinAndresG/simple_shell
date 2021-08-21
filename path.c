#include "shell.h"
#include <unistd.h>
#include <sys/stat.h>

char *get_path(const char *args)
/*void main(void)*/
{
	char *value_path = _getenv("PATH");
	char *path = NULL, *argv = NULL, *temp = NULL;
	struct stat st = {0};

	char *directory = malloc(strlen(value_path) * sizeof(char *) + 1);
	/*if (directory == NULL)
		return (NULL);*/
	directory = strtok(value_path, ":\n");

	argv = strdup(args);
	/*argv = strcat("/", argv);*/ /* stack smashing al concatenar*/
	while (directory != NULL || value_path == NULL)
	{
		temp = strdup(directory);
		path = _strcat(temp, "/");
		path = _strcat(path, argv);
		/*printf("%s\n", path);*/
		if (stat(path, &st) == -1)
		{
			/*printf("error: %s\n", path);*/
		}
		else
		{
			return (path);
			/*printf("%s\n", path);*/
		}
		directory = strtok(NULL, ":\n");
	}
	free(directory);
	free(value_path);
}
