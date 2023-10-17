#include "main.h"

/**
 * convert - converts number and base into string
 * @nb: input number
 * @base: input base
 * @lcase: flag if hexa values need to be lowercase
 * Return: b
 */

char *convert(unsigned long int nb, int base, int lcase)
{
	static char *pre;
	static char buffer[50];
	char *b;

	pre = (lcase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	b = &buffer[49];
	*b = '\0';
	do {
		*--b = pre[nb % base];
		nb /= base;
	} while (nb != 0);
	return (b);
}
