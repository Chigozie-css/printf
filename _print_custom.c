#include "main.h"

/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @argsList: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: check
 */

int print_bigS(va_list argsList, flags_t *f)
{
	int a, check = 0;
	char *r;
	char *t = va_arg(argsList, char *);

	(void)f;
	if (!t)
		return (_puts("(null)"));

	for (a = 0; t[a]; a++)
	{
		if (t[a] > 0 && (t[a] < 32 || t[a] >= 127))
		{
			_puts("\\x");
			check += 2;
			r = convert(t[a], 16, 0);
			if (!r[1])
				check += _putchar('0');
			check += _puts(r);
		}
		else
			check += _putchar(t[a]);
	}
	return (check);
}

/**
 * print_rev - prints a string in reverse
 * @argsList: argument from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: int
 */

int print_rev(va_list argsList, flags_t *f)
{
	int a = 0, b;
	char *t = va_arg(argsList, char *);

	(void)f;
	if (!t)
		t = "(null)";

	while (t[a])
		a++;

	for (b = a - 1; b >= 0; b--)
		_putchar(t[b]);

	return (a);
}

/**
 * print_rot13 - prints a string using rot13
 * @argsList: list of arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */

int print_rot13(va_list argsList, flags_t *f)
{
	int a, b;
	char case1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char CASE2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *t = va_arg(argsList, char *);

	(void)f;
	for (b = 0; t[b]; b++)
	{
		if (t[b] < 'A' || (t[b] > 'Z' && t[b] < 'a') || t[b] > 'z')
			_putchar(t[b]);
		else
		{
			for (a = 0; a <= 52; a++)
			{
				if (t[b] == case1[a])
					_putchar(CASE2[a]);
			}
		}
	}
	return (b);
}

/**
 * print_percent - prints a percent
 * @argsList: va_list arguments from _printf
 * @f: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */

int print_percent(va_list argsList, flags_t *f)
{
	(void)argsList;
	(void)f;
	return (_putchar('%'));
}
