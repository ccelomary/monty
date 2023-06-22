
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
	char buffer[1000], *opcode;
	unsigned int index, line;

	line = 1;
	while (!feof(file))
	{
		memset(buffer, 0, sizeof(char) * 1000);
		fscanf(file, "%[^\n]%*c", buffer);
		index = 0;
		opcode = strtok(buffer, " \t");
		while (index < OPTCODE_LENGTH)
		{
			if (!strcmp(instructions[index].opcode, opcode))
			{
				if (instructions[index].f)
					instructions[index].f(stack, line, strtok(NULL, " \t"));
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
