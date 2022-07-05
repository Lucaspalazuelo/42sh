/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** none
*/

char *my_strncpy(char *dest, const char *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
