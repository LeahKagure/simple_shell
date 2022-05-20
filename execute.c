#include "main.h"

/**
 * execute - executes a given input command
 * @input_array: array of strings containing input command
 * @command: name of command to execute
 * @shell_name: name of shell program
 *
 * Return: 0 success. Otherwise negative integer
 */
int execute(char **input_array, char *command, char *shell_name)
{
	pid_t child_pid;
	int status;
	char *error_message[4];

	error_message_init(error_message, shell_name, command);

	child_pid = fork();
	if (child_pid == -1)
	{
		error_message[2] = "fork error";
		print_error(error_message);
		return (-1);
	}
	else if (child_pid == 0) /* execute command */
	{
		if (execve(command, input_array, NULL) == -1)
		{
			error_message[2] = "execve error";
			print_error(error_message);
			return (-2);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}
