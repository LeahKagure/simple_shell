#include "main.h"

/**
 * delete_node_index - deletes the node at given name of a linked list
 * @head: pointer to the pointer of the 1st node in the list
 * @index: the index of the node that should be deleted
 *
 * Return: 0 is successful. Otherwise -1
 */
int delete_node_index(list_t **head, int index)
{
	list_t *current, *del;
	int i;

	/* if list does not exist or list is empty */
	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* if you are deleting the 1st node */
	if (index == 0)
	{
		*head = (*head)->next;
		free_node(current);
		return (0);
	}

	/* go to the node just before the node we are supposed to delete */
	for (i = 0; (i < index - 1) && current->next; i++)
		current = current->next;

	/* delete the node */
	if (current->next && i == index - 1)
	{
		del = current->next;
		current->next = current->next->next;
		free_node(del);
	}

	return (0);
}
