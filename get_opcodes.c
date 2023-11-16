#include "monty.h"

/**
 * get_instructs - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_instructs(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push_node},
		{"pall", print_all},
		{"pint", print_data},
		{"pop", pop_node},
		{"swap", swap_top},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", rotat_first},
		{"rotr", rev_stack},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp_(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
