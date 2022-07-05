/*
** EPITECH PROJECT, 2022
** builtins.c
** File description:
** Created by louis on 17/01/2022.
*/

#include "my.h"

int exec_unsetenv(all_t *s_all, char **array)
{
    if (array[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        s_all->the_return = 1;
        return 0;
    }
    if (my_strcmp_real("PWD", array[1]) == 0
    || my_strcmp_real("OLDPWD", array[1]) == 0)
        return 1;
    t_node *delete = s_all->node;
    while (delete->next != NULL) {
        if (my_strcmp_real(delete->name, array[1]) == 0) {
            delete_node(s_all, delete);
            return 1;
        }
        delete = delete->next;
    }
    return 0;
}
