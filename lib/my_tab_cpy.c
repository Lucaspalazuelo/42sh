/*
** EPITECH PROJECT, 2022
** my_tab_cpy.c
** File description:
** Created by louis on 22/04/2022.
*/

#include "my.h"

char **my_tab_cpy(char **old)
{
    char **new;
    int i = 0;

    for (; old[i] != NULL; i++);
    new = malloc(sizeof(char *) * (i + 1));
    for (i = 0; old[i] != NULL; i++)
        new[i] = my_strdup(old[i]);
    new[i] = NULL;
    return new;
}
