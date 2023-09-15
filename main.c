#include "monty.h"
/**
 * main - entry point
 * Description: monty program
 * @argc:argument count
 * @argv:argument vector
 * Return: 0
*/
char *value = NULL;
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	int r = 0, nline = 1;
	size_t len;
	char *opcode;
	char *line;

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

	while ((r = getline(&line, &len, file)) != -1)
	{
		opcode = strtok(line, " \n\t");
		if (strcmp(opcode, "push") == 0)
		{
			value = strtok(NULL, " \n\t");
			if (is_int(value) == 0)
			{
				free_stack(stack);
				fprintf(stderr, "L%d: usage: push integer\n", nline);
				exit(EXIT_FAILURE);
			}
		}
		execute_opcode(&stack, nline, opcode);
		nline++;
	}
	free(line);
	free_stack(stack);
	fclose(file);
	return (0);
}
