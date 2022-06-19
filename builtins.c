#include "shell.h"

/**
 *builtins - contains the commands to be executed
 *Return: 0 always Success
 */
int builtins(void)
{
	char *b_str[] = {"cd", "exit"};

	return (sizeof(b_str) / sizeof(char *));
}

/**
 *c_d - changes the directories
 *@arg: the input tokens
 *Return: 0 always success
 */
int c_d(char **arg)
{
	if (arg[1] == NULL)
	{
		perror("Missing Arguments\n");
	}
	else
	{
		if (chdir(arg[1]) != 0)
			perror("Error");
	}
	return (1);
}

/**
 *ex_it - exits with status from program
 *@arg: the input token
 *Return: 0 aways success
 */
int ex_it(__attribute__((unused))char **arg)
{
	return (0);
}
