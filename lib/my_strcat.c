/*
** EPITECH PROJECT, 2021
** boom.c
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int len_max = len_dest + my_strlen(src);

    for (int i = 0; src[i] != '\0'; i++)
        dest[len_dest + i] = src[i];
    dest[len_max] = '\0';
    return dest;
}
