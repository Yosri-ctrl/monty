#include "monty.h"

/**
 * _nop - the main function.
 * @head: int
 * @ln: int
 * Return: 0.
 */
void _nop(stack_t **head, unsigned int ln)
{
	(void)head;
	(void)ln;
}

/**
 * _add - the main function.
 * @head: int
 * @ln: int
 * Return: 0.
 */
void _add(stack_t **head, unsigned int ln)
{
	int x = 0;
	
	if (!(*head)->next || !*head)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", ln);
		error = 1;
		return;
	}

	x = ((*head)->n) + (((*head)->next)->n);
	_pop(head, ln);
	(*head)->n = x;
}

/**
 * _pall - the main function.
 * @head: int
 * @ln: int
 * Return: 0.
 */
void _pall(stack_t **head, unsigned int ln)
{
	stack_t *h = *head;

	(void)ln;
	if (!*head)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _pop - the main function.
 * @head: int
 * @ln: int
 * Return: 0.
 */
void _pop(stack_t **head, unsigned int ln)
{
	stack_t *tmp = NULL;

	if (!*head)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", ln);
		error = 1;
		return;
	}

	if (!(*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		tmp = *head;
		((*head)->next)->prev = NULL;
		(*head) = (*head)->next;
		free(tmp);
	}
}

/**
 * _swap - the main function.
 * @head: int
 * @ln: int
 * Return: 0.
 */
void _swap(stack_t **head, unsigned int ln)
{
	int x;

	if (!*head || !(*head)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", ln);
		error = 1;
		return;
	}

	x = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = x;
}
