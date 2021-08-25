#include "shell.h"
#define DELIMITERS " \n"

/**
 * tokenize - separate a line in arguments.
 * @str: get the string to be tokenized.
 * @delim: string with delimiters.
 * Return: a pointer to an array of strings.
 */

char **tokenize(char *str, char *delim)
{
	int bufsize = count_words(str, delim); /* to assign the exact memory*/
	char *str_temp;
	int position = 0;
	char **args = malloc(bufsize * sizeof(char *) + 1);

	/*verify if malloc alloc the memory*/
	if (args == NULL)
	{
		return (NULL);
	}

	/* divide the str "the line obtained" in smaller strings */
	/* get pointer to the first string(argument)*/
	str_temp = _strdup(str);
	args[0] = strtok(str_temp, delim);
	for (position = 1; position < bufsize; position++)
	{
		/* asign the argument to each position of the array args*/
		/* get othe strings*/
		args[position] = strtok(NULL, delim);
	}
	return (args); /*return the list of arguments*/
}
