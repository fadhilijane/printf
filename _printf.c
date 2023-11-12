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
			write(stdout, *format, strlen(*format));
			counter++;
		}
		else

	}
}
