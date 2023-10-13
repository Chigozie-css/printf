#include "main.h"

/**
 * _printf - function that produces output
 * according to a format.
 *
 * @format: character string
 *
 * Return: charac
 */

int _printf(const char *format, ...)
{
	int charac = 0;
	va_list args_list;

	if (format == NULL)
	{
		return (0);
	}

	va_start(args_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			charac++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
					charac++;
			}
			else if  (*format == 'c')
			{
				char c  = va_arg(args_list, int);

				write(1, &c, 1);
				charac++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(args_list, char*);
				int stringLen = 0;

				while (string[stringLen] != '\0')
					stringLen++;
				write(1, string, stringLen);
				charac += stringLen;
			}
		}
		format++;
	}
	va_end(args_list);
	return (charac);
}
