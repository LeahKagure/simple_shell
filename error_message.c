#include "main.h"

/**
 * error_message_init - initialize error_message array with given values
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
