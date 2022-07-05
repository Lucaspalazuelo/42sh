/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** none
*/

#include "my_printf.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}
