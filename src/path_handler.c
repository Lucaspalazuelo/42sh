/*
** EPITECH PROJECT, 2022
** path_handler.c
** File description:
** Created by louis on 22/02/2022.
*/

#include "my.h"

int search_for_separator(char *strtoken, int i)
{
    while (strtoken[i] != '\0') {
        if (strtoken[i] != ' ' && strtoken[i] != '\t'
        && strtoken[i] != '\n' && strtoken[i] != ';')
            return i;
        if (strtoken[i] == ';')
            strtoken[i] = ' ';
        i++;
    }
    return i;
}

void rmv_surplus_seprarator(char *strtoken)
{
    int i = 0, last_sep = 0, tmp;
    search_for_separator(strtoken, 0);
    while (i < my_strlen(strtoken) && strtoken[i] != '\0') {
        if (strtoken[i] == ';')
            last_sep = i;
        if (strtoken[i] == ';')
            i = search_for_separator(strtoken, i + 1);
        i++;
    }
    tmp = last_sep;
    if (my_strlen(strtoken) == 2)
        return;
    while (strtoken[++last_sep] != '\0') {
        if (strtoken[last_sep] != ' ' && strtoken[last_sep] != '\n'
        && strtoken[last_sep] != '\t')
            return;
        i++;
    }
    strtoken[tmp] = ' ';
}

char **my_split_scd(char *concat, char **array, char *new_buffer, all_t *s_all)
{
    if (concat == NULL) {
        s_all->the_return = 1;
        write(2, "Unmatched '\"'.\n", 17);
        return NULL;
    }
    array = my_sp_str_to_word_array(concat, " ");
    double_sep_start(s_all, array);
    free(concat);
    free(new_buffer);
    concat = NULL;
    if (s_all->the_return == 1) {
        my_free_tab(array);
        return NULL;
    }
    return array;
}

char **my_split(char *buffer, all_t *s_all)
{
    rmv_surplus_seprarator(buffer);
    char *new_buffer = check_separator_char(my_strdup(buffer));
    char **array = NULL;
    char *concat = malloc(sizeof(char) * (my_strlen(new_buffer) + 1));
    for (int i = 0; i < my_strlen(new_buffer); i++)
        concat[i] = '\0';
    char separators[3] = " \n\t";
    char *strtoken = strtok(new_buffer, separators);
    while (strtoken != NULL) {
        my_strcat(concat, strtoken);
        my_strcat(concat, " ");
        strtoken = strtok(NULL, separators);
    }
    concat = check_quotation_mark(concat);
    return my_split_scd(concat, array, new_buffer, s_all);
}
