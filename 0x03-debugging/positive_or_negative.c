#include "main.h"

void positive_or_negative(int i);
/**
 * main - Prints a random number and states whether
 *        it is positive, negative, or zero.
 *
 * Return: Always 0.
*/
int main(void)
{
        int n;



        if (n > 0)
                printf("%d is positive\n", n);
        else if (n < 0)
                printf("%d is negative\n", n);
        else
                printf("%d is zero\n", n);

        return (0);
        
        }
