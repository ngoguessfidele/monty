#include "monty.h"

global_t data;

/**
 * _free- frees the global variables
 */
void _free(void)
{
	free_dlistint(data.head);
	free(data.buffer);
	fclose(data.fd);
}

/**
 * _set- set the data
 *
 * @fd: fd
 * Return: no return
 */
void _set(FILE *fd)
{
	data.lifo = 1;
	data.counter = 1;
	data.arg = NULL;
	data.head = NULL;
	data.fd = fd;
	data.buffer = NULL;
}

/**
 * check_input- check if no error
 * @argc: number of arguments
 * @argv: argument vector
 * Return: struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main- Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	_set(fd);
	nlines = getline(&data.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtok(data.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = search(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", data.counter);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				_free();
				exit(EXIT_FAILURE);
			}
			data.arg = _strtok(NULL, " \t\n");
			f(&data.head, data.counter);
		}
		nlines = getline(&data.buffer, &size, fd);
		data.counter++;
	}

	_free();

	return (0);
}
