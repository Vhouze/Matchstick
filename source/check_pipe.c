/*
** EPITECH PROJECT, 2019
** matchsticks
** File description:
** checkpipe
*/

#include "my.h"

int *check_last_pipe(map_t *m)
{
    int *tab = malloc(sizeof(int) * 3);
    int line = 0;
    int count = 0;
    int count2 = 0;
    int column = 0;
    int tmp = 0;

    while (m->tab[line]) {
        while (m->tab[line][column]) {
            if (m->tab[line][column] == '|') {
                count = line;
                count2 = count;
            }
            column++;
        }
        column = 0;
        line++;
        if (count2 != 0)
            tmp++;
        count2 = 0;
    }
    tab[0] = count;
    tab[1] = tmp;
    tab[2] = '\0';
    return (tab);
}
