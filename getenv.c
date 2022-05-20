#include "main.h"

/**
  * _getenv - Gets an environment variable
  * @name: The variable to find in the system environment
  *
  * Return: The content of the environment variable
  */
char *_getenv(const char *name)
{
	int i = 0;
	char *env_var = NULL;

	while (environ[i])
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			env_var = _strdup(environ[i]);
			while (*env_var != '=')
				env_var++;

			++env_var;
			return (env_var);
		}
		i++;
	}

	return (NULL);
}
