
#include "monty.h"

/**
 * monty - function that interpret instructions
 * and execute them
 *
 * @file: file to read instructions from
 * @stack: stack to apply the instructions to
 * @instructions: array that contains all possible instruction and
 * it's correspondant functions
 */
void monty(FILE *file, stack_t **stack, instruction_t instructions[])
{
	char opcode[100], buffer[1000];
	unsigned int index, line;

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
