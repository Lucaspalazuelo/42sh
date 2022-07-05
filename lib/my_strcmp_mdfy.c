/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** none
*/

#include "my.h"

int my_strcmp_real(char *s_1, char *s_2)
{
    int i = 0;
    char *s1 = my_strdup(s_1);
    char *s2 = my_strdup(s_2);
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        i++;
    int c = s1[i] - s2[i];
    free(s1);
    free(s2);
    return (c);
}
