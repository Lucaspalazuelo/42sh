/*
** EPITECH PROJECT, 2022
** exec_which.c
** File description:
** Created by louis on 19/05/2022.
*/

#include "my.h"

void abs_path_loop_which(char **path_split, char *bin, char **cmd, char *path)
{
    path_split = my_sp_str_to_word_array(&path[1], ":");
    free(path);
    path = NULL;
    for (int i = 0; path_split[i] != NULL; i++) {
        bin = malloc(sizeof(char) *
                     (my_strlen(path_split[i]) + 1 + my_strlen(cmd[0]) + 1));
        if (bin == NULL)
            break;
        bin[0] = '\0';
        my_strcat(bin, path_split[i]);
        my_strcat(bin, "/");
        my_strcat(bin, cmd[0]);
        if (access(bin, F_OK) == 0)
            break;
        free(bin);
        bin = NULL;
    }
    my_free_tab(path_split);
    free(cmd[0]);
    cmd[0] = bin;
}

int get_abs_path_which(char **envp, char **cmd)
{
    char *path = my_strdup(my_getenv(envp, "PATH"));
    char *bin = NULL;
    char **path_split = NULL;

    if (path == NULL)
        path = my_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
    if (cmd[0][0] != '/' && my_strncmp(cmd[0], "./", 2) != 0)
        abs_path_loop_which(path_split, bin, cmd, path);
    else if (cmd[0][0] != '/' && my_strncmp(cmd[0], "./", 2) == 0) {
        free(path);
        path = NULL;
        return 1;
    }
    return 0;
}

int error_handling_which(char **array)
{
    if (my_count_tab(array) < 2) {
        my_printf("which: Too few arguments.\n");
        return 1;
    }
    return 0;
}

int exec_which(all_t *s_all, char **array, char **envp)
{
    char **tmp;
    char **tmp_built_in;

    if (error_handling_which(array) == 1) {
        s_all->the_return = 1;
        return 1;
    }
    for (int i = 1; array[i] != NULL; i++) {
        tmp = my_tab_cpy(&array[i]);
        tmp_built_in = my_tab_cpy(&array[i]);
        if (get_abs_path_which(envp, tmp) == 0 && tmp[0] != NULL)
            my_printf("%s\n", tmp[0]);
        else if (is_built_in(tmp_built_in) == 1)
            my_printf("%s: shell built-in command.\n", tmp_built_in[0]);
        my_free_tab(tmp);
        my_free_tab(tmp_built_in);
    }
    return 0;
}
