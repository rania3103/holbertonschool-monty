#include "monty.h"
/**
 * push - pushes an  element to the stack;
 * @stack: top of the stack
 * @line_number:integer
 * @value: integer
*/
void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
