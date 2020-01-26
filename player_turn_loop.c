/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** player_turn_loop
*/

#include "my.h"

int player_turn(map_t *m, pturn_t *p)
{
    p->str = NULL;
    p->len = 2;
    p->line = 0;
    p->match = 0;

    my_putstr("\nYour turn:\n");
    p->line = player_line(m, p);
    if (p->line == -6665)
        return (-6665);
    p->match = player_matches(m, p);
    if (p->match == -6665)
        return (-6665);
    my_putstr("Player removed ");
    my_putnbr(p->match);
    my_putstr(" match(es) from line ");
    my_putnbr(p->line);
    write(1, "\n", 1);
    return (0);
}
