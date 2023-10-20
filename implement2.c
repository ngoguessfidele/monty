#include "monty.h"

/**
 * _queue- set FIFO
 * @_data: head of list
 * @linecount: line count
 */
void _queue(stack_t **_data, unsigned int linecount)
{
	(void)_data;
	(void)linecount;

	data.lifo = 0;
}

/**
 * _stack- sets LIFO
 * @_data: head of list
 * @linecount: line count
 */
void _stack(stack_t **_data, unsigned int linecount)
{
	(void)_data;
	(void)linecount;

	data.lifo = 1;
}

/**
 * _add- adds top elements of stack
 * @_data: head of list
 * @linecount: line count
 */
void _add(stack_t **_data, unsigned int linecount)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *_data;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}
	tmp = (*_data)->next;
	tmp->n += (*_data)->n;
	_pop(_data, linecount);
}

/**
 * _nop- do nothin
 * @_data: head of list
 * @linecount: count lines
 */
void _nop(stack_t **_data, unsigned int linecount)
{
	(void)_data;
	(void)linecount;
}

/**
 * _sub- subracts top stack elements
 * @_data: head of list
 * @linecount: count lines
 */
void _sub(stack_t **_data, unsigned int linecount)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *_data;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}
	tmp = (*_data)->next;
	tmp->n -= (*_data)->n;
	_pop(_data, linecount);
}
