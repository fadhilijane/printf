#include "main.h"

/**
 * _putdigit - The function to print a number in a specified base.
 * @num: Parameter representing the number to be printed.
 * @base: Parameter representing the base to print the number into.
 * Return: +1 if num is negative
 */

int _putdigit(long num, int base)
{
	int count_digit;
	char *numbers;

	numbers = "0123456789abcdef";
	if (num < 0)
	{
		write(1, "-", 1);
		return (_putdigit(-num, base) + 1);
	}
	else if (num < base)
	{
		return (_putchar(numbers[num]));
	}
	else
	{
		count_digit = _putdigit(num / base, base);
		return (count_digit + _putdigit(num % base, base));
	}
}
