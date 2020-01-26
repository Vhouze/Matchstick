/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char *t)
{
    int res = 0;
    int a = 0;
    int b = 0;
    int x = 0;

    while (((t[b] > 47 && t[b] < 58) || t[b] == 45 || t[b] == 43) && t[b]) {
        if (t[b] >= 48 && t[b] <= 57) {
            res = (((t[b] - 48) + res * 10));
            x++;
        } if (t[b] == 45)
            a++;
        b++;
    }
    if (a % 2 == 1)
        res = res * (-1);
    if (x == 0)
        res = -5554;
    return (res);
}
