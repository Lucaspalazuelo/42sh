/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Created by louis on 10/01/2022.
*/

#include "my.h"

int main(int ac, char **av, char **envp)
{
    av[ac] = av[ac];
    all_t *s_all = malloc(sizeof(all_t));
    size_t size_buf = PATH_MAX;
    char **array = NULL;
    char *buffer = malloc(sizeof(char) * size_buf);
    int ret;
    many_initialisation(s_all, envp);
    display_special_prompt(s_all);
    while (getline(&buffer, &size_buf, stdin) > 0) {
        array = my_split(buffer, s_all);
        ret = start_mysh(s_all, array, envp);
        if (ret == 1)
            break;
        display_special_prompt(s_all);
    }
    return the_end(s_all, buffer);
}
