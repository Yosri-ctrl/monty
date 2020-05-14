#include "monty.h"



/**
 * _push - the main function.
 * @head: int.
 * @ln: int.
 * @arg: int.
 * Return: 0.
 */
void _push(stack_t **head, unsigned int ln, char *arg)
{
	stack_t *nStack = NULL;

	int x = atoi(arg);

	(void)ln;
	free(arg);
	nStack = malloc(sizeof(stack_t));
	if (!nStack)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		error = 1;
		return;
	}
	nStack->n = x;
	if (*head)
	{
		(*head)->prev = nStack;
		nStack->next = *head;
		nStack->prev = NULL;
		*head = nStack;
	}
	else
	{
		nStack->prev = NULL;
		nStack->next = NULL;
		*head = nStack;
	}
}

/**
 * chArg - the main function.
 * @ln: int
 * Return: 0.
 */
char *chArg(unsigned int ln)
{
	char *tmp;
	char *arg;
	int i = 0, length = 0;

	tmp = strtok(NULL, " \n");
	while (tmp && tmp[0] == ' ')
		tmp = strtok(NULL, " \n");
	if (!tmp)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		error = 1;
		return (NULL);
	}
	while ((tmp[length] && tmp[length] != '\n' && tmp[length] != ' '))
		length++;
	arg = malloc(sizeof(char) * (length + 1));
	if (!arg)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		error = 1;
		return (NULL);
	}
	while (i < length)
	{
		arg[i] = tmp[i];
		i++;
	}
	arg[i] = '\0';

	if (is_digit(arg, ln) == 1)
		return (NULL);
	return (arg);
}


/**
 * is_digit - the main function.
 * @arg: int
 * @ln: int
 * Return: 0.
 */
int is_digit(char *arg, unsigned int ln)
{
	int i = 0;

	if (arg[i] != '-' && !(arg[i] <= 57 && arg[i] >= 48))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		error = 1;
		return (1);
	}
	else
		i++;
	while (arg[i] != '\0')
	{
		if (arg[i] <= 57 && arg[i] >= 48)
			i++;
		else
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
			error = 1;
			return (1);
		}
	}
	return (0);
}

/**
 * invalid - the main function.
 * @token: int
 * @ln: int
 * Return: 0.
 */
void invalid(char *token, unsigned int ln)
{
	int i = 0, length = 0;
	char *inv_op;

	while (token[length] != ' ' && token[length] != '\n' && token[length])
		length++;
	inv_op = malloc(sizeof(char) * (length));
	if (!inv_op)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		error = 1;
		return;
	}
	while (i < length)
	{
		inv_op[i] = token[i];
		i++;
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", ln, inv_op);
	free(inv_op);
	error = 1;
}

/**
 * get_fn - the main function.
 * @token: int
 * Return: 0.
 */
void (*get_fn(char *token))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t operation[] = {
		{"pall", _pall},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"pint", _pint},
		{"sub", _sub},
		{NULL, NULL}
	};
	if (token[0] == '#')
		return (_nop);
	while (operation[i].opcode)
	{
		if (
				!strncmp(token, operation[i].opcode, strlen(operation[i].opcode)) &&
				(token[strlen(operation[i].opcode)] == '\0')
		   )
			return (operation[i].f);
		i++;
	}
	return (NULL);
}
