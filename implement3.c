#include "monty.h"

/**
 * _div- divides top elements of stack
 * @_data: head of list
 * @linecount: count lines
 */
void _div(stack_t **_data, unsigned int linecount)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *_data;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*_data)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}

	tmp = (*_data)->next;
	tmp->n /= (*_data)->n;
	_pop(_data, linecount);
}

/**
 * _mul- multiplies top of stack
 * @_data: head of list
 * @linecount: count lines
 */
void _mul(stack_t **_data, unsigned int linecount)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *_data;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}

	tmp = (*_data)->next;
	tmp->n *= (*_data)->n;
	_pop(_data, linecount);
}

/**
 * _mod- top 2 elements mod
 * @_data: head of the list
 * @linecount: line count
 */
void _mod(stack_t **_data, unsigned int linecount)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *_data;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*_data)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}

	tmp = (*_data)->next;
	tmp->n %= (*_data)->n;
	_pop(_data, linecount);
}

/**
 * _pchar- character value
 * @_data: head of list
 * @linecount: number of line
 */
void _pchar(stack_t **_data, unsigned int linecount)
{
	if (_data == NULL || *_data == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*_data)->n < 0 || (*_data)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*_data)->n);
}

/**
 * _pstr- string values
 * @_data: head of list
 * @linecount: line count
 */
void _pstr(stack_t **_data, unsigned int linecount)
{
	stack_t *tmp;
	(void)linecount;

	tmp = *_data;

	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
