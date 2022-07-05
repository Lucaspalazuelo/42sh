/*
** EPITECH PROJECT, 2022
** start.c
** File description:
** Created by louis on 08/04/2022.
*/

#include "my.h"

char **start_with_alias(all_t *s_all, char **array, int count)
{
    t_alias *alias = s_all->s_alias;
    while (alias->next != NULL) {
        if (my_strcmp_real(alias->name, array[count]) == 0)
            break;
        alias = alias->next;
    }
    my_free_tab(array);
    array = my_split(alias->cmd, s_all);
    return array;
}

int start_mysh(all_t *s_all, char **array, char **envp)
{
    if (array == NULL || array[0] == NULL) {
        my_free_tab(array);
        return 2;
    }
    int count = is_alias(s_all, array);
    if (count != -1) {
        array = start_with_alias(s_all, array, count);
        if (start(s_all, array, envp) == 1)
            return 1;
    } else if (start(s_all, array, envp) == 1)
        return 1;
    return 0;
}
