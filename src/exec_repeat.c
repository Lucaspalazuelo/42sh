/*
** EPITECH PROJECT, 2022
** exec_repeat.c
** File description:
** Created by louis on 18/05/2022.
*/

#include "my.h"

int error_handling_repeat(char **array)
{
    if (my_count_tab(array) < 3) {
        my_printf("repeat: Too few arguments.\n");
        return 1;
    }
    if (my_isnum(array[1]) == 1) {
        my_printf("repeat: Badly formed number.\n");
        return 1;
    }
    return 0;
}

int exec_repeat(all_t *s_all, char **array, char **envp)
{
    int i = 0;
    char **tmp;

    if (error_handling_repeat(array) == 1) {
        s_all->the_return = 1;
        return 1;
    }
    while (i < my_atoi(array[1])) {
        tmp = my_tab_cpy(array);
        choose_command(s_all, &tmp[2], envp);
        my_free_tab(tmp);
        i++;
    }
    return 0;
}