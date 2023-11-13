/**
 * File: _printf.c
 * Author: Fadhili Jane
 *         Kaiga Githinji
 */

#include "main.h"
/**
 * _putstring - The function to print the string.
 * @str: The string to be printed.
 * Return: Number of characters printed.
 */
int _putstring(char *str)
{
	int count_chars;

	count_chars = 0;
	while (*str != '\0')
	{
		_putchar((int)*str);
		count_chars++;
		str++;
	}
	return (count_chars);
}
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
/**
 * _printf - The printf function
 * @format: the format of the printf function
 * Return: the number of characters but not '\0'
 */

int _printf(const char *format, ...)
{
	int counter = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			counter++;
		}
		else
		{
			switch (*++format)
			{
				case 'c':
					counter += _putchar(va_arg(args, int));
					break;
				case 's':
					counter += _putstring(va_arg(args, char *));
					break;
				case 'd':
					counter += _putdigit((long)va_arg(args, int), 16);
					break;
				case 'i':
					counter += _putdigit((long)va_arg(args, unsigned int), 16);
					break;
				case 'b':
			   		counter += _putdigit((long)va_arg(args, unsigned int), 2);
					break;

				default:
					counter += write(1, format, 1);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (counter);
}
