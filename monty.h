#ifndef MONTY_H
#define MONTY_H

#define OPTCODE_LENGTH 11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number,
			  const char *s __attribute__((__unused__)));
} instruction_t;

void free_stack(stack_t **);
stack_t *push_stack(stack_t **, int);
stack_t *pop_stack(stack_t **);
void print_stack(const stack_t *, int);
int stack_length(const stack_t *);
/* utils */
int _isdigit(const char *);

/* instructions */
void push(stack_t **, unsigned int, __attribute__((__unused__)) const char *);
void pall(stack_t **, unsigned int line_number, __attribute__((__unused__)) const char *);
void pint(stack_t **, unsigned int line_number, __attribute__((__unused__)) const char *);
void pop(stack_t **, unsigned int line_number, __attribute__((__unused__)) const char *);
void swap(stack_t **, unsigned int line_number, __attribute__((__unused__)) const char *);
void add(stack_t **, unsigned int line_number, __attribute__((__unused__)) const char *);
void sub(stack_t **, unsigned int line_number, __attribute__((__unused__)) const char *);
void _div(stack_t **, unsigned int line_number, __attribute__((__unused__)) const char *);
void mul(stack_t **, unsigned int line_number, __attribute__((__unused__)) const char *);
void mod(stack_t **, unsigned int line_number, __attribute__((__unused__)) const char *);

/* monty */
void monty(FILE *file, stack_t **stack, instruction_t instructions[]);
#endif
