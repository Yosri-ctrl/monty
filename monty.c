#include "monty.h"

int error = 0;

/**
 * exitf - the main function.
 * @head: int
 * @file: int
 * @buff: int
 * Return: 0.
 */
void exitf(stack_t **head, char *buff, FILE *file)
{
	freeList(head, buff, file);
	exit(EXIT_FAILURE);
}
/**
 * freeList - the main function.
 * @head: int
 * @file: int
 * @buff: int
 * Return: 0.
 */
void freeList(stack_t **head, char *buff, FILE *file)
{
	if (*head)
	{
		while ((*head)->next)
		{
			(*head) = (*head)->next;
			free((*head)->prev);
		}
		free(*head);
	}
	fclose(file);
	free(buff);
}

/**
 * tokenizer - the main function.
 * @buff: int
 * Return: 0.
 */

char *tokenizer(char *buff)
{
	char *token = NULL;

	token = strtok(buff, " \n");
	while (token && token[0] == ' ')
		token = strtok(NULL, " \n");
	if (!token)
		return (NULL);
	return (token);
}
/**
 * split - the main function.
 * @head: int
 * @file: int
 * @buff: int
 * @ln: int
 * Return: 0.
 */
void split(stack_t **head, FILE *file, char *buff, unsigned int ln)
{
	char *arg;
	void (*f)(stack_t **head, unsigned int ln);
	char *token = NULL;

	token = tokenizer(buff);
	if (!token)
		return;
	if (!strncmp("push", token, 4) && (token[4] == '\0'))
	{
		arg = chArg(ln);
		if (arg != 0)
		{
			_push(head, ln, arg);
			if (error == 1)
			{
				exitf(head, buff, file);
			}
			return;
		}
		else
		{
			exitf(head, buff, file);
		}
	}
	f = get_fn(token);
	if (!f)
	{
		invalid(token, ln);
		if (error == 1)
		{
			exitf(head, buff, file);
		}
	}
	f(head, ln);
	if (error == 1)
	{
		freeList(head, buff, file);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - the main function.
 * @argc: int
 * @argv: int
 * Return: 0.
 */
int main(int argc, char **argv)
{
	size_t size = 0;
	stack_t *head = NULL;
	FILE *file;
	char *buff = NULL;
	int ln = 1;


	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; (getline(&buff, &size, file)) != -1; ln++)
		split(&head, file, buff, ln);
	freeList(&head, buff, file);
	exit(EXIT_SUCCESS);
}
