#include "monty.h"

/**
 * new_Node - creates new node
 * @n: is a value
 * Return: new node
 */
stack_t *new_Node(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

/**
 * _push - push item
 * @stack: is a parameter
 * @line_number: is value
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	int p_int;
	stack_t *new = NULL;

	is_valid(value, stack, line_number);
	p_int = atoi(bus.arg);

	(void)line_number;

	new = new_Node(p_int);
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int number)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
