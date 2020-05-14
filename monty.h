#ifndef HEAD
#define HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

extern int error;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;

void _push(stack_t **stack, unsigned int ln, char *str);

char *chArg(unsigned int line_number);


void split(stack_t **head, FILE *fp, char *line, unsigned int ln);

void (*get_fn(char *token))(stack_t **, unsigned int);

void invalid(char *token, unsigned int ln);

int is_digit(char *arg, unsigned int ln);


void _pall(stack_t **head, unsigned int ln);
void _pop(stack_t **head, unsigned int ln);
void _swap(stack_t **head, unsigned int ln);
void _add(stack_t **head, unsigned int ln);
void _nop(stack_t **head, unsigned int ln);
void _pint(stack_t **head, unsigned int ln);
void _div(stack_t **head, unsigned int ln);

void freeList(stack_t **head, char *buff, FILE *file);

#endif
