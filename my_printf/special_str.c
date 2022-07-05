/*
** EPITECH PROJECT, 2021
** special_str.c
** File description:
** Created by louis on 17/11/2021.
*/

#include "my_printf.h"

void str_octal(int octal)
{
    int count = 1;

    my_putchar('\\');
    while (octal * count < 100) {
        my_putchar('0');
        count *= 10;
    }
    my_put_nbr(octal);
}

int special_str(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126)
            my_putchar(str[i]);
        else
            str_octal(convert_octal((int)str[i]));
    }
    return (0);
}

void my_special_print_string(char *arg, va_list ap, var_t *var)
{
    char *str;
    int i = var->i;

    if (arg[i] != 'S')
        return;
    str = va_arg(ap, char *);
    manage_space_str(str, var);
    special_str(str);
}
