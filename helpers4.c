#include "monty.h"
/**
 * f_div - divides the top two elements of the stack.
 * @stack: stack head
 * @number: line_number
 * Return: no return
 */
void f_div(stack_t **stack, unsigned int number)
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
	fprintf(stderr, "L%d: can't div, stack too short\n", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->next->n / h->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}

/**
 * f_mul - multiplies the top two elements of the stack.
 * @stack: stack head
 * @number: line_number
 * Return: no return
 */
void f_mul(stack_t **stack, unsigned int number)
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
	fprintf(stderr, "L%d: can't mul, stack too short\n", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->next->n * h->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}

/**
 * f_mod - returns the modulo of the top two elements of the stack.
 * @stack: stack head
 * @number: line_number
 * Return: no return
 */
void f_mod(stack_t **stack, unsigned int number)
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
	fprintf(stderr, "L%d: can't mod, stack too short\n", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	if (h->n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->next->n % h->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}
