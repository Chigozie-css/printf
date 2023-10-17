#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */

typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums */
int print_int(va_list argsList, flags_t *f);
void print_number(int a);
int print_unsigned(va_list argsList, flags_t *f);
int check_num(int a);

/* print_bases */
int print_hex(va_list argsList, flags_t *f);
int print_hex_big(va_list argsList, flags_t *f);
int print_binary(va_list argsList, flags_t *f);
int print_octal(va_list argsList, flags_t *f);


/* converter */
char *convert(unsigned long int nb, int base, int lcase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char spc))(va_list, flags_t *);


/* get_flag */
int get_flag(char spc, flags_t *f);

/* print_alpha */
int print_string(va_list argsList, flags_t *f);
int print_char(va_list argsList, flags_t *f);

/* write_funcs */
int _putchar(char chara);
int _puts(char *string);

/* print_custom */
int print_rot13(va_list argsList, flags_t *f);
int print_rev(va_list argsList, flags_t *f);
int print_bigS(va_list argsList, flags_t *f);

/* print_address */
int print_address(va_list nl, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);

#endif

