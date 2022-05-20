#include "main.h"

/**
 * execBuiltInCommands - Executes a built-in command
 * @u_tokns: ...
 * @line: ...
 *
 * Return: 1 if is a built-in command or 0 if not
 */
int execBuiltInCommands(char **u_tokns, char *line)
{
	int i = 0;
	char *ListBuiltinCmds[] = { "exit", "cd", "help", "env", NULL };

	while (ListBuiltinCmds[i])
	{
		if (_strcmp(u_tokns[0], ListBuiltinCmds[i]) == 0)
		{
			switch (i)
			{
				case 0:
					_handle_exit(u_tokns, line);
				case 1:
					chdir(u_tokns[1]);
					return (1);
				case 2:
					_open_help();
					return (1);
				case 3:
					_print_env();
					return (1);
				default:
					break;
			}
		}
		i++;
	}

	return (0);
}
