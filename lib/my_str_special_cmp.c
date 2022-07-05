/*
** EPITECH PROJECT, 2021
** my_str_special_cmp.c
** File description:
** none
*/

#include "stdio.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0')
        i++;
    while (s2[j] != '\0')
        j++;
    return (i - j);
}

int my_str_special_cmp_2(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0') {
        if (s1[i] < s2[i])
            return 1;
        i++;
    }
    return 0;
}

int my_str_special_cmp(char *s1, char *s2)
{
    if (my_strcmp(s1, s2) < 0)
        return 1;
    if (my_strcmp(s1, s2) == 0) {
        if (my_str_special_cmp_2(s1, s2) == 1)
            return 1;
    }
    return 0;
}
