#include "shell.h"
#include <sys/wait.h>

/* https://www.delftstack.com/howto/c/execvp-in-c/ */

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

	pid = fork();
	if (pid == 0)
	{
		execve(path, args, environ);
	}
	else if (pid < 0)
	{
		perror("Erroor:");
	}
	else
	{
		/*Parent process*/
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
