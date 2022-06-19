#include "shell.h"

/**
 *execute - calls the builtins to action
 *@arg: the input argument from cli prompt
 *Return: exec status(overiding main process for success)
 */
int execute(char **arg)
{
	int i;
	char *b_str[] = {"cd", "exit"};

	int (*b_func[])(char **) = {&c_d, &ex_it};

	if (arg[0] == NULL)
		return (1);
	for (i = 0; i < builtins(); i++)
	{
		if (_strcmp(arg[0], b_str[i]) == 0)
		{
			return ((*b_func[i])(arg));
		}
	}
	return (launch(arg));
}
