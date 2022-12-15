#include "monty.h"
/**
 * f_pop - prints the top
 * @head: stack head
 * @number: line_number
 * Return: no return
 */
void f_pop(stack_t **head, unsigned int number)
{
	stack_t *h;

	h = *head;

	if (h == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	*head = h->next;
	free(h);
}

/**
 * f_swap - swaps the top two elements of the stack.
 * @head: stack head
 * @number: line_number
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int number)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
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
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}


/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @number: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int number)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
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
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
 * f_nop - function that does nothing
 * @head: double head pointer to the stack
 * @number: line count
 *
 * Return: nothing
 */
void f_nop(stack_t **head, unsigned int number)
{
	(void) number;
	(void) head;
}


/**
 * f_sub - subtracts the top two elements of the stack.
 * @head: stack head
 * @number: line_number
 * Return: no return
 */
void f_sub(stack_t **head, unsigned int number)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
	h = h->next;
	len++;
	}
	if (len < 2)
	{
	fprintf(stderr, "L<line_number>: can't sub, stack too short", number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->next->n - h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
