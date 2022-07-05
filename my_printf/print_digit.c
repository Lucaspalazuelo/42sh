/*
** EPITECH PROJECT, 2021
** print_digit.c
** File description:
** Created by louis on 16/11/2021.
*/

#include "my_printf.h"

void my_print_digit(char *arg, va_list ap, var_t *var)
{
    int nbr;
    int value;
    int i = var->i;

    if ((arg[i] != 'd' && arg[i] != 'i' && arg[i] != 'u'))
        return;
    if (arg[i - 1] == 'l')
        return;
    if (arg[i - 1] == '*') {
        value = va_arg(ap, int);
        var->index = value;
    }
    nbr = va_arg(ap, int);
    manage_space((long) nbr, var);
    arg[i - 1] == ' ' ? my_putchar(' ') : i;
    my_put_nbr(nbr);
    space_after(nbr, var);
}

void my_print_octal(char *arg, va_list ap, var_t *var)
{
    int nbr;
    int i = var->i;

    if (arg[i] != 'o')
        return;
    nbr = va_arg(ap, int);
    manage_space((long) nbr, var);
    my_put_nbr(convert_octal(nbr));
    space_after(nbr, var);
}

void my_print_long(char *arg, va_list ap, var_t *var)
{
    long nbr;
    int i = var->i;

    if (arg[i - 1] == 'l') {
        nbr = va_arg(ap, long);
        manage_space(nbr, var);
        arg[i - 2] == ' ' ? my_putchar(' ') : i;
        my_put_long(nbr);
        space_after(nbr, var);
    }
}
