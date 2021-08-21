#include "shell.h"



extern char **environ;
int main(void)
{
	char *prompt = "Holbies$ ";
	char *line;
	char **list_args; /*array that save all arguments*/
	int st;
	char *argv, *path;

	while (1)
	{
	write(STDOUT_FILENO, prompt, strlen(prompt));
	line = read_line();
	list_args = tokenize(line); /*split line for get arguments*/
	argv = list_args[0];
	
	if (strcmp(argv, "exit") == 0)
	{
	if (count_words(line) > 1)
	{
		perror("1: exit: Illegal number: djdhf");
		exit(EXIT_FAILURE);
	}
	else
	{
	return (0);
	}
	}
	path = get_path(argv);
	/*if (path == NULL)*/
	st = execute(path, list_args);

	/*printf("%s\n", path);
	printf("%s\n", argv);
	printf("-->%s\n-->%s\n-->%s\n", list_args[0], list_args[1], list_args[2]);*/
	}
	free(line);
}

