#include "shell.h"

/*THIS IS TASK 1 SIMPLE SHELL PROJECT*/
/**
 * main - gets the prompt going
 * Return: 0 for success
 */
int main(void)
{
	char **token;
	char *line;
	int status;

	while (status)
	{
		write(1, "$", 1);
		line = readline();
		token = splitline(line);
		status = execute(token);
		free(line);
		free(token);
		/*write (1, buffer, _strlen(buffer));*/
	}
	return (0);
}
