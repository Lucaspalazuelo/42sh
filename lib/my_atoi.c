/*
** EPITECH PROJECT, 2021
** my_atoi
** File description:
** return a char *str
*/

#include <unistd.h>
#include <stdio.h>

int my_atoi(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
        }
        i += 1;
    }
    return nb;
}
