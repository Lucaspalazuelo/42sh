/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** dupe
*/

#include "my.h"

char *my_strdup(char *src)
{
    int index = my_strlen(src);
    char *new = malloc(sizeof(char) * (index + 1));

    return my_strcpy(new, src);
}
