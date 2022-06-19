#include "shell.h"

/**
 *_strlen - gete the length of string
 *@str: the input
 *Return: length of string
 */
int _strlen(char *str)
{
	int len;

	if (!str)
		return (0);

	for (len = 0; str[len] != '\0'; len++)
		;

	return (len);
}

/**
 *_strcmp - compare two strings
 *@s1: 1st input
 *@s2: 2nd input
 *Return: 0 always success
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (_strlen(s1) != _strlen(s2))
		return (-1);

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 *_strtok - splits a line into tokens
 *@str: line to be split
 *@delim: the separator of tokens
 *Return: address of the tokens
 */
char *_strtok(char *str, char *delim)
{
	int i = 0, j = 0, a = 0;
	static char *tracker;

	if (!delim || (!str && !tracker))
		return (NULL);
	str == NULL ? str = tracker : str;
	for (; str[j] == ' ' ; j++)
	{
		if (str[j + 1] == '\0')
			return (NULL);
	}
	for (i = j ; str[i] != '\0' ; i++)
	{
		if (str[i] == *delim)
		{
			a = 1;
			break;
		}
	}
	for (; str[i] != '\0' ; i++)
		if (str[i] != delim[0])
			break;
		else if (str[i + 1] == '\0')
		{
			a = 0, str[i] = '\0';
			break;
		}
		else
			str[i] = '\0';
	if (a == 0)
	{
		tracker = NULL;
		return (str + j);
	}
	if (str + i)
		tracker = str + i;
	else
		tracker = NULL;
	return (str + j);
}
