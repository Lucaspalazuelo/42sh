/*
** EPITECH PROJECT, 2021
** my_free_tab.c
** File description:
** Created by louis on 22/12/2021.
*/

#include "my.h"

void my_free_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i] != NULL) {
            free(tab[i]);
            tab[i] = NULL;
        }
    }
    free(tab);
    tab = NULL;
}
