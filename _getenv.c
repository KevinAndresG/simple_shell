#include "shell.h"

/*allows us to iterate through environ*/
extern char **environ;
/* environ = array of strings(name=value) */

char *_getenv(const char *name)
{
	char *value = NULL, *newvar = NULL, *envtemp = NULL;
	int i = 0;

	if (name == NULL)
	return(NULL);
    while (environ[i] != NULL)
	{
	envtemp = strdup(environ[i]);
	newvar = strtok(envtemp, "=\n");
    if (strcmp(newvar, name) == 0)
	{
        value = strtok(NULL, "=\n");
	}
	i++;
	}
	/*return the value of the variable*/
	return (value);
}
