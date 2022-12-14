#include "monty.h"

int main(int ac, char **av)
{
	FILE *fp;
	char **op_args;
	int i;
	char *line;
	
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
	/* readline from file*/
	line = readline(fp);
	return (0);
}
