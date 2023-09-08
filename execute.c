#include "monty.h"
/**
 * execute_opcode - execute instruction
 * @opcode:instruction
 * @value: integer
*/
void execute_opcode(char *opcode, int value)
{
	struct instruction_t instrcutions[]={
	{"push", push},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"pall", pall},
	{"NULL", NULL}
	};

	int i;

	for(i = 0; instructions.opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(&stack, &line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s", i, opcode);
	exit(EXIT_FAILURE);
}
