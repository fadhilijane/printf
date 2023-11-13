#include "main.h"

/**
 * _printf - The printf function
 * @format: the format of the printf function
 * Return: the number of characters but not '\0'
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int counter = 0;
	
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
					counter += write(stdout, va_arg(args, char), 1);
					break;
				case 's':
					counter += write(stdout, va_arg(args, char *), 1);
					break;
				case 'd':
					counter += write(stdout, va_arg(args, int), 1);
					break;
				case 'i':counter += write(stdout, va_arg(args, unsigned int), 1);

				default:
					_putchar('%');
					_putchar(*format);
					counter += 2;
					break;
			}
		}
		format++;
	}
	va_end(args);
	return count;
}
