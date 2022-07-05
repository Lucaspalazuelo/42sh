/*
** EPITECH PROJECT, 2022
** alias_built_in.c
** File description:
** Created by louis on 22/02/2022.
*/

#include "my.h"

t_alias *init_alias(void)
{
    t_alias *node = malloc(sizeof(t_alias));
    node->next = NULL;
    return node;
}

t_alias *fill_alias_scd(t_alias *node, char **array, int i, int count_w)
{
    node->cmd = malloc(sizeof(char) * (count_w + i + 1));
    for (int j = 0; j < count_w; j++)
        node->cmd[j] = '\0';
    i = 2;
    while (array[i] != NULL) {
        my_strcat(node->cmd, array[i]);
        my_strcat(node->cmd, " ");
        i++;
    }
    return node;
}

int fill_alias_node(all_t *s_all, char **array)
{
    if (array[1] == NULL || array[2] == NULL)
        return 1;
    t_alias *node = malloc(sizeof(t_alias));
    node->name = my_strdup(array[1]);
    int i = 2, count_w = 0;
    while (array[i] != NULL) {
        count_w += my_strlen(array[i]);
        i++;
    }
    node = fill_alias_scd(node, array, i, count_w);
    node->next = s_all->s_alias;
    s_all->s_alias = node;
    return 0;
}

int is_alias_scd(t_alias *node, char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        if (my_strcmp_real(node->name, array[i]) == 0)
            return i;
        i++;
    }
    return -1;
}

int is_alias(all_t *s_all, char **array)
{
    int i;
    t_alias *node = s_all->s_alias;
    while (node->next != NULL) {
        if ((i = is_alias_scd(node, array)) != -1)
            return i;
        node = node->next;
    }
    return -1;
}
