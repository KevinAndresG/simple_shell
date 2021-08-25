#include "shell.h"


void p_error(char *argv, __attribute__((unused)) int count)
{
	char *msg2 = ": not found\n";
	char *msg = "hsh: ";

	write(2, msg, strlen(msg));
	_strcat(argv, msg2);
	write(2, argv, _strlen(argv));
}


void _sing(__attribute__((unused)) int signal)
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "Holbies$ ", 9);
}


