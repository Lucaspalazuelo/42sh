/*
** EPITECH PROJECT, 2022
** search_globbings.c
** File description:
** Created by louis on 20/05/2022.
*/

#include "my.h"

int search_globbings_scd(char **array, int i)
{
    for (int j = 0; array[i][j] != '\0'; j++) {
        if (is_globbing(array[i][j]) == 1 && array[i][0] != '"'
            && array[i][0] != '\'') {
            return i;
        }
    }
    return -1;
}

int search_globbings(char **array)
{
    int ret;
    for (int i = 0; array[i] != NULL; i++)
        if ((ret = search_globbings_scd(array, i)) != -1)
            return ret;
    return -1;
}