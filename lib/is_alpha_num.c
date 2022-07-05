/*
** EPITECH PROJECT, 2022
** is_alpha_num.c
** File description:
** Created by louis on 21/02/2022.
*/

int is_alpha_num(char charach)
{
    if (charach >= 'a' && charach <= 'z')
        return 1;
    if (charach >= 'A' && charach <= 'Z')
        return 1;
    if (charach >= '0' && charach <= '9')
        return 1;
    return 0;
}
