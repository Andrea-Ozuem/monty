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
	/* readline from file*/
	op_args = readline(fp);	
	for (i = 0; op_args[i]; i++)
		printf("args %i: %s\n", i, op_args[i]);
	return (0);
}

char **readline(FILE *fp)
{
	int buf = 15;
	char *line = NULL;
	char *token;
	size_t n = 0;
	int i, total;
	char **tokens = malloc(sizeof(char *) * buf);

	total = 0;
	while (getline(&line, &n, fp) != -1)
	{
		if (total >= buf)
			tokens = realloc(tokens, sizeof(char *) * (buf + buf));
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

void f_push(stack_t **head, unsigned int number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
/**	if (new == NULL)
		return (NULL);*/
	new->n = number;
	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
		new->prev = NULL;
		*head = new;
	}
}
