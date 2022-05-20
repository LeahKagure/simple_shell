#include <stdio.h>
#include <string.h>

/**
 * main - a function that splits a string and returns an array
 * of each word of the string.
 *
 * Return: array of each word of the string
 */

int main(void)
{
	char str[] = "Welcome to my hood";
	const char s[2] = " ";
	char *token;

	/*Get the first token*/
	token = strtok(str, s);

	/*Walk through the next tokens*/
	while (token != NULL)
	{
		printf("%s\n", token);

		token = strtok(NULL, s);
	}

	return (0);
}
