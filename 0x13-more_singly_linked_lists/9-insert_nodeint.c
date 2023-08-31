#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a listint_t list
 * @head: Pointer to a pointer to the head of the list
 * @idx: The index at which the new node should be added (starting at 0)
 * @n: The integer value to be added to the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *newNode, *tmp = *head;
    unsigned int i;

    if (head == NULL)
        return (NULL); 

    newNode = malloc(sizeof(listint_t));
    if (newNode == NULL)
        return (NULL); 

    newNode->n = n;

    for (i = 0; i < idx - 1; i++)
    {
        if (tmp == NULL)
        {
            free(newNode);
            return (NULL);
        }

        tmp = tmp->next;
    }

    newNode->next = tmp->next;
    tmp->next = newNode;

    return (newNode);
}

