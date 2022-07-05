/*
** EPITECH PROJECT, 2022
** my_print_tab.c
** File description:
** Created by louis on 27/04/2022.
*/

#include "my.h"

void my_print_tab(char **tab)
{
    if (tab == NULL) {
        my_printf("(NULL)\n");
        return;
    }
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("%i: %s\n", i, tab[i]);
    }
}
