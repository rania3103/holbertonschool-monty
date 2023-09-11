#include "monty.h"
/**
 * execute_opcode - execute instruction
 * @stack:top of the stack.
 * @line_number: integer.
 * @opcode:instruction.
 * @value: integer.
*/

void execute_opcode(stack_t **stack, int line_number, char *opcode, int value)
{
	struct instruction_t instructions[] = {
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"pall", pall},
	{NULL, NULL}
	};

	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, "push") == 0)
		{
			push(stack, line_number, value);

		}
		else if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
