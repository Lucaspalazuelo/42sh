/*
** EPITECH PROJECT, 2022
** check_is_file.c
** File description:
** Created by louis on 27/01/2022.
*/

#include "my.h"

int check_is_file(char *name)
{
    if (name[0] != '.' && name[1] != '/')
        return 0;
    struct stat buf;
    stat(&name[2], &buf);
    if (S_ISDIR(buf.st_mode) == 1 || S_ISREG(buf.st_mode) == 1)
        return 1;
    return 0;
}
