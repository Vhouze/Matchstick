/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char *str)
{
    int a = 0;

    while (str[a])
        a++;
    return (a);
}
