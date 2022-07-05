/*
** EPITECH PROJECT, 2022
** free_start.c
** File description:
** Created by louis on 21/04/2022.
*/

#include "my.h"

void free_linked_list_array(all_t *s_all, t_array *nodetodelete)
{
    t_array *currentnode = s_all->s_array;
    t_array *previousnode = NULL;
    while (currentnode != NULL) {
        if (currentnode != nodetodelete) {
            previousnode = currentnode;
            currentnode = currentnode->next;
            continue;
        }
        if (previousnode)
            previousnode->next = nodetodelete->next;
        else
            s_all->s_array = nodetodelete->next;
        my_free_tab(nodetodelete->array);
        free(nodetodelete);
        break;
    }
}

void free_start(all_t *s_all)
{
    while (s_all->s_array->next != NULL)
        free_linked_list_array(s_all, s_all->s_array);
    free(s_all->s_array);
}
