#include "main.h"

/**
 * print_address - prints address of input in hexa format
 * @nl: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */

int print_address(va_list argsList, flags_t *f)
{
	char *string;
	unsigned long int b = va_arg(argsList, unsigned long int);

	register int check = 0;
	(void)f;

	if (!b)
		return (_puts("(nil)"));
	string = convert(b, 16, 1);
	check += _puts("0x");
	check += _puts(string);
	return (check);
}
