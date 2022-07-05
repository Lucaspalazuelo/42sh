/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** none
*/

#include "stdio.h"

long my_strlen(char const *str)
{
    long i = 0;

    while (str[i] != '\0')
        i += 1;
    return i;
}
