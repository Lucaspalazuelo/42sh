/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** put and display numbers
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    char tmp = '0';

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    tmp = (nb % 10) + '0';
    my_putchar(tmp);
    return 0;
}
