#include "monty.h"
/**
 * tokenize_line - split line into tokens.
 * @line: read line from file.
 * Return:pointer to an array of ttokens
*/
char **tokenize_line(char *line)
{
	char **tokens = malloc(strlen(line) * sizeof(char *));
	int i = 0;

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	char *token = strtok(line, " \n\t");

	while (token !=  NULL)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " \n\t");
	}
	tokens[i] = NULL;
	return (tokens);
}
