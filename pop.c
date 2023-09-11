#include "monty.h"
/**
 * pop - Removes the topmost element from the stack
 * @stack: Pointer to the stack head
 * @line_number: The line number where the pop opcode was encountered
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** removing the head node */
	*stack = head->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(head);
}
