/*
** EPITECH PROJECT, 2022
** double_redirection.c
** File description:
** Created by louis on 09/05/2022.
*/

#include "my.h"

void double_redir_scd(all_t *s_all, char **cmd, char **envp, char *redirection)
{
    int tempout;
    int oldout;

    tempout = open(redirection, O_WRONLY);
    oldout = dup(2);
    close(oldout);
    close(1);
    dup(tempout);
    if (s_all->read_file != NULL) {
        my_printf("%s", s_all->read_file);
        free(s_all->read_file);
    }
    choose_command(s_all, cmd, envp);
    close(tempout);
    close(2);
    exit(EXIT_SUCCESS);
}

void double_redirection(all_t *s_all, char **cmd, char **envp,
                        char *redirection)
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
        double_redir_scd(s_all, cmd, envp, redirection);
}
