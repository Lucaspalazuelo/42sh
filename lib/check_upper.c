/*
** EPITECH PROJECT, 2022
** check_upper.c
** File description:
** Created by louis on 21/01/2022.
*/

#include "my.h"

int check_upper(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            return 1;
        i++;
    }
    return 0;
}
