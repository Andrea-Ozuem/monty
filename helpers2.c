#include "monty.h"
/**
 * f_pop - prints the top
 * @stack: stack head
 * @number: line_number
 * Return: no return
 */
void f_pop(stack_t **stack, unsigned int number)
{
	stack_t *h;

	h = *stack;

	if (h == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	*stack = h->next;
	free(h);
}

/**
 * f_swap - swaps the top two elements of the stack.
 * @stack: stack head
 * @number: line_number
 * Return: no return
 */
void f_swap(stack_t **stack, unsigned int number)
{
	stack_t *h;
	int len = 0, temp;

	h = *stack;
	while (h)
	{
	h = h->next;
	len++;
	}
	if (len < 2)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}


/**
 * f_add - adds the top two elements of the stack.
 * @stack: stack head
 * @number: line_number
 * Return: no return
 */
void f_add(stack_t **stack, unsigned int number)
{
	stack_t *h;
	int len = 0, temp;

	h = *stack;
	while (h)
	{
	h = h->next;
	len++;
	}
	if (len < 2)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}

/**
 * f_nop - function that does nothing
 * @stack: double head pointer to the stack
 * @number: line count
 *
 * Return: nothing
 */
void f_nop(stack_t **stack, unsigned int number)
{
	(void) number;
	(void) stack;
}


/**
 * f_sub - subtracts the top two elements of the stack.
 * @stack: stack head
 * @number: line_number
 * Return: no return
 */
void f_sub(stack_t **stack, unsigned int number)
{
	stack_t *h;
	int len = 0, temp;

	h = *stack;
	while (h)
	{
	h = h->next;
	len++;
	}
	if (len < 2)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->next->n - h->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}
