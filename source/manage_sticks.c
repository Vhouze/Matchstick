/*
** EPITECH PROJECT, 2019
** matchsticks
** File description:
** manage sticks
*/

#include "my.h"

int countsticks_loop(map_t *m, int line, int column, int count)
{
    if (m->tab[line][column] == '|')
        count++;
    return (count);
}

int countsticks(map_t *m)
{
    int line = 0;
    int column = 0;
    int count = 0;

    while (m->tab[line]) {
        while (m->tab[line][column]) {
            count = countsticks_loop(m, line, column, count);
            column++;
        }
        column = 0;
        line++;
    }
    return (count);
}

int check_stick(map_t *m, pturn_t *p)
{
    int a = 0;
    int column = 0;

    while (m->tab[p->line][column]) {
        if (m->tab[p->line][column] == '|')
            a++;
        column++;
    }
    return (a);
}

int check_last_stick(map_t *m, pturn_t *p)
{
    int max = my_strlen(m->tab[p->line]);

    while (m->tab[p->line][max] != '|')
        max--;
    return (max);
}

char **delete_stick(map_t *m, pturn_t *p)
{
    int last = check_last_stick(m, p);

    while (p->match > 0) {
        m->tab[p->line][last] = ' ';
        last--;
        p->match--;
    }
    return (m->tab);
}
