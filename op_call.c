#include "monty.h"

/**
  *get_op - chooses which function to call per opcode
  *@stack: stack
  *@line_number: current line
  *@line: line current
  *Return: 0 as success
  */
int get_op(stack_t **stack, unsigned int line_number, char *line)
{
	instruction_t ops[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		/*{"nop", f_nop},
		{"sub", f_sub},*/
		{NULL, NULL}
	};
	char *op;
	int i = 0;

	op = strtok(line, " \t\n\r");
	if (op && op[0] == '#')
		return (0);

	globals.arg = strtok(NULL, " \t\n\r");
	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if ((op && ops[i].opcode == NULL) || (!ops[i].opcode))
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, op);
		handle_error(stack);
	}
	return (1);
}
