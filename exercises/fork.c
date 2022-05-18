#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/**
 * main - fork example
 *
 * Return: Always 0
 */

int main(void)
{
pid_t my_pid;
pid_t cpid;

printf("Before fork\n");

my_pid = getpid();

printf("pid: %u\n", my_pid);
cpid = fork();

if (cpid == -1)
{
perror("Error!");
return (1);
}
printf("After fork\n");
my_pid = getpid();

printf("child pid is %u\n", cpid);

printf("My pid is %u\n", my_pid);
return (0);
}
