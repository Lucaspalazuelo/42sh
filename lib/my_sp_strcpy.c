/*
** EPITECH PROJECT, 2021
** my_sp_strcpy.c
** File description:
** Created by louis on 15/11/2021.
*/

#include "my_printf.h"

char *my_sp_strcpy(char const *str, int i)
{
    int len = i;
    while (str[len] != '%' && str[len] != '\0')
        len++;
    int a = 0;
    char *dest = malloc(sizeof(char) * (len + 1));
    while (str[i] == ' ' || str[i] == '#')
        i++;
    while (a != len) {
        dest[a] = str[i];
        i++;
        a++;
    }
    dest[a] = '\0';
    return dest;
}
