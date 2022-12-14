#include "monty.h"

int get_op(stack_t **stack, unsigned int line_number, char *line, FILE *fp)
{
	instruction_t ops[] = {
		{"push", f_push},
		{"pall", f_pall},
		/*{"pint", f_pint},*/
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
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
		printf("%s\n", op);
		if (strcmp(op, ops[i].opcode) == 0)
		{
			printf("called\n");
			ops[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op == NULL && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, op);
		free(op);
		free(globals.arg);
		free(line);
		fclose(fp);
		/*free stack*/
		exit(EXIT_FAILURE);
	}
	return (1);
}
