#include "shell.h"
#define DELIMITERS " \n"

/**
 * tokenize - separate a line in arguments
 * @str: get the string to be tokenized
 * Return: char double pointer
 */

char **tokenize(char *str)
{
	int bufsize = count_words(str); /* to assign the exact memory*/
	char *str_temp;
	int position = 0;
	char *divided_args = NULL;
	char **args = malloc(bufsize * sizeof(char *) + 1);

	/*verify if malloc alloc the memory*/
	if (args == NULL)
	{
		return (NULL);
	}

	/* divide the str "the line obtained" in smaller strings */
	/* get pointer to the first string(argument)*/
	str_temp = strdup(str);
	divided_args = strtok(str_temp, DELIMITERS);
	while (divided_args != NULL)
	{
		/* asign the argument to each position of the array args*/
		args[position] = divided_args;
		position++;
		/* get other strings*/
		divided_args = strtok(NULL, DELIMITERS);
	}
	args[position] = NULL;
	return (args); /*return the list of arguments*/
}
