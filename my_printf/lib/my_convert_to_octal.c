/*
** EPITECH PROJECT, 2021
** my_convert_to_octal.c
** File description:
** Created by louis on 16/11/2021.
*/

int convert_octal(int dec)
{
    int octal = 0;
    int i = 1;

    while (dec != 0) {
        octal += (dec % 8) * i;
        dec /= 8;
        i *= 10;
    }
    return (octal);
}
