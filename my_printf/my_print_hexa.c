/*
** EPITECH PROJECT, 2021
** my_print_hexa.c
** File description:
** Created by louis on 18/11/2021.
*/

#include "my_printf.h"

void print_hexa_scd(char *arg, int i, var_t *var, long nbr)
{
    i -= 2;
    char *str3 = int_to_char(nbr);
    long len3 = my_strlen(str3);
    free(str3);
    var->nbr = len3 > 5 ? -1 : -2;
    while (arg[i] != '%') {
        if (arg[i] == '#') {
            var->lock2 = 0;
            var->lock = len3 > 5 ? 1 : 0;
        } else {
            var->lock = len3 > 5 ? 1 : 0;
            var->lock2 = 1;
        }
        i--;
    }
}

void my_print_hexa_x(char *arg, va_list ap, var_t *var)
{
    int nbr, i = var->i;
    if (arg[i] != 'x')
        return;
    nbr = va_arg(ap, int);
    if (arg[i - 1] == '%') {
        my_putnbr_base(nbr, "0123456789abcdef");
        return;
    }
    if (arg[i - 2] == '%' && arg[i - 1] == '#') {
        my_putstr("0x");
        my_putnbr_base(nbr, "0123456789abcdef");
        return;
    }
    print_hexa_scd(arg, i, var, nbr);
    manage_space((long) nbr, var);
    if (var->lock2 == 0)
        my_putstr("0x");
    my_putnbr_base(nbr, "0123456789abcdef");
    manage_space_after_hexa(nbr, var);
}

void my_print_hexa_big_x(char *arg, va_list ap, var_t *var)
{
    int nbr, i = var->i;
    if (arg[i] != 'X')
        return;
    nbr = va_arg(ap, int);
    if (arg[i - 1] == '%') {
        my_putnbr_base(nbr, "0123456789ABCDEF");
        return;
    }
    if (arg[i - 2] == '%' && arg[i - 1] == '#') {
        my_putstr("0x");
        my_putnbr_base(nbr, "0123456789ABCDEF");
        return;
    }
    print_hexa_scd(arg, i, var, nbr);
    manage_space((long) nbr, var);
    if (var->lock2 == 0)
        my_putstr("0x");
    my_putnbr_base(nbr, "0123456789ABCDEF");
    var->lock2 = 1;
    manage_space_after_hexa(nbr, var);
}
