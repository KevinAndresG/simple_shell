#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

int main(void);
char *read_line(void);
char **tokenize(char *str, char *delim);
int execute(char *path, char **args);
char *_getenv(const char *name);
char *get_path(char *args);
void _sign(__attribute__((unused)) int signal);

/*FUNCTION HELPERS*/
int count_words(char *str, char *delim);
int _strlen(const char *s);
char *_strdup(const char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void p_error(char *argv, int count);

#endif
