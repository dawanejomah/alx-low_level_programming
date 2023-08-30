#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t
 * @head: double pointer to the head of the list
 *
 *Return: empty
 */

int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);
	tmp = *head;
	*head = tmp->next;

	n = tmp->n;
	free(tmp);

	return (n);
}
