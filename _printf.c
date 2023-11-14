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
		_putchar(*str);
		count_chars++;
		str++;
	}
	return(count_chars);
}

/**
 * write_format - gives the fomat of the printf
 * @symbol: letter after %
 * @args: arguments given
 * Return: count of xters
 */

int write_format(char symbol, va_list args)
{
	int counter = 0;

	switch (symbol)
	{
		case 'c':
			counter += _putchar(va_arg(args, int));
			break;
		case 's':
			counter += _putstring(va_arg(args, char *));
			break;
		case 'd': case 'i':
			counter += _putdigit((long)va_arg(args, int), 10);
			break;
		case 'b':
			counter += _putdigit((long)va_arg(args, unsigned int), 2);
			break;
		case 'u':
			counter += _putdigit((long)va_arg(args, unsigned int), 10);
			break;
		case 'o':
			counter += _putdigit((long)va_arg(args, unsigned int), 8);
			break;
		case 'x': case 'X':
			counter += _putdigit((long)va_arg(args, unsigned int), 16);
			break;
		default:
			counter += write(1, &symbol, 1);
			break;
	}
	return (counter);
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
			counter += write_format(*(++format), args);
		}
		format++;
	}
	va_end(args);
	return (counter);
}
