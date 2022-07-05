/*
** EPITECH PROJECT, 2022
** exec_all.c
** File description:
** Created by louis on 12/01/2022.
*/

#include "my.h"

int is_built_in(char **array)
{
    int i = 0;
    char *cmd[] = {"cd", "pwd", "env",
    "setenv", "unsetenv",
    "alias", "repeat", "where", "which", NULL};
    while (cmd[i] != NULL) {
        if (array[0] != NULL && my_strcmp_real(cmd[i], array[0]) == 0)
            return 1;
        i++;
    }
    if (array[1] != NULL)
        if (my_strcmp_real("env", array[1]) == 0)
            return 1;
    return 0;
}

int exec_pwd(all_t *s_all)
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        my_printf("%s\n", cwd);
    else {
        perror("getcwd()");
        s_all->the_return = 1;
    }
    return 0;
}

int exec_built(all_t *s_all, char **array, char **envp)
{
    if (my_strcmp_real(array[0], "cd") == 0)
        return exec_cd(s_all, array, envp);
    if (my_strcmp_real(array[0], "pwd") == 0)
        return exec_pwd(s_all);
    if (my_strcmp_real(array[0], "setenv") == 0)
        return exec_setenv(s_all, array);
    if (my_strcmp_real(array[0], "unsetenv") == 0)
        return exec_unsetenv(s_all, array);
    if (my_strcmp_real(array[0], "alias") == 0)
        return fill_alias_node(s_all, array);
    if (my_strcmp_real(array[0], "env") == 0 && array[1] == NULL)
        return exec_env(s_all);
    if (my_strcmp_real(array[0], "repeat") == 0)
        return exec_repeat(s_all, array, envp);
    if (my_strcmp_real(array[0], "where") == 0)
        return exec_where(s_all, array, envp);
    if (my_strcmp_real(array[0], "which") == 0)
        return exec_which(s_all, array, envp);
    return 0;
}
