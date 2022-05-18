#include "main.h"

/**
 * shell - implement shell functionality
 * @env_list: list of environment variables
 * @shell_name: name of shell program
 *
 * Return: 0 success. Non-zero otherwise
 */
int shell(list_t *env_list, char *shell_name)
{
	char *input, *full_name;
	list_t *input_list;
	char **input_array;
	int built_ret, exec_ret;
	char *error_message[4];

	error_message_init(error_message, shell_name, NULL);

	while (1)
	{
		input = get_input();
		if (input == NULL)
			return (0);

		input_list = split_string(input, " "); /* check input */
		if (input_list == NULL || input[0] == '\n')
		{
			free(input);
			continue;
		}

		/* check if input is a built-in command */
		built_ret = get_built(input_list, shell_name, env_list);
		if (built_ret != -1)
		{
			free_input(input, input_list, NULL);
			if (built_ret < -1)
				continue;
			else
				return (built_ret);
		}

		/* check if 1st string is a valid command */
		error_message[1] = input_list->name;
		full_name = get_full_name(input_list->name, env_list);
		if (full_name == NULL)
		{
			error_message[2] = "not found";
			print_error(error_message);
			free_input(input, input_list, NULL);
			continue;
		}

		/* change input_list to input_array */
		input_array = list_to_array(input_list);
		if (input_array == NULL)
		{
			error_message[2] = "malloc failed";
			print_error(error_message);
			free(full_name);
			free_input(input, input_list, NULL);
			continue;
		}

		/* execute command */
		exec_ret = execute(input_array, full_name, shell_name);
		if (exec_ret < 0)
		{
			free_input(input, input_list, input_array);
			free(full_name);
			return (-exec_ret);
		}

		free(full_name);
		free_input(input, input_list, input_array);
	}

	return (0);
}

/**
 * get_input - gets input from the terminal
 *
 * Return: string input. Otherwise NULL
 */
char *get_input(void)
{
	char *buffer = NULL;
	size_t bufferSize = 0;

	if (isatty(STDIN_FILENO))
		prompt();

	if (getline(&buffer, &bufferSize, stdin) == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 2);

		free(buffer);
		return (NULL);
	}

	/* replace tabs with spaces */
	str_rep(buffer, '\t', ' ');
	
	return (_strlen(buffer) == 1 ? buffer : _strtok(buffer, "\n"));
}

/**
 * print_error - prints given error message to stderr
 * @error_message: array of strings composing error message
 */
void print_error(char **error_message)
{
	int i;
	char *str;

	for (i = 0; i < 4; i++)
	{
		str = error_message[i];

		if (str)
		{
			if (i > 0)
				write(STDERR_FILENO, ": ", 3);

			write(STDERR_FILENO, str, _strlen(str) + 1);

			if (i == 0)
				write(STDERR_FILENO, ": 1", 4);
		}
	}

	write(STDERR_FILENO, "\n", 2);
}

/**
 * prompt - displays shell prompt
 */
void prompt(void)
{
	char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, _strlen(prompt) + 1);
}

/**
 * free_input - frees given memory buffers
 * @input: string representing input
 * @input_list: list representing input
 * @input_array: array of strings representing input
 */
void free_input(char *input, list_t *input_list, char **input_array)
{
	if (input)
		free(input);

	if (input_list)
		free_list(input_list);

	if (input_array)
		free_array(input_array);
}

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

/** error_message_init - initialize error_message array with given values
 * @error_message: error message array
 * @shell_name: 1st value
 * @command: 2nd value
 */
void error_message_init(char **error_message, char *shell_name, char *command)
{
	error_message[0] = shell_name;
	error_message[1] = command;
	error_message[2] = NULL;
	error_message[3] = NULL;
}
