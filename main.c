#include "monty.h"
/**
 * main - entry point
 * Description: monty program
 * @argc:argument count
 * @argv:argument vector
 * Return: 0
*/
int main(int argc, char *argv[])
{
	size_t len = 0;
	int r;
	char *line = NULL;
	char **tokens;
	FILE *file;
	int value;
	int nline = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	r = getline(&line, &len, file);
	while (r > 0)
	{
		tokens = tokenize_line(line);
		if (tokens[0])
		{
			if (isdigit(tokens[1]))
			{
				value = atoi(tokens[1]);
				execute_opcode(&stack, nline, tokens[0], value);
			}
			else
			{
				execute_opcode(&stack, nline, tokens[0], 0);
			}	
			nline++;
			free(tokens);
		}
		 r = getline(&line, &len, file);	
	}

	free(line);
	fclose(file);
	return (0);
}
