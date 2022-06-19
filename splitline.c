#include "shell.h"

#define BUFFSIZE 64

/**
 *splitline - splits the arguments int tokens
 *@str: the input from readline
 *Return: address of the broken down token buffer
 */
char **splitline(char *str)
{
	int postn = 0;
	int buffsize = BUFFSIZE;
	char delim[] = " \t\n";
	char **tokens = malloc(sizeof(char *) * buffsize);
	char *tkn;

	if (!tokens)
	{
		perror("Memory Allocation Error\n");
		return (NULL);
	}

	tkn = strtok(str, delim);

	while (tkn != NULL)
	{
		tokens[postn] = tkn;
		postn++;
		if (postn >= buffsize)
		{
			buffsize += BUFFSIZE;
			tokens = realloc(tokens, buffsize * sizeof(char *));
			if (!tokens)
			{
				perror("Memmory Not Allocated");
				return (NULL);
			}
		}
		tkn = strtok(NULL, delim);
	}
	tokens[postn] = NULL;

	return (tokens);
}
