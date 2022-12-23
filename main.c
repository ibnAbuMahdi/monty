#include <stdio.h>
#include "monty.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * main - code driver
 * @ac: arg count
 * @av: arg list
 * Return: 0 always
 */

int main(int ac, char **av)
{
	if (check_args(ac))
	{
		if (check_file(av[1]))
		{
			handle_file(av[1]);
		}
	}
	free_dlistint(front);
	return (0);
}

/**
 * check_args - checks for valid number of args
 * @ac: args count
 * Return: 1 if valid number, 0 o.w.
 */

int check_args(int ac)
{
	error_t *err = malloc(sizeof(error_t));

	if (!err)
		malloc_error();
	if (ac != 2)
	{
		err->code = USAGE_ERROR;
		err->msg = "USAGE: monty file";
		err->exit_code = EXIT_FAILURE;
		print_err(err);
	}
	if (err)
		free(err);
	return (1);
}

/**
 * check_file - check if file is valid
 * @file_path: file path
 * Return: 1 if file valid and 0 o.w.
 */

int check_file(char *file_path)
{
	error_t *err = malloc(sizeof(error_t));

	if (!err)
		malloc_error();
	if (open(file_path, O_RDONLY) > 0)
	{
		free(err);
		return (1);
	}
	else
	{
		err->code = FILE_OPEN_ERROR;
		err->msg = "Error: Can't open file";
		err->exit_code = EXIT_FAILURE;
		err->file = file_path;
		print_err(err);
		free(err);
	}
	return (0);
}

/**
 * handle_file - handles file if valid
 * @file_path: file path
 */

void handle_file(char *file_path)
{
	char *buf = NULL, **args;
	size_t n = 0;
	size_t readno;
	unsigned int l_no = 0;
	FILE *stream = fopen(file_path, "r");

	front = NULL;
	while ((readno = _getline(&buf, &n, stream)) > 0)
	{
		l_no++;
		args = parse_line(buf);
		if (process_args(args, l_no, front))
			free_pp((void **) args);
	}
	free(buf);
	fclose(stream);
}

/**
 * process_args - processes args of line
 * @args: the args
 * @l_no: line number
 * @front: the front node in list
 * Return: 1 always
 */

int process_args(char **args, unsigned int l_no, stack_t *front)
{
	int i, size;
	size_t ac;
	stack_t *new_node = NULL;
	instruction_t inst[] = {{"pall", pall}, {"push", push}, {"pint", pint},
		{"pop", pop}, {"swap", swap}};

	ac = count(args);
	if (ac == 0)
		invalid_inst("", l_no);
	if (ac > 1)
	{
		new_node = malloc(sizeof(stack_t));
		if (!new_node)
			malloc_error();
	}
	size = sizeof(inst) / sizeof(inst[0]);
	for (i = 0; i < size; i++)
	{
		if (strcmp(args[0], inst[i].opcode) == 0)
		{
			if (ac > 1 && !contains_letter(args[1]))
			{
				new_node->n = atoi(args[1]);
				inst[i].f(&new_node, l_no);
			}
			else
			{
				inst[i].f(&front, l_no);
			}
			if (new_node)
				free(new_node);
			return (1);
		}
	}
	free(new_node);
	invalid_inst(args[0], l_no);
	return (1);
}





