/*
** EPITECH PROJECT, 2022
** simple_redirection.c
** File description:
** Created by louis on 26/04/2022.
*/

#include "my.h"

void redirection_scd(all_t *s_all, char **cmd, char **envp, char *redirection)
{
    int tempout;
    FILE *temp;
    int oldout;

    temp = fopen(redirection, "wb");
    fclose(temp);
    tempout = open(redirection, O_WRONLY);
    oldout = dup(2);
    close(oldout);
    close(1);
    dup(tempout);
    choose_command(s_all, cmd, envp);
    close(tempout);
    close(2);
    exit(EXIT_SUCCESS);
}

void exec_redirection(all_t *s_all, char **cmd, char **envp, char *redirection)
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
        redirection_scd(s_all, cmd, envp, redirection);
}
