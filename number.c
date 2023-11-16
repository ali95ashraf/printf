
#include "main.h"
/**
* convert - converter function, a clone of itoa
* @num: number
* @base: base
* @flags: argument flags
* @parameters: parameter struct
*
* Return: string
*/
char *convert(long int num, int base, int flags, params_t *parameters)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;
    (void)parameters;  // Unused parameters, added to avoid compiler warning

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }
    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;
    return (ptr);
}
/**
* print_unsigned - prints unsigned integer numbers
* @ap: argument pointer
* @parameters: the parameters struct
*
* Return: bytes printed
*/
int print_unsigned(va_list ap, params_t *parameters) {
    unsigned long l;

    if (parameters->l_modifier)
        l = (unsigned long)va_arg(ap,unsigned long);
    else if (parameters->h_modifier)
        l = (unsigned short int)va_arg(ap,unsigned int);
    else
    l = (unsigned int) va_arg(ap,unsigned int);
    parameters->unsign = 1;
    return (print_number(convert(l, 10, CONVERT_UNSIGNED, parameters), parameters));
}
/**
* print_address - prints address
* @ap: argument pointer
* @parameters: the parameters struct
*
* Return: bytes printed
*/
int print_address(va_list ap, params_t *parameters)
{
    unsigned long int n = va_arg(ap,
    unsigned long int);
    char *str;

    if (!n)
        return (_puts("(nil)"));

    str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, parameters);
    *--str = 'x';
    *--str = '0';
    return (print_number(str, parameters));
}
