#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * free_list - frees memory of a list
 * @head: pointer to head of singly linked list
 * Return: No Return
 */
void free_list(list_t *head)
{
	list_t *t;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		t = head->next;
		free(head->str);
		free(head);
		head = t;
	}
}
