#include "monty.h"

int main(int ac, char **av)
{
	FILE *fp;
	char **op_args;
	int i;
	
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	
	op_args = readline(fp);
	for (i = 0; op_args[i]; i++)
		printf("args %i: %s\n", i, op_args[i]);
	return (0);
}
