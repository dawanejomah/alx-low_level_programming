#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_nodeint_at_index: returns the nth node of listint_t
 * @head: double pointer to the head of the list
 * @index: index of the node to return
 *
 * Return: pointer to the nth node of listint_t
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *tmp = head; 

	while (tmp != NULL)
	{
		if (count == index)
			return (tmp);

		tmp = tmp->next;
		count++;
	}

	return (NULL);
}
