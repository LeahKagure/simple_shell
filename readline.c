#include "shell.h"

/**
 *readline - gets the input the user inputs at the prompt
 *Return: a buffer for the storage of the string input
 */
char *readline(void)
{
	char *buffer = NULL;
	size_t n = 0;

	if (getline(&buffer, &n, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("Readline Error");
			exit(EXIT_FAILURE);
		}
	}
	return (buffer);
}
