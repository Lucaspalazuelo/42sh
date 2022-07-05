/*
** EPITECH PROJECT, 2021
** rmvchar.c
** File description:
** none
*/

void rmvcharac(char *str, char garbage)
{
    char *src;
    char *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage)
            dst++;
    }
    *dst = '\0';
}
