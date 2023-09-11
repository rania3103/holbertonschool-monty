#include "monty.h"
/**
 * get_opcode - gets the operation
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * @opcode: the operation
 * Return: 0 (on success) or -1
*/

int get_opcode(stack_t **stack, unsigned int line_number, char *opcode)
{
	instruction_t instruction[] = {
	{"push", push},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	// {"add", add},
	{"nop", nop},
	{"pall", pall},
	{NULL, NULL}
	};

	int i;

	for (i = 0; instruction[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instruction[i].opcode) == 0)
		{
			instruction[i].f(stack, line_number);
			return (0);
		}
	}
	return (-1);
}


/**
 * execute_opcode - executes monty instruction
 * @stack: the stack
 * @file: the file to be used
*/
void execute_opcode(FILE *file, stack_t **stack)
{
	int r, nline = 1;
	size_t len = 0;
	char *line = NULL, *token = NULL;

	r = getline(&line, &len, file);
	while (r > 0)
	{
		token = strtok(line, " \n\t\r");
		nline++;

		if (token == NULL)
			continue;

		if (get_opcode(stack, nline, token) == -1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", nline, token);
			free(line);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
}
/**	{
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
		else
			continue;

		 r = getline(&line, &len, file);	
	}*/
