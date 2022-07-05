/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** my_to_word_array
*/

#include "stdlib.h"

int check_charac(char const *charac, char str)
{
    int i = 0;
    while (charac[i] != '\0') {
        if (charac[i] == str)
            return 1;
        i++;
    }
    return 0;
}

int sp_nb_words(char const *str, char *charach)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (i != 0 && check_charac(charach, str[i]) == 1
            && check_charac(charach, str[i - 1]) != 1)
            j++;
        i++;
    }
    if (i > 0 && check_charac(charach, str[i - 1]) != 1)
        j++;
    return j;
}

int sp_word_len(char const *str, int i, char *charach)
{
    int len = 0;
    while (check_charac(charach, str[i]) != 1 && str[i] != '\0') {
        len++;
        i++;
    }
    return len;
}

char *sp_cpy_word(char const *str, int i, char *charac)
{
    int x = 0;
    int nb_lettres;
    nb_lettres = sp_word_len(str, i, charac);
    char *cpy = malloc(sizeof(char) * nb_lettres + 1);
    while (x < nb_lettres) {
        cpy[x] = str[i + x];
        x++;
    }
    cpy[x] = '\0';
    return cpy;
}

char **my_sp_str_to_word_array(char *str, char *charach)
{
    int i = 0;
    int y = 0;
    char **array = malloc(sizeof(char *) * (sp_nb_words(str, charach) + 1));
    while (str[i] != '\0') {
        if (check_charac(charach, str[i]) == 1)
            i++;
        else {
            array[y] = sp_cpy_word(str, i, charach);
            i += sp_word_len(str, i, charach);
            y += 1;
        }
    }
    array[y] = NULL;
    return array;
}
