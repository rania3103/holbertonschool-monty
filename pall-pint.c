#include "monty.h"
/**
 * pall - prints all the values on the stack
 * @stack: the top of the stack
 * @line_number: line number
*/
void pall(stack_t **stack, int line_number)
{
	stack_t *node = *stack;

	while(node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
/**
 * pint -  prints the value at the top of the stack
 * @stack: the top of the stack
 * @line_number: line number
*/
void pint(stack_t **stack, int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	ptintf("%d\n", tmp->n);
}
