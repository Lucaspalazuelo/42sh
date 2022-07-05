/*
** EPITECH PROJECT, 2021
** my_put_float.c
** File description:
** Created by louis on 16/11/2021.
*/

#include "my_printf.h"

int my_putnbr_base_long(long nbr, char *base)
{
    int i = 0;
    int size;
    long nb;

    if (nbr < 0) {
        nbr = - nbr;
        i += 1;
        my_putchar('-');
    }
    size = my_strlen(base);
    if (nbr > 0) {
        nb = nbr;
        nbr /= size;
        i += my_putnbr_base_long(nbr, base);
        i += 1;
        my_putchar(base[nb % size]);
    }
    return (i);
}

int my_put_float(double nbr)
{
    long dec;
    long ent;
    double dec2;
    int i = 0;

    ent = nbr;
    dec = nbr * (float)1000000;
    dec -= ent * 1000000;
    dec2 = (double)dec;
    i += my_putnbr_base_long(ent, "0123456789");
    i++;
    my_putchar('.');
    i += my_putnbr_base_long((long)dec2, "0123456789");
    return (i);
}
