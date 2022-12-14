#include "monty.h"

void monty(char *line, int line_no)
{
	instruction_t ops = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{NULL, NULL}
	};
	char *token, push_arg;
	int i;

	token = strdup(strtok(line, " \t\r\n"));
	
	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(token, ops[i].opcode))
		{
			ops[i].f();
			/* handle errors in running*/
		}
	}
	printf("L%i: unknown instruction %s\n", line_no, token);
	exit(EXIT_FAILURE);
}

void readline(FILE *fp)
{
	char *line = NULL;
	size_t n = 0;
	int line_no = 1;

	while (getline(&line, &n, fp) != -1)
	{
		monty(line, line_no)
		i++;
	}
}
