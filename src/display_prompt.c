/*
** EPITECH PROJECT, 2022
** display_prompt.c
** File description:
** Created by louis on 04/04/2022.
*/

#include "my.h"

void choose_display(char **path, int i)
{
    if (path[0] == NULL) {
        my_printf(CYAN"/"YELLOW" ✗ "RESET);
        my_free_tab(path);
        return;
    }
    for (; path[i + 1] != NULL; i++);
    if (my_strcmp_real(path[i], "louis") == 0) {
        my_printf(CYAN "~ " RESET);
        my_free_tab(path);
        return;
    }
    my_printf(CYAN"%s"YELLOW" ✗ "RESET, path[i]);
    my_free_tab(path);
}

void display_special_prompt(all_t *s_all)
{
    if (isatty(0) != 1)
        return;
    char cwd[PATH_MAX];
    char **path;
    int i = 0;
    getcwd(cwd, sizeof(cwd));
    path = my_sp_str_to_word_array(cwd, "/");
    if (s_all->the_return == 0)
        my_printf(GREEN BOLD"➜  ");
    if (s_all->the_return != 0)
        my_printf(RED BOLD"➜  ");
    choose_display(path, i);
}
