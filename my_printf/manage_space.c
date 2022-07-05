/*
** EPITECH PROJECT, 2021
** manage_space.c
** File description:
** Created by louis on 16/11/2021.
*/

#include "my_printf.h"

int index_function(char const *str, int i)
{
    char *new_str = my_sp_strcpy(str, i);
    int index = my_getnbr(new_str);
    free(new_str);
    return index;
}

int is_zero(var_t *var, int len2)
{
    if (var->str[var->i - len2 - 1] == '0') {
        if (var->lock2 == 0) {
            my_putstr("0x");
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

void manage_space(long nb, var_t *var)
{
    if (var->index == -1)
        return;
    char *str2 = int_to_char(var->index);
    int len2 = my_strlen(str2);
    free(str2);
    char *str3 = int_to_char(nb);
    long len3 = my_strlen(str3);
    free(str3);
    if (len3 >= var->index)
        return;
    for (long j = 0; j < var->index - len3 + var->lock; j++)
        is_zero(var, len2) == 1 ? my_putchar(' ') : my_putchar('0');
}

void space_after(long nb, var_t *var)
{
    if (var->index == -1)
        return;
    char *str2 = int_to_char(var->index);
    if (str2[0] != '-') {
        free(str2);
        return;
    }
    var->index *= -1;
    free(str2);
    manage_space(nb, var);
}
