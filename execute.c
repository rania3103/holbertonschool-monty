#include "monty.h"
/**
 * execute_opcode - execute instruction
 * @stack:top of the stack.
 * @line_number: integer.
 * @opcode:instruction.
*/

void execute_opcode(stack_t **stack, unsigned int line_number, char *opcode)
{
	instruction_t instructions[] = {
	{"push", push},
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
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	free_stack(*stack);
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
