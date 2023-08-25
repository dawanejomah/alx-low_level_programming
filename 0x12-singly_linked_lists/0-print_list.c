#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - function that prints all the elements of a list
 * @h: pointer to the list_t list to print
 *
 * Return: returns the number of nodes printed
 */
size_t print_list(const list_t *h)
{
	size_t n_nodes = 0;

	if (h == NULL)
	{
		return (0);
	}
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		n_nodes++;
	}
	return (n_nodes);
}
