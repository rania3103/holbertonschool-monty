#include "monty.h"
/**
 * is_int - check if the value is numeric.
 * @value: string.
 * Return:0 or 1
*/
int is_int (char *value)
{
	size_t i = 0;

	if (value == NULL)
	{
		return (0);
	}
	while (i < strlen(value))
	{
		if (!isdigit(value[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
