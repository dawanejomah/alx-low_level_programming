#include "lists.h"
/**
 * delete_nodeint_at_index - deletes the node at a given position in listint_t
 * @head: double pointer to the head of the list
 * @index: index of the node to be deleted
 *
 * Return: address memory node or NULL.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp = *head, *next;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = tmp->next;
		free(tmp);
		return (1);
	}

	for (i = 0; i < index - 1 && tmp; i++)
		tmp = tmp->next;

	if (tmp == NULL || tmp->next == NULL)
		return (-1);

	next = tmp->next->next;
	free(tmp->next);
	tmp->next = next;

	return (1);
}
