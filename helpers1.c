#include "monty.h"

/**
 * f_push - push item
 * @stack: is a parameter
 * @number: is value
 */
void f_push(stack_t **stack, unsigned int number)
{
	stack_t *new = NULL;
	int p_int;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	is_valid(globals.arg, stack, number);
	p_int = atoi(globals.arg);

	(void) number;
	new->n = p_int;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	new->prev = NULL;
	*stack = new;
}

/**
 * f_pall - prints the stack
 * @stack: stack head
 * @number: no used
 * Return: no return
*/
void f_pall(stack_t **stack, unsigned int number)
{
	stack_t *h;
	(void) number;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
  *f_pint - prints topmost stack
  *@stack: stack
  *@line_number: line num
  */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		handle_error(stack);
	}
	printf("%d\n", (*stack)->n);
}
