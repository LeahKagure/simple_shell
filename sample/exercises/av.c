#include <stdio.h>
/**
 * main - prints all arguments without using argc
 * @argc: number of arguments in argv
 * @argv: array of strings (arguments)
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
int count;

printf("This program was called with \"%s\".\n", argv[0]);

if (argc > 1)
{
for (count = 1; count < argc; count++)
{
printf("argv[%d] = %s\n", count, argv[count]);
}
}
else
{
printf("The command had no other arguments.\n");
}

return (0);
}
