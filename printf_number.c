#include "main.h"
/**
 * printf_number - prints integer or decimal
 * @args: argument to print
 *
 * @args: flag to specify whether to print as decimal (1) or integer (0)
 * Return: number of characters printed
 */

int printf_number(va_list args)
{
	int num = va_arg(args, int);
	int n = 0;

	n += printf("%d", num);
	return (n);
}

/**
 * custom_printf - A custom printf function for basic output formatting.
 * @format: A format string specifying the output format.
 * @...: A variable number of arguments to insert into the format string.
 *
 * It supports integer format specifiers "d" and "i."
 * The function returns the total number of characters printed.
 */

int custom_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int n = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			n += printf_number(args);
			i++;
		}
		else
		{
			putchar(format[i]);
			n++;
		}
	}
	va_end(args);
	return (n);
}

int main(void)
{
	int num1 = 42;
	int num2 = -123;

	int printed = custom_printf("This is a custom printf: %d and %i\n", num1, num2);

	printf("n: %d\n", printed);
	return (0);
}
