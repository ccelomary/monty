#include "monty.h"

/**
 * _put_number_helper - function that prints
 * number into stdout
 *
 * @n: number to be printed
 * Return: (void)
 */
void _put_number_helper(long int n)
{
	char c;

	if (!n)
		return;
	_put_number_helper(n / 10);
	c = (n % 10) + 48;
	write(1, &c, 1);
}

/**
 * putnumber - function that prints
 * number into stdout
 *
 * @n: number to be printed
 * Return: (void)
 */
void putnumber(long int n)
{
	if (!n)
		write(1, "0", 1);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
		_put_number_helper(n);
	}
	write(1, "\n", 1);
}
