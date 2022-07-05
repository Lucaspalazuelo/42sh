/*
** EPITECH PROJECT, 2021
** print_string.c
** File description:
** Created by louis on 16/11/2021.
*/

#include "my_printf.h"

void manage_space_str(char *str, var_t *var)
{
    if (var->index == -1)
        return;
    long len = my_strlen(str);
    if (len >= var->index)
        return;
    for (long j = 0; j < var->index - len; j++)
        my_putchar(' ');
}

void manage_space_char(var_t *var)
{
    if (var->index == -1)
        return;
    if (1 >= var->index)
        return;
    for (long j = 0; j < var->index - 1; j++)
        my_putchar(' ');
}

void my_print_string(char *arg, va_list ap, var_t *var)
{
    char *str;
    int i = var->i;

    if (arg[i] != 's')
        return;
    str = va_arg(ap, char *);
    manage_space_str(str, var);
    my_putstr(str);
}

void my_print_char(char *arg, va_list ap, var_t *var)
{
    char charac;
    int i = var->i;
    if (arg[i] != 'c')
        return;
    charac = va_arg(ap, int);
    manage_space_char(var);
    my_putchar(charac);
}
