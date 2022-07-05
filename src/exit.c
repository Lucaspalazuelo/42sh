/*
** EPITECH PROJECT, 2022
** exit.c
** File description:
** Created by louis on 11/05/2022.
*/

#include "my.h"

int is_exit(all_t *s_all, char **array)
{
    if (array[0] != NULL && my_strcmp_real(array[0], "exit") == 0) {
        if (array[1] != NULL && my_isnum(array[1]) == 1) {
            s_all->the_return = 1;
            my_printf("exit: Expression Syntax.\n");
            return 0;
        }
    }
    if (array[0] != NULL && my_strcmp_real(array[0], "exit") == 0) {
        s_all->the_return = array[1] == NULL ? 0 : my_atoi(array[1]);
        return 1;
    }
    s_all->the_return = 0;
    return -1;
}
