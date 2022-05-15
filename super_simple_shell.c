#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

char *strip_newline(char *str);
char *prompt(void);
static void sig_handler(int sig);

char *input;
char *buf;

/**
 * prompt - a program that prints "cisfun$ ", wait for the user
 * to enter a command.
 * Return: string of user input OW -1 on fail
 */

char *prompt(void)
{
	size_t size = 10;
	static char *buf;

	/*allocate mem for buf*/
	buf = malloc(sizeof(char) * size);

	if (buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	printf("cisfun$ ");

	/*get input from user*/

	if (getline(&buf, &size, stdin) == -1)
	{
		free(buf);
		perror("Error:\n ");
		return (NULL);
	}
	/* remove newline and return*/
	return (strip_newline(buf));
}

/**
 * strip_newline - removes newline character from a new string
 * @str: string
 *
 * Return: string with newline character stripped
 */

char *strip_newline(char *str)
{
	int i;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
	return (str);
}

/**
 * sig_handler - signal to check interrupt
 * @sig: SIGINT
 */

static void sig_handler(int sig)
{
	free(input);
	exit(98);
	free(buf);
	(void)sig;
	write(STDOUT_FILENO, "\n", 2);
	exit(0);
}

/**
 * main - implementation of a super simple shell
 *
 * Return 0;
 */

int main(void)
{
	char *argv[2];
	int status, child_pid;

	argv[1] = NULL;

	if (signal(SIGINT, sig_handler) == SIG_ERR)
		exit(98);

	while (1)
	{
		/* get input*/
		input = prompt();
		if (input == NULL)
			return (1);

		argv[0] = input;

		/*create child process*/
		child_pid = fork();
		if (child_pid == -1)
		{
			free(input);
			perror("Error:\n");
			return (1);
		}
		else if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				free(input);
				perror("EXEC Error:\n ");
				return (1);
			}
		}
		wait(&status);
		free(input);
	}
	return (0);
}
