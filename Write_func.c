#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @chara: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 * Description: _putchar uses a local buffer of 1024 to call write
 * as little as possible
 */

int _putchar(char chara)
{
	static char buf[1024];
	static int a;

	if (chara == -1 || a >= 1024)
	{
		write(1, &buf, a);
		a = 0;
	}
	if (chara != -1)
	{
		buf[a] = chara;
		a++;
	}
	return (1);
}

/**
 * _puts - prints a string to stdout
 * @string: pointer to the string to print
 * Return: number of chars written
 */

int _puts(char *string)
{
	register int a;

	for (a = 0; string[a] != '\0'; a++)
		_putchar(string[a]);
	return (a);
}
