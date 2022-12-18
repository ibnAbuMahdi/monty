#include "general.h"
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_err - prints error messages
 * @error: the error struct
 */

void print_err(error_t *error)
{
	switch (error->code)
	{

		case FILE_OPEN_ERROR:
			fprintf(stderr, "%s %s\n", error->msg, error->file);
			break;
		case USAGE_ERROR:
			fprintf(stderr, "%s\n", error->msg);
	}
	exit(error->exit_code);
	free(error->msg);

}

/**
 * malloc_error - prints error messages to signify malloc error
 */

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * invalid_inst - invalid instruction error
 * @opcode: the op code provided
 * @lno: the line number
 */

void invalid_inst(char *opcode, unsigned int lno)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", lno, opcode);
	exit(EXIT_FAILURE);
}


