/*
** EPITECH PROJECT, 2021
** rev_str.c
** File description:
** try
*/

int my_len_lol_ptdr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *my_revstr(char *str)
{
    char buf;
    int i = 0;
    int index = my_len_lol_ptdr(str) - 1;

    while (index >= 0 && i <= (index / 2)) {
        buf = str[i];
        str[i] = str[index - i];
        str[index - i] = buf;
        i++;
    }
    return str;
}
