/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my_putnbr
*/

#include "my.h"

int my_putnbr(int nb)
{
    char a = nb + 48;
    char b = nb % 10 + 48;

    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
    } else if (nb > 9) {
        my_putnbr(nb / 10);
        write(1, &b, 1);
    } else
        write(1, &a, 1);
    return (0);
}
