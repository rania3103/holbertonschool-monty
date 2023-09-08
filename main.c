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
		execute_opcode(tokens[0], atoi(tokens[1]));
		free(tokens);
	}
	free(line);
	fclose(file);
	return (0);
}
