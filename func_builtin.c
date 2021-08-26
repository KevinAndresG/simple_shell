#include "shell.h"

/**
 * p_error - function that print errors
 * @argv: argument
 * @count: the counter
 * Return: void
 */
void p_error(char *argv, __attribute__((unused)) int count)
{
	char *msg2 = ": not found\n";
	char *msg = "hsh: ";

	write(2, msg, strlen(msg));
	_strcat(argv, msg2);
	write(2, argv, _strlen(argv));
}

/**
 * _sign - signal that can report some exceptional behavior
 * @signal: signal
 * Return: void
 */
void _sign(__attribute__((unused)) int signal)
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "Holbies$ ", 9);
}

/**
 * _exit_o - function that exits the shell
 * @argv: comand.
 * @line: line.
 * Return: void
 */
void _exit_o(char *argv, char *line)
{
if (_strcmp(argv, "exit") == 0)
	{
		if (count_words(line, " ") > 1)
		{
		perror("1: exit: Illegal number");
		}
		else
		{
		free(argv);
		free(line);
		exit(0);
		}
	}
}