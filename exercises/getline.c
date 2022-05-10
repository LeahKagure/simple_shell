#include <stdio.h>
#include <stdlib.h>

#define LSH_RL_BUFSIZE 1024
/**
 * lsh_read_line - function that reads line from user
 * Return: Exit Success
 */
char *lsh_read_line(void)
{
	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* Read a character*/
		c = getchar();
		/* If we hit EOF, replace it with a null character and return.*/
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
			position++;
		}
		/* If we have exceeded the buffer, reallocate.*/
		if (position >= bufsize)
		{
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * lsh_loop - function that loops interprating commands
 */
void lsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = lsh_read_line();
		/*args = lsh_split_line(line);*/
		/*status = lsh_execute(args);*/

		free(line);
		/*free(args);*/
	} while (status);
}

/**
 * main - main function to run shell
 * @argc: count of arguments
 * @argv: array of strings
 * Return: exit success
 */

int main(int argc, char **argv)
{
	/* Load config files, if any.*/
	/* Run command loop.*/
	lsh_loop();
	/* Perform any shutdown/cleanup.*/
	return (EXIT_SUCCESS);
}
