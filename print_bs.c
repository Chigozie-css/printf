#include "main.h"

/**
 * print_hex - prints a number in hexadecimal base,
 * in lowercase
 * @argsList: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convert() which in turns converts the input
 * number into the correct base and returns it as a string
 * Return: a printed number of char
 */

int print_hex(va_list argsList, flags_t *f)
{
	unsigned int nb = va_arg(argsList, unsigned int);
	char *string = convert(nb, 16, 1);
	int check = 0;

	if (f->hash == 1 && string[0] != '0')
		check += _puts("0x");
	check += _puts(string);
	return (check);
}

/**
 * print_hex_big - prints a number in hexadecimal base,
 * in uppercase
 * @argsList: va_list arguments from _printf
 * @f: pointer to the struct that determines
 * if a flag is passed to _printf
 * Description: the function calls convert() which in turns converts the input
 * number into the correct base and returns it as a string
 * Return: a printed number of char
 */

int print_hex_big(va_list argsList, flags_t *f)
{
	unsigned int nb = va_arg(argsList, unsigned int);
	char *string = convert(nb, 16, 0);
	int check = 0;

	if (f->hash == 1 && string[0] != '0')
		check += _puts("0X");
	check += _puts(string);
	return (check);
}

/*
* print_binary - print a number in base 2 binary.
* @argsList: va_list arguments from _printf
* @f: pointer to the struct that determines
* if a flag is passed to _printf
* Description: the function calls convert) which in turns converts the input.
* Return: a printed number of char
*/

int print_binary(va_list argsList, flags_t *f)
{
	unsigned int nb = va_arg(argsList, unsigned int);
	char *string = convert(nb, 2, 0);

	(void)f;
	return (_puts(string));
}

/**
* print_octal - prints a number in base 8
* @argsList: va_list arguments from _printf
* @f: pointer to the struct that determines
* if a flag is passed to _printf
* Description: the function calls convert) which in turns converts the input
* number into the correct base and returns it as a string
* Return: the number of char printed
*/

int print_octal(va_list argsList, flags_t *f)
{
	unsigned int nb = va_arg(argsList, unsigned int);
	char *string = convert(nb, 8, 0);
	int check = 0;

	if (f->hash == 1 & 8 string[o] != '0*)
		check += _putchar(0);
	check += _puts(string);
	return (check);
}
