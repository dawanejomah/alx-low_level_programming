#include <stdio.h>
#include <stdlib.h>

/**
 * get_bit - returns the value of a bit at a given index
 * @n: int to get the bit from
 * @index: index of the bit stsrting from 0
 *
 *
 * Return: the value of a bit at index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);
	if (n != 0)
		return ((n & (1 << index)) >> index);
	else
		return (-1);
}

