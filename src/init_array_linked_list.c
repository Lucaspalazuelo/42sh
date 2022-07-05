/*
** EPITECH PROJECT, 2022
** array_in_linked_list.c
** File description:
** Created by louis on 21/02/2022.
*/

#include "my.h"

t_array *init_array(void)
{
    t_array *node = malloc(sizeof(t_array));
    node->array = NULL;
    node->next = NULL;
    return node;
}

void fill_array_linked_list(all_t *s_all, int start, int end, char **array)
{
    t_array *node = malloc(sizeof(t_node));
    int i = 0;

    node->array = malloc(sizeof(char *) * (end - start + 1));
    while (start < end) {
        node->array[i] = my_strdup(array[start]);
        i++;
        start++;
    }
    node->array[i] = NULL;
    node->next = s_all->s_array;
    s_all->s_array = node;
}

int what_is_separator(char *str)
{
    if (my_strcmp_real(str, ";") == 0
    || my_strcmp_real(str, "&&") == 0)
        return 1;
    return 0;
}

void put_array_in_linked_list(all_t *s_all, char **array)
{
    s_all->s_array = init_array();
    int i = 0;
    while (array[i] != NULL)
        i++;
    int max = i--;
    while (i >= 0) {
        if (what_is_separator(array[i]) == 1) {
            fill_array_linked_list(s_all, i + 1, max, array);
            max = i;
        }
        i--;
    }
    fill_array_linked_list(s_all, i + 1, max, array);
}
