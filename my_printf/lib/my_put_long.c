/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** confirm
*/

void my_putchar(char c);

int my_put_long(long nb)
{
    long mod;
    long nb_2 = nb;

    if (nb_2 < 0) {
        my_putchar('-');
        nb_2 = nb_2 * (-1);
    }
    if (nb_2 >= 0) {
        if (nb_2 >= 10) {
            mod = (nb_2 % 10);
            nb_2 = (nb_2 - mod) / 10;
            my_put_long(nb_2);
            my_putchar(mod + 48);
        } else
            my_putchar(48 + nb_2 % 10);
    }
    return 0;
}
