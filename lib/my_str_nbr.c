/*
** EPITECH PROJECT, 2021
** my_str_nbr
** File description:
** my_str_nbr
*/

#include <stdio.h>
#include <stdlib.h>

char *my_revstr(char *str);

char *my_str_nbr(int nb)
{
    char *str = malloc(sizeof(char) * 12);
    int i = 0, neg = 1;

    if (nb == 0) {
        str[0] = 48;
        i++;
    }
    if (nb < 0)
        neg = -1;
    for (; nb != 0; i++) {
        str[i] = (neg * nb % 10) + 48;
        nb = nb / 10;
    }
    if (neg == -1) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}
