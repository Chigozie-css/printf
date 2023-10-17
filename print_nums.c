#include "main.h"

/**
 * print_int - prints an integer
 * @argsList: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */

int print_int(va_list argsList, flags_t *f)
{
	int a = va_arg(argsList, int);
	int r = check_num(a);

	if (f->space == 1 && f->plus == 0 && a >= 0)
		r += _putchar(' ');
	if (f->plus == 1 && a >= 0)
		r += _putchar('+');
	if (a <= 0)
		r++;
	print_number(a);
	return (r);
}

/**
 * print_unsigned - prints an unsigned integer
 * @argsList: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */

int print_unsigned(va_list argsList, flags_t *f)
{
	unsigned int a = va_arg(argsList, unsigned int);
	char *string = convert(a, 10, 0);

	(void)f;
	return (_puts(string));
}

/**
 * print_number - helper function that loops through
 * an integer and prints all its digits
 * @a: integer to be printed
 */

void print_number(int a)
{
	unsigned int ab;

	if (a < 0)
	{
		_putchar('-');
		ab = -a;
	}
	else
		ab = a;
	if (ab / 10)
		print_number(ab / 10);
	_putchar((ab % 10) + '0');
}

/**
 * check_num - returns the number of digits in an integer
 * for _printf
 * @a: integer to evaluate
 * Return: number of digits
 */

int check_num(int a)
{
	unsigned int b = 0;
	unsigned int c;

	if (a < 0)
		c = a * -1;
	else
		c = a;
	while (c != 0)
	{
		c /= 10;
		b++;
	}
	return (b);
}
