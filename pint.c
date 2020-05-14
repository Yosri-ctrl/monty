#include "monty.h"

/**
 * _pint - the main function.
 * @head: int
 * @ln: int
 * Return: 0.
 */
void _pint(stack_t **head, unsigned int ln)
{
	if (!head || !*head)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", ln);
		error = 1;
		return;
	}
	printf("%d\n", (*head)->n);
}
