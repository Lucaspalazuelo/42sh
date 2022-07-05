/*
** EPITECH PROJECT, 2022
** my_count_tab.c
** File description:
** Created by louis on 18/05/2022.
*/

#include "my.h"

int my_count_tab(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}
