#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - writes formatted output to stdout
 * @format: pointer to a format string
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 * On error, -1 is returned, and errno is set appropriately.
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list st;
	
	va_start(st, format);
	if (!format)
	{
		return (-1);
	}
	
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char)va_arg(st, int);
				putchar(c);
				count++;
			}
			if (*format == 's')
			{
				char *str = va_arg(st, char *);
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(st);
	return (count);
}
