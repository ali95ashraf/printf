#include "main.h"
/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @parameters: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *parameters, va_list ap)
{
    int d = 0;

    if (*p != '.')
        return p;

    p++; // Move to the character after '.'
    if (*p == '*')
    {
        // If precision is specified as '*', get it from the argument list
        d = va_arg(ap, int);
        p++; // Move to the next character
    }
    else
    {
        // Read precision as a number
        while (_isdigit(*p))
            d = d * 10 + (*p++ - '0');
    }

    // Update the precision in the parameters struct
    parameters->precision = d;
    return (p); // Return the new pointer position in the format string
}
