#include "main.h"

/**
 * add_node_end - adds a new node at the end of a list_s list
 * @head: pointer to the address of the first node
 * @name: the value of the name field of the new node
 * @value: the value of the value field of the new node
 *
 * Return: head of the new list. Otherwise NULL
 */
list_t *add_node_end(list_t **head, const char *name, const char *value)
{
	list_t *trav, *new;

	if (head == NULL || name == NULL || value == NULL)
		return (NULL);

	trav = *head;

	/* create the new node */
	new = create_node(name, value);
	if (new == NULL)
		return (NULL);

	/* if the list has no elements */
	if (trav == NULL)
	{
		*head = new;
		return (*head);
	}

	/* traverse to the end of the list */
	while (trav->next != NULL)
		trav = trav->next;

	trav->next = new;

	return (*head);
}

/**
 * list_len - finds the number of elements in a linked list_t list
 * @h: pointer to a list_t
 *
 * Return: number of elements in the list_t
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}

/**
 * create_node - creates a new list_t node
 * @name: value of the name field
 * @value: value of the value field
 *
 * Return: address of new node. Otherwise NULL
 */
list_t *create_node(const char *name, const char *value)
{
	list_t *new;

	if (name == NULL || value == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->name = _strdup(name);
	new->value = _strdup(value);
	new->next = NULL;

	return (new);
}

/**
 * split_string - splits a given string using a given delimiter
 * @s: string to split
 * @delim: delimiter
 *
 * Return: list of strings
 */
list_t *split_string(char *s, char *delim)
{
	char *str, *next_str;
	list_t *strings = NULL;

	if (s == NULL || delim == NULL)
	{
		return (NULL);
	}

	str = _strdup(s);

	/* get first string */
	add_node_end(&strings, _strtok(str, delim), "");

	/* get all other strings */
	while ((next_str = _strtok(NULL, delim)))
		add_node_end(&strings, next_str, "");

	free(str);

	return (strings);
}

/**
 * free_node - frees a list_t node
 * @h: pointer to list_t node
 */
void free_node(list_t *h)
{
	if (h == NULL)
		return;

	if (h->name)
		free(h->name);

	if (h->value)
		free(h->value);

	free(h);
	h = NULL;
}
