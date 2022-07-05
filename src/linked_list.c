/*
** EPITECH PROJECT, 2022
** linked_list.c
** File description:
** Created by louis on 12/01/2022.
*/

#include "my.h"

t_node *init_node(void)
{
    t_node *node = malloc(sizeof(t_node));
    node->next = NULL;
    return node;
}

void fill_list(all_t *s_all, char *name, char *path)
{
    t_node *node = malloc(sizeof(t_node));
    if (name != NULL)
        node->name = my_strdup(name);
    else
        node->name = NULL;
    if (path != NULL)
        node->path = my_strdup(path);
    else
        node->path = NULL;
    node->next = s_all->node;
    s_all->node = node;
}

void make_good_path_name(all_t *s_all, char **envp)
{
    int count = 0;
    int len_path = s_all->end - s_all->stop;
    char *path = malloc(sizeof(char) * (len_path + 1));
    char *name = malloc(sizeof(char) * s_all->stop + 1);
    for (; count < s_all->stop; count++)
        name[count] = envp[s_all->i][count];
    name[count] = '\0';
    for (count = 0; count < len_path; count++) {
        path[count] = envp[s_all->i][count + s_all->stop + 1];
    }
    path[count] = '\0';
    fill_list(s_all, name, path);
    free(path);
    free(name);
}

void check_en_loop(all_t *s_all, char **envp)
{
    s_all->j = 0;
    int lock = 0;
    while (envp[s_all->i][s_all->j] != '\0') {
        if (envp[s_all->i][s_all->j] == '=' && lock == 0) {
            s_all->stop = s_all->j;
            s_all->j++;
            lock = 1;
        }
        s_all->j++;
    }
    s_all->end = s_all->j;
    make_good_path_name(s_all, envp);
}

void check_env(all_t *s_all, char **envp)
{
    s_all->node = init_node();
    s_all->i = 0;
    while (envp[s_all->i] != NULL) {
        check_en_loop(s_all, envp);
        s_all->i++;
    }
}
