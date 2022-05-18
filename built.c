#include "main.h"

/**
 * get_built - checks if input is a built-in command and if so
 * executes its associated function
 * @input_list: list representing input command
 * @shell_name: name of shell program
 * @env_list: list of environment variables
 *
 * Return: integer, -1 if built-in does not exist
 */
int get_built(list_t *input_list, char *shell_name, list_t *env_list)
{
	char *name;
	int i;

	built_s built_ins[] = {
		{"exit", exit_shell},
		{"env", env_func},
		{"setenv", setenv_func},
		{"unsetenv", unsetenv_func},
		{NULL, NULL}
	};

	name = input_list->name;

	for (i = 0; built_ins[i].name; i++)
	{
		if (_strcmp(name, built_ins[i].name) == 0)
			return (built_ins[i].f(input_list, shell_name, &env_list));
	}

	return (-1);
}

/**
 * exit_shell - implements the exit built-in functionality
 * @input_list: list of command and arguments
 * @shell_name: name of shell program
 * @env_list_ptr: pointer to list of environment variables
 *
 * Return: exit code. Otherwise -2
 */
int exit_shell(list_t *input_list, char *shell_name, list_t **env_list_ptr)
{
	int num;
	char *error_message[4];

	error_message_init(error_message, shell_name, input_list->name);

	if (input_list->next == NULL)
		return (0);

	num = _atoi(input_list->next->name);

	if (num == -1)
	{
		error_message[2] = "Illegal number";
		error_message[3] = input_list->next->name;
		print_error(error_message);
		return (-2);
	}

	(void)env_list_ptr;
	return (num);
}

/**
 * env_func - implements the env built-in functionality
 * @input_list: list of command and arguments
 * @shell_name: name of shell program
 * @env_list_ptr: pointer list of environment variables
 *
 * Return: -2
 */
int env_func(list_t *input_list, char *shell_name, list_t **env_list_ptr)
{
	print_env(*env_list_ptr);

	(void)input_list;
	(void)shell_name;
	return (-2);
}

/**
 * setenv_func - implements the setenv built-in functionality
 * @input_list: list of command and arguments
 * @shell_name: name of shell program
 * @env_list_ptr: pointer list of environment variables
 *
 * Return: -2
 */
int setenv_func(list_t *input_list, char *shell_name, list_t **env_list_ptr)
{
	char *name, *value;
	char *error_message[4];

	error_message_init(error_message, shell_name, input_list->name);

	if (input_list->next == NULL || input_list->next->next == NULL)
	{
		error_message[2] = "invalid number of arguments";
		print_error(error_message);
		return (-2);
	}

	name = input_list->next->name;
	value = input_list->next->next->name;

	if (_setenv(*env_list_ptr, name, value, 1) == -1)
	{
		error_message[2] = "error";
		print_error(error_message);
	}

	return (-2);
}

/**
 * unsetenv_func - implements the unsetenv built-in functionality
 * @input_list: list of command and arguments
 * @shell_name: name of shell program
 * @env_list_ptr: pointer list of environment variables
 *
 * Return: -2
 */
int unsetenv_func(list_t *input_list, char *shell_name, list_t **env_list_ptr)
{
	char *name;
	char *error_message[4];

	error_message_init(error_message, shell_name, input_list->name);

	if (input_list->next == NULL)
	{
		error_message[2] = "invalid number of arguments";
		print_error(error_message);
		return (-2);
	}

	name = input_list->next->name;

	if (_unsetenv(*env_list_ptr, name) == -1)
	{
		error_message[2] = "error";
		print_error(error_message);
	}

	return (-2);
}
