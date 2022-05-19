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
	char *input, *full_name, *error_message[4];
	list_t *input_list;
	char **input_array;
	int built_ret, exec_ret;

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
		built_ret = get_built(input_list, shell_name, env_list);
		if (built_ret != -1)
		{
			free_input(input, input_list, NULL);
			if (built_ret < -1)
				continue;
			else
				return (built_ret);
		}
		error_message[1] = input_list->name;/* checkifisvalidcommand */
		full_name = get_full_name(input_list->name, env_list);
		if (full_name == NULL)
		{
			error_message[2] = "not found";
			print_error(error_message);
			free_input(input, input_list, NULL);
			continue;
		}
		input_array = list_to_array(input_list);/* changelisttoarray */
		if (input_array == NULL)
		{
			error_message[2] = "malloc failed";
			print_error(error_message);
			free(full_name);
			free_input(input, input_list, NULL);
			continue;
		}
		exec_ret = execute(input_array, full_name, shell_name);/* execute command */
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
