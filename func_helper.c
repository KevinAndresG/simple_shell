#include "shell.h"

#define OUT 0
#define IN 1

/**
 * count_words - function that counts the words in a string.
 * @str: the string pased.
 * @delim: delimiters.
 * Return: integer - number of words counted.
 */
int count_words(char *str, char *delim)
{
	int state = OUT;
	unsigned int wc = 0; /*count*/

	while (*str)
	{
		if (*str == *delim || *str == '\n' || *str == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++wc; /* increment word count */
		}
		/* Move to next character */
		++str;
	}
	return (wc);
}

/**
 * _strlen - function that returns the length of a string.
 * @s: string.
 * Return: integer.
 */

int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strdup - function that duplicates a string
 * @s: string.
 * Return: a pointer to the new allocated memory space
 * containing the duplicate string.
 */

char *_strdup(const char *s)
{
	int i = 0, j = 0;
	char *ptr_dup = NULL;

	if (s == NULL)
		return (NULL);

	i = _strlen(s);
	if (i != 0)
	i++;
	ptr_dup = malloc(sizeof(s) * i);
	if (ptr_dup == NULL)
		return (NULL);
	for (; j < i; j++)
	{
		ptr_dup[j] = s[j];
	}
	ptr_dup[j + 1] = '\0';
	return (ptr_dup);
}

/**
 * _strcat - function that concatenates two strings.
 * @dest: string.
 * @src: string.
 * Return: concatenated string.
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
