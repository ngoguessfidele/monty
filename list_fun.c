#include "monty.h"

/**
 * add_dnodeint_end- add node at the end
 * @head: head of list
 * @n: data
 * Return: pointer to added node
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *tmp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		_free();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	temp->next = tmp->next;
	temp->prev = tmp;
	tmp->next = temp;
	return (tmp->next);
}

/**
 * add_dnodeint- add node at index
 * @head: head of list
 * @n: data
 * Return: _data linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		_free();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_dlistint- frees the list
 * @head: head of the list
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
