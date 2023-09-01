#include "main.h"
#include <stdio.h>


/**
*set_bit - sets value of a bit to 1 at a given index
*@n: pointer
*@index: index of the bit
*
*
*Return: 1 if it worked, or -1 if an error occured.
*/

int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || (index > (sizeof(unsigned long int) * 8) - 1))
		return (-1);

	*n |= (1 << index);
	return (1);
}

