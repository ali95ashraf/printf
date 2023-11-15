//
// Created by Ali Ashraf on 13/11/2023.
//
#include "main.h"
/**
 * _printf - prints anything
 * @format: the format string
 *  Return: number of bytes printed
*/
int _printf(const char *format, ...)
{
    int sum = 0;
    va_list ap;
    char *p, *start;
    params_t parameters = PARAMS_INIT;

    va_start(ap, format);

    if (!format || format[0] == '\0' || (format[0] == '%' && !format[1]))
        return (-1);

    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);
    for (p = (char *)format; *p; p++)
    {
        init_params(&parameters, ap);
        if (*p != '%') {
            sum += _putchar(*p);
            continue;
        }
        start = p;
        p++;
        while (get_flag(p, &parameters)) /* while char at p is flag char*/
        {
            p++; /* next char */
        }
        p = get_width(p, &parameters, ap);
        p = get_precision(p, &parameters, ap);
        if (get_specifier(p))
            p++;
        if (!get_specifier(p))
            sum += print_from_to(start, p,
                                 parameters.l_modifier || parameters.h_modifier ? p - 1 : 0);
        else
            sum += get_print_func(p, ap, &parameters);
    }
    _putchar(BUF_FLUSH);
    va_end(ap);
    return (sum);
    }