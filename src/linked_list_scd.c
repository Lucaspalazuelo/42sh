/*
** EPITECH PROJECT, 2022
** linked_list_scd.c
** File description:
** Created by louis on 12/01/2022.
*/

#include "my.h"

t_env *init_env(void)
{
    t_env *node = malloc(sizeof(t_env));
    node->next = NULL;
    return node;
}

void inverse_list(all_t *s_all)
{
    s_all->s_node = init_env();
    t_node *parse = s_all->node;
    while (parse->next != NULL) {
        t_env *fill = malloc(sizeof(t_env));
        if (parse->name != NULL)
            fill->name = my_strdup(parse->name);
        if (parse->path != NULL)
            fill->path = my_strdup(parse->path);
        fill->next = s_all->s_node;
        s_all->s_node = fill;
        parse = parse->next;
    }
}
