/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** player_turn
*/

#include "my.h"

int player_line(map_t *m, pturn_t *p)
{
    int z = 0;

    my_putstr("Line: ");
    if (getline(&p->str, &p->len, stdin) == -1)
        return (-6665);
    p->line = my_getnbr(p->str);
    if ((p->line < 1 && p->line != -5555 && p->line != -5554) ||
        p->line > m->nb) {
        my_putstr("Error: this line is out of range\n");
        z = player_line(m, p);
        if (z == -6665)
            return (-6665);
    } if (p->line == -5554) {
        my_putstr("Error: invalid input (positive number expected)\n");
        z = player_line(m, p);
        if (z == -6665)
            return (-6665);
    }
    p->line = my_getnbr(p->str);
    return (p->line);
}

int player_matches_fourth(map_t *m, pturn_t *p)
{
    int z = 0;

    if (p->match == -5554) {
        my_putstr("Error: invalid input (positive number expected)\n");
        z = player_line(m, p);
        if (z == -6665)
            return (-6665);
        z = player_matches(m, p);
        if (z == -6665)
            return (-6665);
    } if (p->match > check_stick(m, p) && p->match != -6665) {
        my_putstr("Error: not enough matches on this line\n");
        z = player_line(m, p);
        if (z == -6665)
            return (-6665);
        z = player_matches(m, p);
        if (z == -6665)
            return (-6665);
    }
    return (0);
}

int player_matches_third(map_t *m, pturn_t *p)
{
    int z = 0;

    if (p->match < 1 && p->match != -5554 && p->match != -5555) {
        my_putstr("Error: you have to remove at least one match\n");
        z = player_line(m, p);
        if (z == -6665)
            return (-6665);
        z = player_matches(m, p);
        if (z == -6665)
            return (-6665);
    }
    return (0);
}

int player_matches_second(map_t *m, pturn_t *p)
{
    int z = 0;

    if (p->match > p->max_sticks) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(p->max_sticks);
        my_putstr(" matches per turn\n");
        z = player_line(m, p);
        if (z == -6665)
            return (-6665);
        z = player_matches(m, p);
        if (z == -6665)
            return (-6665);
    }
    return (0);
}

int player_matches(map_t *m, pturn_t *p)
{
    int z = 0;

    my_putstr("Matches: ");
    if (getline(&p->str, &p->len, stdin) == -1)
        return (-6665);
    p->match = my_getnbr(p->str);
    z = player_matches_second(m, p);
    if (z == -6665)
        return (-6665);
    z = player_matches_third(m, p);
    if (z == -6665)
        return (-6665);
    z = player_matches_fourth(m, p);
    if (z == -6665)
        return (-6665);
    else {
        p->match = my_getnbr(p->str);
        return (p->match);
    }
}
