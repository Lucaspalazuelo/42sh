/*
** EPITECH PROJECT, 2022
** globbings.c
** File description:
** globbings
*/

#include "my.h"

int is_globbing(char c)
{
    if (c == '[' || c == ']' || c == '*' || c == '?')
        return 1;
    return 0;
}

int globbings_scd(char **array, int i)
{
    for (int j = 0; array[i][j] != '\0'; j++)
        if (is_globbing(array[i][j]) == 1 && array[i][0] != '"'
            && array[i][0] != '\'')
            return 1;
    return 0;
}

int globbings(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        if (globbings_scd(array, i) != 0)
            return 1;
    return 0;
}

void fork_for_globbing(char *command)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == -1)
        perror("fork");
    else if (pid > 0) {
        waitpid(pid, &status, 0);
        kill(pid, SIGTERM);
    } else {
        system(command);
        exit(EXIT_SUCCESS);
    }
    free(command);
}

void do_globbings(char **array, int nb)
{
    char *command = NULL;

    for (int i = 0; i != nb + 1; i++) {
        command = malloc(sizeof(char) * PATH_MAX);
        for (int j = 0; j != nb + 1; j++) {
            strcat(command, array[j]);
            strcat(command, " ");
        }
    }
    fork_for_globbing(command);
}
