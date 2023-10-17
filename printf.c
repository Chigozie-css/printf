#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: check
 */

int _printf(const char *format, ...)
{
	int (*bfunc)(va_list, flags_t *);
	const char *b;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int check = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (b = format; *b; b++)
	{
		if (*b == '%')
		{
			b++;
			if (*b == '%')
			{
				check += _putchar('%');
				continue;
			}
			while (get_flag(*b, &flags))
				b++;
			bfunc = get_print(*b);
			check += (bfunc)
				? bfunc(arguments, &flags)
				: _printf("%%%c", *b);
		}
		else
			check += _putchar(*b);
	}
	_putchar(-1);
	va_end(arguments);
	return (check);
}
