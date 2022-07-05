/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** Created by louis on 12/11/2021.
*/

#include "my_printf.h"

void les_free(var_t *var)
{
    if (var->str != NULL)
        free(var->str);
    free(var);
}

void init(var_t *var)
{
    var->i = 0;
    var->nbr = 0;
    var->lock = var->nbr;
    var->lock2 = 1;
    var->str = NULL;
}

char letter(char c)
{
    char str[10] = "%sciduxXo";
    for (int i = 0; i < 10; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int my_param(char *str, va_list ap, var_t *var)
{
    var->index = -1;
    var->index = index_function(str, var->i + 1);
    var->str = my_strdup(str);
    for (var->i += 1; letter(str[var->i]) == 0; var->i++) {}
    my_print_digit(str, ap, var);
    my_print_string(str, ap, var);
    my_print_char(str, ap, var);
    my_print_long(str, ap, var);
    my_print_octal(str, ap, var);
    my_print_hexa_x(str, ap, var);
    my_special_print_string(str, ap, var);
    my_print_hexa_big_x(str, ap, var);
    if (str[var->i] == '%')
        my_putchar('%');
    return var->i;
}

void my_printf(char *str, ...)
{
    var_t *var;
    var = malloc(sizeof(var_t));
    init(var);
    va_list ap;
    va_start(ap, str);
    for (var->i = 0; str[var->i] != '\0'; var->i++) {
        if (str[var->i] == '%') {
            var->i = my_param(str, ap, var);
            free(var->str);
            var->str = NULL;
        } else
            my_putchar(str[var->i]);
    }
    va_end(ap);
    les_free(var);
}
