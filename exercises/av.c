#include <stdio.h>
/**
 * main - program that prints all the arguments
 * @ac: number of items in av
 * @av: null terminated array of strings
 *
 * Return: 0 success
 */

int main(int ac, char **av)
{
	int i;
	
	if (av == NULL)
		return (0);

	for (i = 0; av[i] != NULL ; i++)
	{
		printf("[%d] -> %s\n", i, av[i]);
	
	}
	return (0);
}
