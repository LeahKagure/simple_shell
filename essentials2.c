#include "main.h"

/**
  * _strcat - Concatenates two strings
  * @dest: The destination string
  * @src: The source string
  *
  * Return: A pointer to the resulting string dest
  */
char *_strcat(char *dest, char *src)
{
	int dlen = 0, i = 0;

	while (dest[dlen])
		dlen++;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}

	dest[dlen] = '\0';
	return (dest);
}

/**
  * _strlen - Counts the length of a string
  * @s: The string to counts
  *
  * Return: The length of a string
  */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
  * _strcmp - Compares two strings
  * @s1: The first string
  * @s2: The second string
  *
  * Return: int value
  */
int _strcmp(char *s1, char *s2)
{
	int len_s1 = 0, len_s2 = 0, pos = 0, diff = 0, lim = 0;

	len_s1 = _strlen(s1);
	len_s2 = _strlen(s2);

	if (len_s1 <= len_s2)
		lim = len_s1;
	else
		lim = len_s2;

	while (pos <= lim)
	{
		if (s1[pos] == s2[pos])
		{
			pos++;
			continue;
		}
		else
		{
			diff = s1[pos] - s2[pos];
			break;
		}

		pos++;
	}

	return (diff);
}

/**
  * _strdup - Duplicate a string
  * @str: the string to duplicate
  *
  * Return: the string duplicated
  */
char *_strdup(char *str)
{
	int idx = 0, len = 1;
	char *dup_str;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup_str = malloc((sizeof(char) * len) + 1);
	if (dup_str == NULL)
		return (NULL);

	while (idx < len)
	{
		dup_str[idx] = str[idx];
		idx++;
	}

	dup_str[idx] = '\0';
	return (dup_str);
}

/**
  * _atoi - Convert a string to an integer.
  * @s: The pointer to convert
  *
  * Return: A integer
  */
int _atoi(char *s)
{
	int min = 1, isi = 0, pos = 0;
	unsigned int ni = 0;

	while (s[pos])
	{
		if (s[pos] == '-')
			min *= -1;

		while (s[pos] >= '0' && s[pos] <= '9')
		{
			isi = 1;
			ni = (ni * 10) + (s[pos] - '0');
			pos++;
		}

		if (isi == 1)
			break;

		pos++;
	}

	ni *= min;
	return (ni);
}
