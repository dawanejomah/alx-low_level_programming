#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
 * listint_len - returns the number of elements in listnt_t
 * @h: head of the list
 *
 * Return: number of elements in the list
 */

size_t listint_len(const listint_t *h)
{
	size_t numElement = 0;

	while (h != NULL)
	{
		numElement++;
		h = h->next;
	}

	return (numElement);
}

