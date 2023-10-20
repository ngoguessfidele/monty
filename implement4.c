#include "monty.h"

/**
 * _rotl- rotates
 * @_data: head of list
 * @linecount: line count
 */
void _rotl(stack_t **_data, unsigned int linecount)
{
	stack_t *tmp1 = NULL;
	stack_t *tmp2 = NULL;
	(void)linecount;

	if (*_data == NULL)
		return;
	if ((*_data)->next == NULL)
		return;

	tmp1 = (*_data)->next;
	tmp2 = *_data;

	for (; tmp2->next != NULL; tmp2 = tmp2->next)
		;

	tmp1->prev = NULL;
	tmp2->next = *_data;
	(*_data)->next = NULL;
	(*_data)->prev = tmp2;
	*_data = tmp1;
}

/**
 * _rotr- reverses the stack
 * @_data: head of list
 * @linecount: line counter
 */
void _rotr(stack_t **_data, unsigned int linecount)
{
	stack_t *tmp = NULL;
	(void)linecount;

	if (*_data == NULL)
		return;
	if ((*_data)->next == NULL)
		return;

	tmp = *_data;

	for (; tmp->next != NULL; tmp = tmp->next)
		;

	tmp->prev->next = NULL;
	tmp->next = *_data;
	tmp->prev = NULL;
	(*_data)->prev = tmp;
	*_data = tmp;
}
