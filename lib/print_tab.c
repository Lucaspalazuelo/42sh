/*
** EPITECH PROJECT, 2022
** print_tab.c
** File description:
** Created by louis on 12/04/2022.
*/

#include "my.h"

void print_tab(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_printf("%i: %s\n", i, array[i]);
    }
}
