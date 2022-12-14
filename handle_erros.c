#include "monty.h"

/**
  *handle_error - handles error
  *@stack: stack head
  */
void handle_error(stack_t **stack)
{
	free(globals.line);
	fclose(globals.fp);
	if (*stack)
		free_stack(*stack);
	exit(EXIT_FAILURE);
}
