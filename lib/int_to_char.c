/*
** EPITECH PROJECT, 2021
** int_to_char.c
** File description:
** none
*/

#include "my.h"

char *int_to_char(int result)
{
    int i = 0;
    char *res;
    res = malloc(sizeof(char) * 12);
    int d;
    d = 1;
    if (result < 0) {
        res[i] = ('-');
        result *= -1;
        i += 1;
    }
    while ((result / d) >= 10)
        d *= 10;
    while (d > 0) {
        res[i] = result / d % 10 + '0';
        d /= 10;
        i += 1;
    }
    res[i] = '\0';
    return res;
}
