#include "monty.h"

/**
 * is_valid - check if second spot of a token array is valid
 * @token: tokens value to check
 * @stack: pointer to a stack
 */
void is_valid(char *arg, stack_t **stack, unsigned int line_number)
{
	int idx = 0;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		if (*stack)
			free(*stack);
/*			free_stack(stack);*/
		free(arg);
		exit(EXIT_FAILURE);
	}

	while (arg[idx])
	{
		if (arg[idx] == '-' && idx == 0)
			idx++;
		if (isdigit(arg[idx]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			if (*stack)
				free(*stack);

/*			replace above with this later	free_stack(stack);*/
			free(arg);
			exit(EXIT_FAILURE);
		}
		idx++;
	}
}
