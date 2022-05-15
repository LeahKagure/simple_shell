#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints user input using getline
 *
 * Return: 0 if success -1 on Failure
 */

int main(void)
{
	char *buf;
	size_t size = 1024;

	buf = malloc(sizeof(char *) * size);

	printf("$ ");

	getline(&buf, &size, stdin);

	printf("%s", buf);

	free(buf);

	return (0);
}
