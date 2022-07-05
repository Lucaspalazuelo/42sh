/*
** EPITECH PROJECT, 2022
** builtin_env.c
** File description:
** Created by louis on 17/01/2022.
*/

#include "my.h"

char *my_getenv_in_list(all_t *s_all, char *to_find)
{
    t_node *find = s_all->node;
    while (find->next != NULL) {
        if (my_strcmp_real(find->name, to_find) == 0)
            return my_strdup(find->path);
        find = find->next;
    }
    return NULL;
}

void changing_pwd(all_t *s_all, char *oldpwd)
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    t_node *find = s_all->node;

    while (find->next != NULL) {
        if (my_strcmp_real(find->name, "PWD") == 0) {
            find->path == NULL ? 0 : free(find->path);
            find->path = NULL;
            find->path = my_strdup(cwd);
        }
        if (my_strcmp_real(find->name, "OLDPWD") == 0) {
            find->path == NULL ? 0 : free(find->path);
            find->path = NULL;
            find->path = my_strdup(oldpwd);
        }
        find = find->next;
    }
}

int exec_env(all_t *s_all)
{
    inverse_list(s_all);
    t_env *display = s_all->s_node;
    while (display->next != NULL) {
        if (display->name != NULL)
            my_printf("%s=", display->name);
        if (display->path != NULL)
            my_printf("%s\n", display->path);
        else
            my_printf("\n");
        display = display->next;
    }
    while (s_all->s_node->next != NULL)
        delete_env(s_all, s_all->s_node);
    free(s_all->s_node);
    return 0;
}
