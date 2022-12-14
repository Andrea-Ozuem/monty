#include "monty.h"
glob_t global = {NULL, NULL, NULL, 0};

/**
  *main - monty code
  *@ac: arg count
  *@av: monty file
  *Return: 0 on success
  */
int main(int ac, char **av)
{
	FILE *fp;
	stack_t *stack;
	char *line;
	size_t n = 0;
	unsigned int line_number = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	global.fp = fp;

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	/* readline from file*/
	while (getline(&line, &n, fp) != -1)
	{
		global.line = line;
		get_op(&stack, line_number, line, fp);
		line_number++;
	}
	fclose(fp);
/*free stack*/
	return (0);
}
