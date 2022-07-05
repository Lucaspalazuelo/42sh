/*
** EPITECH PROJECT, 2022
** my_is_alpha.c
** File description:
** Created by louis on 22/04/2022.
*/

int my_str_is_alpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 1;
        i++;
    }
    return 0;
}

int my_char_is_alpha(char str)
{
    if ((str < 'a' || str > 'z') && (str < 'A' || str > 'Z'))
        return 1;
    return 0;
}
