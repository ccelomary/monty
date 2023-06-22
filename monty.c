
#include "monty.h"

/**
 * monty - function that interpret instructions
 * and execute them
 *
 * @file: file to read instructions from
 * @stack: stack to apply the instructions to
 */
void monty(FILE *file, stack_t **stack)
{
	char opcode[100], buffer[1000];
	unsigned int index, line;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", NULL}};

	line = 1;
	while (!feof(file))
	{
		memset(opcode, 0, sizeof(char) * 100);
		memset(buffer, 0, sizeof(char) * 1000);
		fscanf(file, "%s", opcode);
		if (!strcmp(opcode, "push"))
			fscanf(file, "%s\n", buffer);
		index = 0;
		while (index < OPTCODE_LENGTH)
		{
			if (!strcmp(instructions[index].opcode, opcode))
			{
				if (instructions[index].f)
					instructions[index].f(stack, line, buffer);
				break;
			}
			index++;
		}
		if (index >= OPTCODE_LENGTH)
		{
			fprintf(stderr, "L<%u>: unknown instruction <%s>\n", line, opcode);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		line++;
	}
}
