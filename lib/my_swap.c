/*
** EPITECH PROJECT, 2021
** my swap
** File description:
** swap values in c
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void my_swap(int *a, int *b)
{
    int i = *a;
    *a = *b;
    *b = i;
}
