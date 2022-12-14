#include "monty.h"

int get_op(stack_t **stack, unsigned int line_number, char *line)
{
	instruction_t ops[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{NULL, NULL}
	};
	char *op;
	int i;

	op = strdup(strtok(line, " \t\n\r"));
	if (op && op[0] == '#')
		return (0);
	
	global.arg = strdup(strtok(NULL, " \t\n\r"));
	while (ops[i++].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			if(ops[i].f)
			{
				ops[i].f(stack, line_number);
				return (0);
			}
		}
	}
	if (op == NULL || ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, op);
		free(op);
		free(arg);
		free(line);
		/*free stack*/
		exit(EXIT_FAILURE);
	}
	return (1);
}
