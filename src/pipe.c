/*
** EPITECH PROJECT, 2022
** pipe.c
** File description:
** Created by louis on 26/04/2022.
*/

#include "my.h"

int is_pipe(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (my_strcmp_real(array[i], "|") == 0)
            return i;
    }
    return -1;
}

int the_pipe(all_t *s_all, char **array)
{
    char *new_buffer = NULL;
    int i, len = 0, ret;

    if ((ret = is_pipe(array)) == -1)
        return -1;
    if (array[ret + 1] == NULL) {
        my_printf("Invalid null command.\n");
        s_all->the_return = 1;
        return 0;
    }
    for (i = 0; array[i] != NULL ; i++)
        len += my_strlen(array[i]);
    new_buffer = calloc((len + i + 1), sizeof(char));
    for (int j = 0; array[j] != NULL; j++) {
        my_strcat(new_buffer, array[j]);
        my_strcat(new_buffer, " ");
    }
    system(new_buffer);
    free(new_buffer);
    return 0;
}
