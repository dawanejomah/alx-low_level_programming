#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
 * free_listint_safe - frees a listint_t list.
 * @h: double pointer to the head of the list
 *
 * Return: the size of the list that was freed.
 */


size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp1, *tmp2;
	size_t count = 0;

	if (tmp == 0 || h == 0)
		return (0);

	tmp1 = *h;
	while (tmp1 != 0)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		count++;

		free(tmp2);

		if (tmp2 <= tmp1)
			break;
	}

	*h = 0;
	return (count);
}
