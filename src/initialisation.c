/*
** EPITECH PROJECT, 2022
** initialisation.c
** File description:
** Created by louis on 05/05/2022.
*/

#include "my.h"

void many_initialisation(all_t *s_all, char **envp)
{
    s_all->s_alias = init_alias();
    s_all->the_return = 0;
    s_all->read_file = NULL;
    check_env(s_all, envp);
    check_oldpwd(s_all);
}
