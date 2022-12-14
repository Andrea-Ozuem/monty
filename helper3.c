#include "monty.h"

/**
 * is_valid - check if arg to push is valid
 * @arg: arg  value to check
 * @stack: pointer to a stack
 * @line_number: current line being executed
 */
void is_valid(char *arg, stack_t **stack, unsigned int line_number)
{
	int idx = 0;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
/*			free_stack(stack);*/
		handle_error(stack);
		exit(EXIT_FAILURE);
	}

	while (arg[idx])
	{
		if (arg[idx] == '-' && idx == 0)
			idx++;
		if (isdigit(arg[idx]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			handle_error(stack);
		}
		idx++;
	}
}

/**
  *free_stack - frees a dlist
  *@head: head of list
  */
void free_stack(stack_t *head)
{
	stack_t *tmp, *cur;

	if (head != NULL)
	{
		tmp = head;
		cur = tmp->next;
		while (cur)
		{
			free(tmp);
			tmp = cur;
			cur = cur->next;
		}
		free(tmp);
	}
}
