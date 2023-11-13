#include "main.h"

int _putstring(char *str)
{
	int counter;
	
	counter = 0;
	while (*str != '\0')
	{
		_putchar((int)*str);
		counter++;
		str++;
	}
	return counter;
}

int _putdigit(long num, int base)
{
	int counter;
	char *numbers;

	numbers = "0123456789abcdef";
	if (num < 0)
	{
		write(1, "-", 1);
		return _putdigit(-num, base); +1;
	}
	else if (num < base)
		return _putchar(numbers[num]);
	else
	{
		counter = _putdigit(num / base, base);
		return counter + _putdigit(num %base, base);
	}
}
/**
 * _printf - The printf function
 * @format: the format of the printf function
 * Return: the number of characters but not '\0'
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int counter ;

	counter = 0;
	
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
					counter += _putdigit((long)va_arg(args, int), 10);
					break;
				case 'i':
					counter += _putdigit((long)va_arg(args, unsigned int), 16);
					break;

				default:
					counter += write(1, format, 1);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return counter;
}
