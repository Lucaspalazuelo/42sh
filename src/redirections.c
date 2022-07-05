/*
** EPITECH PROJECT, 2022
** redirections.c
** File description:
** Created by louis on 21/04/2022.
*/

#include "my.h"

int is_redirection(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (my_strcmp_real(array[i], "<") == 0
        || my_strcmp_real(array[i], "<<") == 0
        || my_strcmp_real(array[i], ">") == 0
        || my_strcmp_real(array[i], ">>") == 0)
            return i;
    }
    return -1;
}

int what_redirection(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (my_strcmp_real(array[i], ">") == 0)
            return 1;
        if (my_strcmp_real(array[i], ">>") == 0)
            return 2;
        if (my_strcmp_real(array[i], "<") == 0)
            return 3;
        if (my_strcmp_real(array[i], "<<") == 0)
            return 4;
    }
    return -1;
}

void check_file_exist(all_t *s_all, int i, char **array, char **envp)
{
    int fd;
    char **cmd;
    char *redirection;
    struct stat s;

    cmd = my_tab_cpy(array);
    redirection = my_strdup(array[i + 1]);
    cmd[i] = NULL;
    if ((fd = open(redirection, O_RDONLY)) == -1) {
        char *touch[] = {"/usr/bin/touch", redirection, NULL};
        execute_cmd(s_all, touch, NULL, envp);
    } else {
        stat(redirection, &s);
        s_all->read_file = malloc(sizeof(char) * (s.st_size + 1));
        read(fd, s_all->read_file, s.st_size);
        s_all->read_file[s.st_size] = '\0';
    }
    close(fd);
    free(redirection);
    my_free_tab(cmd);
}

void choose_redirection(all_t *s_all, char **array, char **envp, t_redir r)
{
    if (r.direction == 1) {
        check_file_exist(s_all, r.i, array, envp);
        exec_redirection(s_all, r.cmd, envp, r.redirection);
        s_all->read_file != NULL ? free(s_all->read_file), s_all->read_file
        = NULL : 0;
    }
    if (r.direction == 2) {
        check_file_exist(s_all, r.i, array, envp);
        double_redirection(s_all, r.cmd, envp, r.redirection);
    }
    if (r.direction == 3 || r.direction == 4)
        inverse_redir(r.cmd);
}

int redirection(all_t *s_all, char **array, char **envp)
{
    t_redir r;

    if ((r.i = is_redirection(array)) == -1)
        return 1;
    r.cmd = my_tab_cpy(array);
    r.cmd[r.i] = NULL;
    if (array[r.i + 1] == NULL) {
        my_printf("Missing name for redirect.\n");
        my_free_tab(r.cmd);
        s_all->the_return = 1;
        return 0;
    }
    r.redirection = my_strdup(array[r.i + 1]);
    r.direction = what_redirection(array);
    choose_redirection(s_all, array, envp, r);
    free(r.redirection);
    my_free_tab(r.cmd);
    return 0;
}
