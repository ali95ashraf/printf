#include "main.h"
/**
* is_digit - checks if character is a digit
* @c: the character to check
*
* Return: 1 if digit, 0 otherwise
*/
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
* str_length - returns the length of a string
* @s: the string whose length to check
* Return: integer length of the string
*/
int _strlen(char *s)
{
    int i = 0;

    while (*s++)
        i++;
    return i;
}

/**
* print_number - prints a number with options
* @str: the base number as a string
* @params: the parameter struct
* Return: chars printed
*/
int print_number(char *str, params_t *parameters)
{
    unsigned int i = _strlen(str);
    int neg = (!parameters->unsign && *str == '-');

    if (!parameters->precision && *str == '0' && !str[1])
        str = "";
    if (neg)
    {
        str++;
        i--;
    }
    if (parameters->precision != UINT_MAX)
        while (i++ < parameters->precision)
            *--str = '0';
    if (neg)
        *--str = '-';

    if (!parameters->minus_flag)
        return (print_number_right_shift(str, parameters));
    else
        return (print_number_left_shift(str, parameters));
}

/**
* print_number_right_shift - prints a number with options
* @str: the base number as a string
* @params: the parameter struct
*
* Return: chars printed
*/
int print_number_right_shift(char *str, params_t *parameters)
{
    unsigned int n = 0, neg, neg2, i = _strlen(str);
    char pad_char = ' ';

    if (parameters->zero_flag && !parameters->minus_flag)
        pad_char ='0';
    neg = neg2 = (!parameters->unsign && *str == '-');
    if (neg && i < parameters->width && pad_char == '0' && !parameters->minus_flag)
        str++;
    else
        neg = 0;
    if ((parameters->plus_flag && !neg2) ||
    (!parameters->plus_flag && parameters->space_flag && !neg2))
        i++;
    if (neg && pad_char == '0')
        n += _putchar('-');
    if (parameters->plus_flag && !neg2 && pad_char == '0' && !parameters->unsign)
        n += _putchar('+');
    else if (!parameters->plus_flag && parameters->space_flag && !neg2 &&
    !parameters->unsign && !parameters->zero_flag)
        n += _putchar(' ');
    while (i++ < parameters->width)
        n += _putchar(pad_char);
    if (neg && pad_char == ' ')
        n += _putchar('-');
    if (parameters->plus_flag && !neg && pad_char == ' ' && !parameters->unsign)
        n += _putchar('+');
    else if (!parameters->plus_flag && parameters->space_flag && !neg2 &&
    !parameters->unsign && !parameters->zero_flag)
        n += _putchar(' ');
    n += _puts(str);
    return (n);
}

/**
* print_number_left_shift - prints a number with options
* @str: the base number as a string
* @params: the parameter struct
*
* Return: chars printed
*/
int print_number_left_shift(char *str, params_t *parameters)
{
    unsigned int n = 0, neg, neg2 ,i = _strlen(str);
    char pad_char = ' ';

    if (parameters->zero_flag && !parameters->minus_flag)
        pad_char = '0';
    neg = neg2 = (!parameters->unsign && *str == '-');
    if (neg && i < parameters->width && pad_char == '0' && !parameters->minus_flag)
        str++;
    else
        neg = 0;

    if (parameters->plus_flag && !neg2 && !parameters->unsign)
        n += _putchar('+'), i++;
    else if (parameters->space_flag && !neg2 && !parameters->unsign)
        n += _putchar(' '), i++;
    n += _puts(str);
    while (i++ < parameters->width)
        n += _putchar(pad_char);
    return (n);
}
