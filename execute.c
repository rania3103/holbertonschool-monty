#include "monty.h"
/**
 * execute_opcode - execute instruction
 * @opcode:instruction
 * @value: integer
*/
void execute_opcode(char *opcode, int value)
{
	int i;

	for(i = 0; instructions.opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(value);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s", i, opcode);
	exit(EXIT_FAILURE);
}
