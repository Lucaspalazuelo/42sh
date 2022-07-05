/*
** EPITECH PROJECT, 2022
** setenv.c
** File description:
** Created by louis on 17/01/2022.
*/

#include "my.h"

int error_handling_setenv(char const *name)
{
    int i = 0;
    while (name[i] != '\0') {
        if (is_alpha_num(name[i]) == 0) {
            my_printf("setenv: Variable name "
            "must contain alphanumeric characters.\n");
            return 1;
        }
        i++;
    }
    return 0;
}

int error_handling_setenv_scd(all_t *s_all, char **array)
{
    if (array[1] == NULL) {
        exec_env(s_all);
        return 1;
    } else if (error_handling_setenv(array[1]) == 1)
        return 1;
    if (array[2] == NULL) {
        fill_list(s_all, array[1], NULL);
        return 1;
    } else if (array[3] != NULL) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    } else {
        if (my_char_is_alpha(array[1][0]) == 1) {
            my_printf("setenv: Variable name must begin with a letter.\n");
            return 1;
        }
    }
    return 0;
}

int while_setenv(all_t *s_all, char **array)
{
    t_node *check = s_all->node;
    int lock = 0;
    while (s_all->node->next != NULL) {
        if (my_strcmp_real(array[1], s_all->node->name) == 0) {
            lock = 1;
            break;
        }
        s_all->node = s_all->node->next;
    }
    if (lock == 1 && s_all->node->path != NULL)
        free(s_all->node->path);
    if (lock == 1)
        s_all->node->path = my_strdup(array[2]);
    s_all->node = check;
    return lock;
}

int exec_setenv(all_t *s_all, char **array)
{
    int lock;

    if (error_handling_setenv_scd(s_all, array) == 1) {
        s_all->the_return = 1;
        return 1;
    }
    lock = while_setenv(s_all, array);
    if (array[1] != NULL && array[2] != NULL && array[3] == NULL && lock == 0)
        fill_list(s_all, array[1], array[2]);
    return 0;
}
