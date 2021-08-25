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
