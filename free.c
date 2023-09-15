#include "monty.h"
/**
 * free_stack - frees a stack
 * @stack: the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *tmp = stack;

	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
}
