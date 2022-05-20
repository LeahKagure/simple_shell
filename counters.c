#include "main.h"

/**
  * count_input - Counts the words typed by the user
  * @str: The string that contains the words
  *
  * Return: The number of words found in the string
  */
int count_input(char *str)
{
	int i = 0, cw = 0, state = 0;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			cw++;
		}

		i++;
	}

	return (cw);
}

/**
  * count_delims - Counts delimiters in a string
  * @str: The string that contains the delimiters
  * @del: The delimiters to will find in the string
  *
  * Return: The number of delimiters in the string
  */
int count_delims(char *str, char *del)
{
	int i = 0, j = 0, cw = 0;

	while (del[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == del[i])
				cw++;
			j++;
		}
		i++;
	}

	return (cw);
}
