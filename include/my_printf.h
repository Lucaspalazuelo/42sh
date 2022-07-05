/*
** EPITECH PROJECT, 2021
** my_printf.h
** File description:
** none
*/

#ifndef _MY_H
    #define _MY_H

    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include "my.h"

typedef struct var {
    char *str;
    int nbr;
    int index;
    int lock;
    int lock2;
    int i;
}var_t;

int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char *src);
void rmvcharac(char *str, char garbage);
int my_put_nbr(int nb);
int my_put_long(long nb);
char *my_revstr(char *str);
int my_getnbr(char *str);
char *my_strdup(char const *src);
char *my_sp_strcpy(char const *str, int i);
char *int_to_char(long result);
int convert_octal(int dec);
int my_put_float(double nbr);
int my_putnbr_base(int nbr, char const *base);
void my_print_digit(char *arg, va_list ap, var_t *var);
void my_print_string(char *arg, va_list ap, var_t *var);
void my_print_char(char *arg, va_list ap, var_t *var);
void my_print_octal(char *arg, va_list ap, var_t *var);
void my_print_long(char *arg, va_list ap, var_t *var);
void my_print_hexa_x(char *arg, va_list ap, var_t *var);
void my_print_hexa_big_x(char *arg, va_list ap, var_t *var);
void my_printf(char *str, ...);
void manage_space(long nb, var_t *var);
void manage_space_str(char *str, var_t *var);
void my_special_print_string(char *arg, va_list ap, var_t *var);
int index_function(char const *str, int i);
void space_after(long nb, var_t *var);
void manage_space_after_hexa(long nb, var_t *var);

#endif
