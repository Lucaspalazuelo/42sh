/*
** EPITECH PROJECT, 2022
** exec_inverse_redirections.c
** File description:
** Created by louis on 11/05/2022.
*/

#include "my.h"

void inverse_redir(char **array)
{
    char *new_buffer = NULL;
    int i;
    int len = 0;

    for (i = 0; array[i] != NULL ; i++)
        len += my_strlen(array[i]);
    new_buffer = calloc((len + i + 1), sizeof(char));
    for (int j = 0; array[j] != NULL; j++) {
        my_strcat(new_buffer, array[j]);
        my_strcat(new_buffer, " ");
    }
    system(new_buffer);
    free(new_buffer);
}
