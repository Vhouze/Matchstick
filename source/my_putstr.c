/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char *str)
{
    int a = 0;

    while (str[a]) {
        write(1, &str[a], 1);
        a++;
    }
    return (0);
}
