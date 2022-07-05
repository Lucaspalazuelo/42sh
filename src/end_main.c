/*
** EPITECH PROJECT, 2022
** end_main.c
** File description:
** Created by louis on 21/01/2022.
*/

#include "my.h"

void delete_node(all_t *s_all, t_node *nodetodelete)
{
    t_node *currentnode = s_all->node;
    t_node *previousnode = NULL;
    while (currentnode != NULL) {
        if (currentnode != nodetodelete) {
            previousnode = currentnode;
            currentnode = currentnode->next;
            continue;
        }
        if (previousnode)
            previousnode->next = nodetodelete->next;
        else
            s_all->node = nodetodelete->next;
        free(nodetodelete->name);
        if (nodetodelete->path != NULL)
            free(nodetodelete->path);
        free(nodetodelete);
        break;
    }
}

void delete_env(all_t *s_all, t_env *nodetodelete)
{
    t_env *currentnode = s_all->s_node;
    t_env *previousnode = NULL;
    while (currentnode != NULL) {
        if (currentnode != nodetodelete) {
            previousnode = currentnode;
            currentnode = currentnode->next;
            continue;
        }
        if (previousnode)
            previousnode->next = nodetodelete->next;
        else
            s_all->s_node = nodetodelete->next;
        free(nodetodelete->name);
        if (nodetodelete->path != NULL)
            free(nodetodelete->path);
        free(nodetodelete);
        break;
    }
}

void delete_alias(all_t *s_all, t_alias *nodetodelete)
{
    t_alias *currentnode = s_all->s_alias;
    t_alias *previousnode = NULL;
    while (currentnode != NULL) {
        if (currentnode != nodetodelete) {
            previousnode = currentnode;
            currentnode = currentnode->next;
            continue;
        }
        if (previousnode)
            previousnode->next = nodetodelete->next;
        else
            s_all->s_alias = nodetodelete->next;
        if (nodetodelete->name != NULL)
            free(nodetodelete->name);
        if (nodetodelete->cmd != NULL)
            free(nodetodelete->cmd);
        free(nodetodelete);
        break;
    }
}

int the_end(all_t *s_all, char *buffer)
{
    int the_return = s_all->the_return != 0 ? 1 : 0;
    if (isatty(0) == 1)
        my_printf("exit\n");
    while (s_all->node->next != NULL)
        delete_node(s_all, s_all->node);
    free(s_all->node);
    while (s_all->s_alias->next != NULL)
        delete_alias(s_all, s_all->s_alias);
    free(s_all->s_alias);
    if (buffer != NULL)
        free(buffer);
    free(s_all);
    return the_return;
}
