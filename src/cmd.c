/*
** EPITECH PROJECT, 2022
** cmd.c
** File description:
** Created by louis on 12/01/2022.
*/

#include "my.h"

char *my_getenv(char **env, const char *to_find)
{
    int idx = 0;
    char *elem = NULL;

    while (env != NULL && env[idx]) {
        if (!my_strncmp(env[idx], to_find, my_strlen(to_find)))
            elem = env[idx] + my_strlen(to_find);
        idx += 1;
    }
    return elem;
}

void abs_path_loop(char **path_split, char *bin, char **cmd, char *path)
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

int get_abs_path(char **envp, char **cmd, char *name)
{
    char *path = my_strdup(my_getenv(envp, "PATH"));
    char *bin = NULL;
    char **path_split = NULL;
    int ret;

    if (path == NULL)
        path = my_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
    if (cmd[0][0] != '/' && my_strncmp(cmd[0], "./", 2) != 0)
        abs_path_loop(path_split, bin, cmd, path);
    else if (cmd[0][0] != '/' && my_strncmp(cmd[0], "./", 2) == 0) {
        ret = my_fork(cmd, name, envp);
        free(path);
        path = NULL;
        return ret == 0 ? -1 : ret;
    }
    return 0;
}

void execute_cmd_scd(all_t *s_all, char **cmd, char *name, char **envp)
{
    if (execve(cmd[0], cmd, envp) == -1) {
        check_is_file(name) == 0 ?
        my_printf("%s: Command not found.\n", name) :
        my_printf("%s: Permission denied.\n", name);
        s_all->the_return = 1;
    }
    exit(EXIT_FAILURE);
}

void execute_cmd(all_t *s_all, char **cmd, char *name, char **envp)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == -1)
        perror("fork");
    else if (pid > 0) {
        waitpid(pid, &status, 0);
        kill(pid, SIGTERM);
    } else
        execute_cmd_scd(s_all, cmd, name, envp);
}
