#include "shell.h"
#include <sys/wait.h>

/* https://www.delftstack.com/howto/c/execvp-in-c/ */
extern char **environ;

int execute(char *path, char **args)
{
  pid_t pid, wpid;
  int status;
  char *env;

  pid = fork();
  if (pid == 0)
  {
    if (execve(path, args, environ) == -1)
	{
      perror("Error:");
    }
    /*exit(EXIT_FAILURE);*/
	}
  else if (pid < 0)
  {
    perror("Error:");
  }
  else
  {
    /*Parent process*/
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return (0);
}
