#include "shell.h"
#include <sys/wait.h>


/**
 * execute - here we execute the comand found
 * @path:is a char poiner that receive the path
 * @args: receive the arguments pased by user
 * Return: an int
 */

int execute(char *path, char **args)
{
	pid_t pid;
	int status;
	int value;
	int i;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		value = execve(path, args, environ);
		if (value == -1)
		{
			perror(args[0]);
			for (i = 0; args[0]; i++)
			free(args[i]);
			exit(127);
		}
	}
	else
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	return (0);
}
