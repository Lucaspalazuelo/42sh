/*
** EPITECH PROJECT, 2022
** check_quotation_mark.c
** File description:
** Created by louis on 04/04/2022.
*/

#include "my.h"

char *check_quotation_mark(char *concat)
{
    int i = 0, check = 0, start = 0, end;
    while (concat[i] != '\0') {
        if (concat[i] == '\"' && check == 1) {
            check = 0;
            end = i;
            concat = rmv_quotation_mark(concat, start + 1, end - 1);
            i = my_strlen(concat);
        }
        if (concat[i] == '\"') {
            check = 1;
            start = i;
        }
        i++;
    }
    if (check == 1) {
        free(concat);
        return NULL;
    }
    rmvcharac(concat, '\"');
    return concat;
}

char *rmv_thd(char const *concat, char *new, t_var_quotation_mark *var)
{
    while (var->i <= var->end) {
        if (concat[var->i + 1] == ';') {
            new[var->j++] = ';';
            var->i += 3;
        }
        new[var->j] = concat[var->i];
        var->i++;
        var->j++;
    }
    return new;
}

char *rmv_scd(char const *concat, char *new, t_var_quotation_mark *var)
{
    while (concat[var->i] != '\0') {
        if (var->start == var->i)
            new = rmv_thd(concat, new, var);
        new[var->j] = concat[var->i];
        var->j++;
        var->i++;
    }
    new[var->j] = '\0';
    return new;
}

char *rmv_quotation_mark(char *concat, int start, int end)
{
    t_var_quotation_mark *var = malloc(sizeof(t_var_quotation_mark));
    char *new = malloc(sizeof(char) * (my_strlen(concat) + 1));

    var->start = start;
    var->end = end;
    var->i = 0;
    var->j = 0;
    new = rmv_scd(concat, new, var);
    free(concat);
    concat = my_strdup(new);
    free(new);
    free(var);
    return concat;
}
