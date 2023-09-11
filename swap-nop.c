#include "monty.h"
/**
 * swap -  swaps the top two elements of the stack.
 * @stack: the top of the stack
 * @line_number: line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!(stack) || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
/**
 * nop - doesn’t do anything..
 * @stack: the top of the stack
 * @line_number: line number
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
