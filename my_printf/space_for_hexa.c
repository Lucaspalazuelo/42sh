/*
** EPITECH PROJECT, 2021
** space_for_hexa.c
** File description:
** Created by louis on 18/11/2021.
*/

#include "my_printf.h"

int is_zero_after(var_t *var, int len2)
{
    if (var->str[var->i - len2 - 1] == '0') {
        if (var->lock2 == 0) {
            var->lock = var->nbr;
            var->lock2 = 1;
        }
        return 0;
    } else if (var->str[var->i - len2 - 1] != '0'
    && var->str[var->i - len2 - 1] != ' ' && var->lock2 == 0) {
        var->lock = var->nbr;
    }
    return 1;
}

void manage_space_after_hexa(long nb, var_t *var)
{
    if (var->index == -1)
        return;
    char *str2 = int_to_char(var->index);
    if (str2[0] != '-') {
        free(str2);
        return;
    }
    var->index *= -1;
    long len2 = my_strlen(str2) - 1;
    free(str2);
    char *str3 = int_to_char(nb);
    long len3 = my_strlen(str3);
    free(str3);
    if (len3 >= var->index)
        return;
    is_zero_after(var, len2);
    for (long j = 0; j < var->index - len3 + var->lock; j++)
        my_putchar(' ');
}
