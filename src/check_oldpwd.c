/*
** EPITECH PROJECT, 2022
** check_oldpwd.c
** File description:
** Created by louis on 05/05/2022.
*/

#include "my.h"

void check_oldpwd(all_t *s_all)
{
    t_node *check = s_all->node;
    int yep = 0;
    char cwd[PATH_MAX];
    char *array[] = {NULL, "OLDPWD", getcwd(cwd, sizeof(cwd)), NULL};
    while (check->next != NULL) {
        if (my_strcmp_real("OLDPWD", check->name) == 0)
            yep = 1;
        check = check->next;
    }
    if (yep == 0)
        exec_setenv(s_all, array);
}
