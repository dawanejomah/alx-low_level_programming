#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
*free_listint - frees listint_t
*@head: head of listint_t
*
*/

void free_listint(listint_t *head)
{

	listint_t *tmpPtr;

	while (head != NULL)
{
	tmpPtr = head;
	head = head->next;
	free(tmpPtr);
}
}
