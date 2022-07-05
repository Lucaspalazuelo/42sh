/*
** EPITECH PROJECT, 2022
** my_fork.c
** File description:
** Created by louis on 26/04/2022.
*/

#include "my.h"

int my_puterror(char *str, int nb, int ret)
{
    if (str == NULL)
        return 0;
    write(nb, str, my_strlen(str));
    return ret;
}

int manage_return(int status)
{
    int nb;

    nb = WEXITSTATUS(status);
    if (WIFSIGNALED(status)) {
        if (status == SEGFAULT || status == 11)
            nb = my_puterror("Segmentation fault", 2, SEGFAULT);
        if (status == ABORT || status == 8)
            nb = my_puterror("Floating exception", 2, ABORT);
        if (status == FLOAT || status == 9)
            nb = my_puterror("Abort", 2, FLOAT);
        if (WCOREDUMP(status))
            my_printf(" (core dumped)");
        my_printf("\n");
        return nb;
    }
    return nb == FAIL ? -2 : nb;
}

int my_dad(void)
{
    int nb;
    int status;

    wait(&status);
    nb = manage_return(status);
    return nb;
}

void my_son(char **my_tab, char **my_envp, char *str)
{
    if (execve(str, my_tab, my_envp) == -1) {
        check_is_file(str) == 0 ?
        my_printf("%s: Command not found.\n", str) :
        my_printf("%s: Permission denied.\n", str);
    }
    exit(FAIL);
}

int my_fork(char **my_tab, char *str, char **envp)
{
    int f;
    int nb;

    nb = 1;
    f = fork();
    if (f == -1)
        return (ERROR);
    else if (f != 0) {
        nb = my_dad();
    } else
        my_son(my_tab, envp, str);
    return nb;
}
