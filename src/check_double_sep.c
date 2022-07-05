/*
** EPITECH PROJECT, 2022
** check_double_sep.c
** File description:
** Created by louis on 16/05/2022.
*/

#include "my.h"

int check_if_null_cmd(char **array)
{
    int i = 0;

    while (array[i] != NULL && array[i + 1] != NULL) {
        if (my_strcmp_real(array[i], "&&") == 0
        && my_strcmp_real(array[i + 1], "&&") == 0) {
            my_printf("Invalid null command.\n");
            return 1;
        }
        i++;
    }
    return 0;
}

void double_sep_start(all_t *s_all, char **array)
{
    int i = 0;

    if (array[0] == NULL)
        return;
    while (my_strcmp_real(array[0], "&&") == 0) {
        while (array[i] != NULL && array[i + 1] != NULL) {
            free(array[i]);
            array[i] = my_strdup(array[i + 1]);
            i++;
        }
        array[i] = NULL;
        i = 0;
    }
    s_all->the_return = check_if_null_cmd(array);
}
