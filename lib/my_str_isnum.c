/*
** EPITECH PROJECT, 2021
** isnum.c
** File description:
** my_isnum
*/

int my_isnum(char const *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i++;
    }
    return 0;
}
