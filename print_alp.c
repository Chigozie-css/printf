#include "main.h"

/**
 * print_string - loops through a string and prints
 * every character
 * @argsList: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: a printed number of char
 */

int print_string(va_list argsList, flags_t *f)
{
	char *alp = va_arg(argsList, char *);

	(void)f;

	if (!alp)
		alp = "(null)";
	return (_puts(alp));
}

/**
 * print_char - prints a character
 * @argsList: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */

int print_char(va_list argsList, flags_t *f)
{
	(void)f;
	_putchar(va_arg(argsList, int));
	return (1);
}
