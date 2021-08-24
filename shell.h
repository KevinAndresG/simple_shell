#ifndef SHELL_H
#define SHELL_H
extern char **environ;
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(void);
char *read_line(void);
char **tokenize(char *str, char *delim);
int execute(char *path, char **args);
char *_getenv(const char *name);
char *get_path(char *args);

/*FUNCTION HELPERS*/
int count_words(char *str, char *delim);
int _strlen(const char *s);
char *_strdup(const char *s);
char *_strcat(char *dest, char *src);

#endif
