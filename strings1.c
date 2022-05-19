#include "main.h"

/**
 * _strtok - tokenizes a given string using a given delimiter
 * @str: string
 * @delim: delimiter
 *
 * Return: pointer to next token. Otherwise NULL
 */
char *_strtok(char *str, const char *delim)
{
	char c;
	int found_char = 0;
	char *start;
	static char *current;

	start = (str ? str : current);

	if (str)
		current = str;

	if (delim == NULL || *current == '\0')
		return (NULL);

	c = delim[0];

	while (*current == c) /* ignore separators at beginning */
	{
		start++;
		current++;
	}

	while (*current)
	{
		if (*current == c && found_char) /* found a delimiter */
		{
			*current = '\0';
			current++;
			break;
		}

		found_char = 1;
		current++;
	}

	while (*current && *current == c) /* ignore separators at end */
		current++;

	return (start);
}

/**
 * is_in_str - checks whether given character is in a given string
 * @str: string
 * @c: character
 *
 * Return: 1 if c is in str. 0 Otherwise
 */
int is_in_str(const char *str, char c)
{
	if (str == NULL)
		return (0);

	while (*str)
	{
		if (*str == c)
			return (1);

		str++;
	}

	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @str: string
 *
 * Return: integer equivalent. Otherwise -1
 */
int _atoi(char *str)
{
	int i, j, n, result;

	if (str == NULL)
		return (-1);

	n = _strlen(str);

	for (i = n - 1, j = 1, result = 0; i >= 0; i--, j *= 10)
	{
		if (result < 0 || str[i] > '9' || str[i] < '0')
			return (-1);

		result += (str[i] - '0') * j;
	}

	return (result % 256);
}

/**
 * str_rep - replaces all occurences of a character in a string with another
 * @str: string
 * @c1: character to replace
 * @c2: character to replace with
 */
void str_rep(char *str, char c1, char c2)
{
	while (*str)
	{
		if (*str == c1)
			*str = c2;

		str++;
	}
}
