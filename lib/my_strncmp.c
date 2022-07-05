/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** Created by louis on 12/01/2022.
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
        i = i + 1;
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return (0);
    else if (s1[i] > s2[i])
        return (1);
    else
        return (-1);
}
