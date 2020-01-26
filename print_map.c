/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** print map
*/

#include "my.h"

void print_map(map_t *m)
{
    for (int a = 0; m->tab[a]; a++) {
        my_putstr(m->tab[a]);
        write(1, "\n", 1);
    }
}
