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
	char buffer[1024];
	int len = 0, r;
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
		if (isdigit(tokens[1]))
		{
			value = atoi(tokens[1]);
			execute_opcode(&stack, nline, tokens[0], value);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", nline);
			exit(EXIT_FAILURE);
		}
		nline++;
		free(tokens);
	}
	free(line);
	fclose(file);
	return (0);
}
