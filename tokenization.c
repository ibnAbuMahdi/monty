#include "monty.h"

/**
 * split_words - Split a line into words
 *
 * @line: Line to spli
 * @sep: Delimiters for split the words
 *
 * Return: Set of words
 **/
char **split_words(char *line, const char *sep)
{
	char **words, **tmp, *token;
	size_t new_size, old_size;

	old_size = sizeof(char *);
	words = malloc(old_size);
	if (!words)
		malloc_error();
	if (words != NULL)
	{
		new_size = 1;
		token = strtok(line, sep);
		while (token)
		{
			if (token[0] == '#')
				break;
			tmp = _realloc(words, old_size, (new_size + 1) * sizeof(char *));
			old_size = (new_size + 1) * sizeof(char *);
			if (tmp == NULL)
				break;
			words = tmp;
			++new_size;
			words[new_size - 2] = malloc(_strlen(token) + 1);
			if (words[new_size - 2] == NULL)
			{
				free(words);
				free(tmp);
				malloc_error();
			}
			if (words[new_size - 2] != NULL)
				_strcpy(words[new_size - 2], token);

			token = strtok(NULL, sep);

			tmp = NULL;
		}

		words[new_size - 1] = NULL;
	}
	free(line);
	return (words);
}

/**
 * join_words - Join 3 words with a separator
 * Description: Result -> w1.sep.w2.sep.nl
 * @word1: Word1 to join
 * @word2: Word2 to join
 * @word3: Word3 to join
 * @sep: Separator between the words
 *
 * Return: Line composed by 3 parts followed by a separator and
 * end by a new line
 **/
char *join_words(char *word1, char *word2, char *word3, const char *sep)
{
	char *aux;
	int size_str1, size_str2, size_str3, size_sep;

	size_str1 = size_str2 = size_sep = 0;

	if (word1 != NULL)
		size_str1 = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		size_str2 = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		size_str3 = _strlen(word3);
	else
		word3 = "";

	if (sep != NULL)
		size_sep = _strlen((char *)sep);
	else
		sep = "";

	aux = malloc(size_str1 + size_str2 + size_sep + size_str3 + size_sep + 2);
	if (aux == NULL)
		malloc_error();

	aux = _strcpy(aux, word1);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word2);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word3);
	aux = _strcat(aux, "\n");

	return (aux);
}

/**
 * count - counts args
 * @args: the args
 * Return: no of args
 */

size_t count(char **args)
{
	size_t i = 0;

	if (!args)
		return (i);
	while (args[i])
		i++;
	return (i);
}

/**
 * rem_space - removes space in string @s
 * @s: the string
 * Return: a new string
 */

char *rem_space(char *s)
{
	size_t i = 0, j = 0, start = 0, len;
	char *o;

	if (!s)
		return (NULL);
	o = malloc(_strlen(s) + 1);
	if (!o)
		malloc_error();
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && !start)
		{
			o[j] = s[i];
			start = 1;
			j++;
		}
		else if (start)
		{
			o[j] = s[i];
			j++;
		}
		i++;
	}
	o[j] = '\0';
	len = j > 0 ? j - 1 : 0;
	while (o[len])
	{
		if (o[len] == ' ' || o[len] == '\t' || o[len] == '\n')
			o[len] = '\0';
		else
			break;
		if (len > 0)
			len--;
	}
	free(s);
	return (o);
}


