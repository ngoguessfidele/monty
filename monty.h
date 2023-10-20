#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s-  stack _data linked list
 * @n: an integer
 * @prev: previous node
 * @next: next node
 *
 * Description: stacks
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s- opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Descrption: opcode and handle functions
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globalvar- global data structure
 * @lifo: stack or queue
 * @counter: current line
 * @arg: second paramenter
 * @head: _data linked list
 * @fd: fd
 * @buffer: input
 *
 * Description: structure for stacks queues ..
 */
typedef struct globalvar
{
	int lifo;
	unsigned int counter;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t data;

/* implementations */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **_data, unsigned int linecount);
void _pop(stack_t **_data, unsigned int linecount);
void _swap(stack_t **_data, unsigned int linecount);
void _queue(stack_t **_data, unsigned int linecount);
void _stack(stack_t **_data, unsigned int linecount);
void _add(stack_t **_data, unsigned int linecount);
void _nop(stack_t **_data, unsigned int linecount);
void _sub(stack_t **_data, unsigned int linecount);
void _div(stack_t **_data, unsigned int linecount);
void _mul(stack_t **_data, unsigned int linecount);
void _mod(stack_t **_data, unsigned int linecount);
void _pchar(stack_t **_data, unsigned int linecount);
void _pstr(stack_t **_data, unsigned int linecount);
void _rotl(stack_t **_data, unsigned int linecount);
void _rotr(stack_t **_data, unsigned int linecount);

/* search for implementations */
void (*search(char *opc))(stack_t **stack, unsigned int line_number);

/* handlers */
int _sch(char *s, char c);
char *_strtok(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* handle linked lists */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void _free(void);

#endif
