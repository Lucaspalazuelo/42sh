/*
** EPITECH PROJECT, 2021
** my_put_nbr_base.c
** File description:
** Created by louis on 16/11/2021.
*/

#include "my_printf.h"

int my_putnbr_base(int nbr, char const *base)
{
    int result;
    int power = 1;
    int len_base = my_strlen(base);

    if (nbr == -1) {
        my_putstr("FFFFFFFF");
        return (0);
    }
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    while ((nbr / power) >= len_base)
        power *= len_base;
    while (power > 0) {
        result = (nbr / power) % len_base;
        my_putchar(base[result]);
        power = power / len_base;
    }
    return 1;
}
