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
	FILE *file;
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

	execute_opcode(file, &stack);
	fclose(file);

	return (0);
}
