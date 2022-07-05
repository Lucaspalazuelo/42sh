/*
** EPITECH PROJECT, 2022
** start.c
** File description:
** Created by louis on 11/04/2022.
*/

#include "my.h"

int choose_command_scd(all_t *s_all, char **array, char **envp)
{
    int ret;

    if ((ret = is_exit(s_all, array)) != -1)
        return ret;
    if (the_pipe(s_all, array) == 0)
        return 0;
    if (redirection(s_all, array, envp) == 0)
        return 0;
    if (globbings(array) == 1) {
        do_globbings(array, search_globbings(array));
        return 0;
    }
    return -1;
}

int choose_command(all_t *s_all, char **array, char **envp)
{
    int ret;

    if ((ret = choose_command_scd(s_all, array, envp)) != -1)
        return ret;
    if (is_built_in(array) == 0) {
        char *new = array[0] != NULL ? my_strdup(array[0]) :  NULL;
        s_all->the_return = get_abs_path(envp, array, new);
        if (s_all->the_return == 0)
            execute_cmd(s_all, array, new, envp);
        if (s_all->the_return == -1)
            s_all->the_return = 0;
        free(new);
    } else
        exec_built(s_all, array, envp);
    return 0;
}

int start(all_t *s_all, char **array, char **envp)
{
    int is_break = 0;
    put_array_in_linked_list(s_all, array);
    t_array *node = s_all->s_array;
    while (node->next != NULL) {
        if (choose_command(s_all, node->array, envp) == 1) {
            is_break = 1;
            break;
        }
        node = node->next;
    }
    free_start(s_all);
    my_free_tab(array);
    return is_break;
}
