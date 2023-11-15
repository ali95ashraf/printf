//
// Created by Ali Ashraf on 13/11/2023.
//
#include "main.h"

/**
* init_params - clears struct fields and reset buf
* @pararmeters: the parameters struct
* @ap: the argument pointer
*
* Return: void
*/
void init_params(params_t *parameters, va_list ap)
{
    parameters->unsign = 0;
    parameters->minus_flag = 0;
    parameters->space_flag = 0;
    parameters->hashtag_flag = 0;
    parameters->plus_flag = 0;
    parameters->zero_flag = 0;
    parameters->precision = UINT_MAX;
    parameters->h_modifier = 0;
    parameters->l_modifier = 0;
    parameters->width = 0;
    (void)ap;  // Unused parameter, added to avoid compiler warning
}
