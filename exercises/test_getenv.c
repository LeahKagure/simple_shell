#include <stdio.h>
#include "which.h"

/**
 * main - test
 *
 * Return: always 0
 */

int main(void)
{
	char *name = "PATH";

	printf("%s: %s\n", name, _getenv(name));

	return (0);
}
