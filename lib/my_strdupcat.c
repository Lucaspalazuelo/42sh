/*
** EPITECH PROJECT, 2021
** my_strdupcat.c
** File description:
** Created by louis on 02/12/2021.
*/

#include "my.h"

char *my_strdupcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *str = malloc(sizeof(char) * (dest_len + src_len + 1));
    int i;

    for (int j = 0; j < dest_len; j++)
        str[j] = dest[j];
    for (i = 0; src[i] != '\0'; i++)
        str[dest_len + i] = src[i];
    str[dest_len + i] = '\0';
    return (str);
}
