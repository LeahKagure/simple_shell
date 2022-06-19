#include "shell.h"

/**
 * main - prints a string on display
 * Return: 0 always success
 */
int _print(void)
{
	write(1, "Hello World\n", 12);
	return (0);
}
