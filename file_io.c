#include "monty.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * _getline - gets a line from stream file
 * @line: the address of the buffer to store the data obtained
 * @n: the address of the number of data retrived
 * @file: the address of the file
 * Return: the number of data retrieved
 */

size_t _getline(char **line, size_t *n, FILE *file)
{
	size_t max;
	size_t i;
	char c;

	if (*line == NULL)
	{
		*line = malloc(120);
		if (!line)
			malloc_error();
	}
	if (!(*n))
		*n = 120;
	max = *n;
	i = 0;
	while (max == *n)
	{
		for (; i < *n - 1 && ((c = fgetc(file)) > 0)  && c != '\n'; i++)
			*(*line + i) = c;
		if (c == '\n')
		{
			*(*line + i) = c;
			i++;
		}
		if (i == max - 1)
		{
			_realloc(*line, *n, max += 120);
			if (*line)
				*n = max;
		}
		else
		{
			max = i;
		}
	}
	*(*line + i) = '\0';
	return (i);
}

/**
 * parse_line - parses a line containing chars
 * @line: the buffer to parse
 * Return: array of strings in @line
 */

char **parse_line(char *line)
{
	char *new_line = _strdup(line);

	if (!line)
		return (NULL);
	new_line = rem_space(new_line);
	return (split_words(new_line, " \t\n"));
}







