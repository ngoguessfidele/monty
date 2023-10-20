#include "monty.h"

/**
 * _push- push implemantation
 * @_data: head of list
 * @linecount: line number
 * Return: nothing
 */
void _push(stack_t **_data, unsigned int linecount)
{
	int n, j;

	if (!data.arg)
	{
		dprintf(2, "L%u: ", linecount);
		dprintf(2, "usage: push integer\n");
		_free();
		exit(EXIT_FAILURE);
	}

	for (j = 0; data.arg[j] != '\0'; j++)
	{
		if (!isdigit(data.arg[j]) && data.arg[j] != '-')
		{
			dprintf(2, "L%u: ", linecount);
			dprintf(2, "usage: push integer\n");
			_free();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(data.arg);

	if (data.lifo == 1)
		add_dnodeint(_data, n);
	else
		add_dnodeint_end(_data, n);
}

/**
 * _pall- prints stack
 * @_data: head of list
 * @linecount: line number
 */
void _pall(stack_t **_data, unsigned int linecount)
{
	stack_t *tmp;
	(void)linecount;

	tmp = *_data;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint- prints top of stack
 * @_data: head of list
 * @linecount: line number
 */
void _pint(stack_t **_data, unsigned int linecount)
{
	(void)linecount;

	if (*_data == NULL)
	{
		dprintf(2, "L%u: ", linecount);
		dprintf(2, "can't pint, stack empty\n");
		_free();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*_data)->n);
}

/**
 * _pop- removes top of stack
 * @_data: head of list
 * @linecount: line number
 */
void _pop(stack_t **_data, unsigned int linecount)
{
	stack_t *tmp;

	if (_data == NULL || *_data == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}
	tmp = *_data;
	*_data = (*_data)->next;
	free(tmp);
}

/**
 * _swap- swaps top elements of stack
 * @_data: head of list
 * @linecount: line count
 */
void _swap(stack_t **_data, unsigned int linecount)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *_data;
	for (; tmp != NULL; tmp = tmp->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", linecount);
		_free();
		exit(EXIT_FAILURE);
	}

	tmp = *_data;
	*_data = (*_data)->next;
	tmp->next = (*_data)->next;
	tmp->prev = *_data;
	(*_data)->next = tmp;
	(*_data)->prev = NULL;
}
