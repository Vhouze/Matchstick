/*
** EPITECH PROJECT, 2019
** matchsticks
** File description:
** ai turn
*/

#include "my.h"

void ai_rand_line(map_t *m, pturn_t *p, int *tab)
{
    tab = check_last_pipe(m);
    if (tab[1] >= 2) {
        if (check_stick(m, p) == 0 || p->line == 0) {
            p->line = rand() % m->nb;
            ai_rand_line(m, p, tab);
        }
    }
    else {
        tab = check_last_pipe(m);
        p->line = tab[0];
    }
}

void ai_rand_matches(map_t *m, pturn_t *p, int x, int *tab)
{
    tab = check_last_pipe(m);
    if (tab[1] != 1) {
        while (p->match > p->max_sticks && p->match > check_stick(m, p))
            p->match = rand() % x + 1;
        while (p->match > p->max_sticks || p->match > check_stick(m, p))
            p->match += -1;
        if (p->match < 0)
            ai_rand_matches(m, p, x, tab);
    }
    else {
        if (check_stick(m, p) <= p->max_sticks)
            p->match = check_stick(m, p) - 1;
        else if (check_stick(m, p) - 1 == p->max_sticks)
            p->match = p->max_sticks;
        else
            p->match = 1;
    }
    if (p->match == 0)
        p->match = 1;
}

int ai_turn(map_t *m, pturn_t *p)
{
    int x = countsticks(m);
    int *tab = check_last_pipe(m);

    p->line = rand() % m->nb;
    ai_rand_line(m, p, tab);
    p->match = rand() % x;
    ai_rand_matches(m, p, x, tab);
    my_putstr("\nAI's turn...\nAI removed ");
    my_putnbr(p->match);
    my_putstr(" match(es) from line ");
    my_putnbr(p->line);
    write(1, "\n", 1);
    free(tab);
    return (0);
}
