#include "shell.h"

/*allows us to iterate through environ*/
/* environ = array of strings(name=value) */

/**
 * _getenv - to get environment
 * @name: here we save the line
 * Return: a char pointer
 */

char *_getenv(const char *name)
{
	char *value = NULL, *newvar = NULL, *envtemp = NULL;
	int i = 0;

	if (name == NULL)
		return (NULL);
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
	free(envtemp);
	free(newvar);
}
