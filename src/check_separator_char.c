/*
** EPITECH PROJECT, 2022
** rmv_quotation_mark.c
** File description:
** Created by louis on 04/04/2022.
*/

#include "my.h"

char *create_new_str(char *str, char *new_str, int i, int j)
{
    while (str[i] != '\0') {
        if (str[i] == ';') {
            my_strcat(new_str, " ; ");
            j += 3, i++;
        }
        if (str[i] == '|') {
            my_strcat(new_str, " | ");
            j += 3, i++;
        }
        if (str[i] == '&' && str[i + 1] == '&') {
            my_strcat(new_str, " && ");
            j += 4, i += 2;
        }
        new_str[j++] = str[i];
        i++;
    }
    new_str[j] = '\0';
    free(str);
    return new_str;
}

char *check_separator_char(char *str)
{
    int i = 0, j = 0;
    int count = 0;
    while (str[i++] != '\0')
        if (str[i] == ';' || str[i] == '|'
        || (str[i] == '&' && str[i + 1] == '&'))
            count++;
    if (count == 0)
        return str;
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + (count * 2) + 1));
    for (int k = 0; k < ((my_strlen(str) + (count * 2))); k++)
        new_str[k] = '\0';
    i = 0;
    return create_new_str(str, new_str, i, j);
}
