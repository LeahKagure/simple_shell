#include "main.h"

/**
 * free_list - frees a list_t list
 * @h: list_t head
 * Return: 0 (Success)
 */
void free_list(list_t *h)
{
	list_t *current;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		current = h;
		h = h->next;
		free_node(current);
	}

}

/**
 * list_to_array - converts a given list of strings into an array of strings
 * @h: head of given list
 *
 * Return: an array of strings. Otherwise NULL
 */
char **list_to_array(const list_t *h)
{
	char **array;
	unsigned int i, length;

	if (h == NULL)
		return (NULL);

	/* allocate space for array */
	length = list_len(h);
	array = malloc(sizeof(char *) * (length + 1));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < length && h; i++, h = h->next)
		array[i] = _strdup(h->name);

	array[length] = NULL;

	return (array);
}

/**
  * free_array - frees an array of strings
  * @arr: array
  */
void free_array(char **arr)
{
	unsigned int i;

	for (i = 0; arr && arr[i]; i++)
		free(arr[i]);

	if (arr)
	{
		free(arr);
	}

	arr = NULL;
}

/**
 * find_name - finds the index of a node with the given name in a list_t
 * @h: head of list_t
 * @name: name of node
 *
 * Return: index of node if found. Otherwise -1
 */
int find_name(list_t *h, const char *name)
{
	list_t *trav = h;
	int index = 0;

	if (h == NULL || name == NULL)
		return (-1);

	/* find matching node */
	while (trav && (_strcmp(trav->name, name)))
	{
		index++;
		trav = trav->next;
	}

	return (trav ? index : -1);
}

/**
 * update_value - updates value field list_t node at given index
 * @h: head of list_t
 * @index: index of node to update
 * @value: new value
 *
 * Return: 0 success. -1 Otherwise
 */
int update_value(list_t *h, int index, const char *value)
{
	list_t *trav = h;

	if (h == NULL || index < 0 || value == NULL)
		return (-1);

	/* find node to update */
	while (index && trav)
	{
		index--;
		trav = trav->next;
	}

	/* update node */
	if (trav)
	{
		free(trav->value);
		trav->value = _strdup(value);
		/*printf("UPDATE SUCCESSFUL!!!!\n");*/
		return (0);
	}

	return (-1);
}
