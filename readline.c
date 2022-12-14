#include "monty.h"

#define BUF 15
char **readline(FILE *fp)
{
	char *line = NULL;
	char *token;
	size_t n = 0;
	int i, total;
	char **tokens = malloc(sizeof(char *) * BUF);

	total = 0;
	while (getline(&line, &n, fp) != -1)
	{
		if (total >= BUF)
			tokens = realloc(tokens, sizeof(char *) * (BUF + BUF)); 
		token = strtok(line, " \t\r\n");
		for (i = 0; token && i < 2; i++)
		{
			tokens[total] = strdup(token);
			token = strtok(NULL, " \t\r\n");
			total++;
		}
	}
	return (tokens);
}
