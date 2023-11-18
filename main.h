#ifndef _PRINTF_H
#define _PRINTF_H

#include "stdarg.h"
#include "stdio.h"
#include "unistd.h"
#include "limits.h"
#include "stdlib.h"

#define OUTPUT_BUF_SIZE 1024  /* task 4 */
#define BUF_FLUSH -1            /* task 4 */

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	/* task 7 ,8 ,9 ,10 ,11 ,12 */

#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

/**
* struct parameters - parameters struct
* @unsign: flag if unsigned value
* @plus_flag: on if plus flag specified
* @space_flag: on if hashtag flag specified
*			+ Chashtag flag: on if flag specified
* @zero_flag: on if flag specified
* @minus_flag: on if flag specified
* @width: field width specified
* @precision: field precision specified
*
* @h_modifier: on if h_modifier is specified
* @1_modifier: on if 1_modifier is specified
*/

typedef struct parameters
{
	unsigned int unsign: 1; /* task 7 */
	unsigned int plus_flag: 1; /* task 7 */
	unsigned int space_flag: 1; /* task 7 */
	unsigned int hashtag_flag: 1;
	unsigned int zero_flag: 1; /* task 11 */
	unsigned int minus_flag: 1; /* task 12 */
	unsigned int width; /* task 9 */
	unsigned int precision; /* task 10 */
	unsigned int h_modifier: 1; /* task 8 */
	unsigned int l_modifier: 1; /* task 8 */
} params_t;

/*
* struct specifier - Struct token
* @specifier: format token
* @f: The function associated
*/
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *str);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ap, params_t *parameters);          /* task 0 */
int print_int(va_list ap, params_t *parameters);      /* task 1 */
int print_string(va_list ap, params_t *parameters);        /* task 0 */
int print_percent(va_list ap, params_t *parameters);       /* task 0 */
int print_s(va_list ap, params_t *parameters);              /* task 5 */

/* number.c module */
char *convert(long int num, int base, int flags, params_t *parameters);
int print_unsigned(va_list ap, params_t *parameters); /* task 3 */
int print_address(va_list ap, params_t *parameters);    /* task 6 */

/* specifier.c module */
int (*get_specifier(char *s)) (va_list ap, params_t *parameters);
int get_print_func(char *s, va_list ap, params_t *parameters);
int get_flag(char *s, params_t *parameters);
int get_modifier(char *s, params_t *parameters);
char *get_width(char *s, params_t *parameters, va_list ap);

/* convert_number.c module */
int print_hex(va_list ap, params_t *parameters);        /* task 3 */
int print_HEX(va_list ap, params_t *parameters);        /* task 3 */
int print_binary(va_list ap, params_t *parameters);    /* task 2 */
int print_octal(va_list ap, params_t *parameters);     /* task 3 */

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *parameters); /* task 13 */
int print_rot13(va_list ap, params_t *parameters); /* task 14 */

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *parameters);
int print_number_right_shift(char *str, params_t *parameters);
int print_number_left_shift(char *str, params_t *parameters);

/* params.c module */
void init_params(params_t *parameters, va_list ap);

/* string_fields.c module */
char *get_precision(char *p, params_t *parameters, va_list);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif
