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
/**
 * _div - the main function.
 * @head: int
 * @ln: int
 * Return: 0.
 */

void _div(stack_t **head, unsigned int ln)
{
	int x = 0;

	if (*head || (*head)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", ln);
		error = 1;
		return;
	}
	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", ln);
		error = 1;
		return;
	}
	x = (((*head)->next)->n) / ((*head)->n);
	_pop(head, ln);
	(*head)->n = x;
}
