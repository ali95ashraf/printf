//
// Created by Ali Ashraf on 13/11/2023.
//
#include "main.h"
/**
 * get_specifier - finds the format func
 * @s: the format string
 * Return: the number of bytes printed
*/
int (*get_specifier(char *s)) (va_list ap, params_t *parameters)
{

    specifier_t specifiers [] =
            {
            {"c", print_char},
            {"d", print_int},
            {"¡", print_int},
            {"s", print_string},
            {"%", print_percent},
            {"b", print_binary},
            {"o", print_octal},
            {"u", print_unsigned},
            {"x", print_hex},
            {"X", print_HEX},
            {"p", print_address},
            {"s", print_s},
            {"r", print_rev},
            {"R", print_rot13},
            {NULL, NULL}
            };
    int i = 0;

    while (specifiers[i].specifier)
    {
        if (*s == specifiers[i].specifier[0])
        {
            return (specifiers[i].f);
        }
        i++;
    }
    return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @parameters: the parameters struct
 *
 * return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *parameters)
{
    int (*f)(va_list, params_t *) = get_specifier(s);

    if (f)
        return (f(ap, parameters));
    return (0);
}
/**
 * get_flag - finds the flag func
 * @s: the format string
 * @parameters: the parameters struct
 *
 * Return: if flag was valid
 */
 int get_flag(char *s, params_t *parameters)
 {
     int i = 0;

     switch (*s)
     {
         case '+':
             i = parameters->plus_flag = 1;
             break;
         case ' ':
             i = parameters->space_flag = 1;
             break;
         case '#':
             i = parameters->hashtag_flag = 1;
             break;
         case '-':
             i = parameters->minus_flag = 1;
             break;
         case '0':
                 i = parameters->zero_flag = 1;
             break;
     }
     return (i);
 }

 /**
  * get_modifier - finds the modifier func
  * @s: the format string
  * @parameters: the parameters struct
  *
  * Return: if modifier was valid
  */

 int get_modifier(char *s, params_t *parameters)
 {
     int i = 0;

     switch (*s)
     {
         case 'h':
             i = parameters->h_modifier = 1;
             break;
         case '1':
             i = parameters->l_modifier = 1;
             break;
     }
     return (i);
 }

 /**
  * get_width - gets the width from the format string
  * @s: the format string
  * @parameters: the parameters struct
  * @ap: the argument pointer
  *
  * Return: new pointer
  */
  char *get_width(char *s, params_t *parameters, va_list ap)
  {
      int d = 0;

      if (*s == '*')
      {
          d = va_arg(ap, int);
          s++;
      }
      else
      {
          while (_isdigit(*s))
              d = d * 10 + (*s++ - '0');
      }
      parameters->width = d;
      return (s);
  }