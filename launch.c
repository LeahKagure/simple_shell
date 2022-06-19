#include "shell.h"

/**
 *launch - launches a child process
 *@args: the input
 *Return: id of the child process
 */
int launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Execution Failed\n");
			return (-1);
		}
	}
	else if (pid < 0)
	{
		perror("Child Process Not Created\n");
		return (-1);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (wpid);
}
