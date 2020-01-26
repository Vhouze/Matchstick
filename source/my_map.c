/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my_map
*/

#include "my.h"

void my_init_tab(map_t *m)
{
    if (m->line == 0 || m->line == m->nb + 1 ||
        m->column == 0 || m->column == m->nb * 2)
        m->tab[m->line][m->column] = '*';
    else {
        if (m->column >= m->nb - m->x && m->column <= m->nb + m->x)
            m->tab[m->line][m->column] = '|';
        else
            m->tab[m->line][m->column] = ' ';
    }
    m->column += 1;
}

char **my_tab(map_t *m)
{
    m->line = 0;
    m->column = 0;
    m->x = -1;
    m->tab = malloc(sizeof(char *) * (m->nb + 3));

    while (m->line < m->nb + 3) {
        m->tab[m->line] = malloc(sizeof(char) * (m->nb * 2 + 2));
        while (m->column != m->nb * 2 + 1)
            my_init_tab(m);
        m->tab[m->line][m->column] = '\0';
        m->line += 1;
        m->x += 1;
        m->column = 0;
    }
    m->tab[m->line - 1] = NULL;

    return (m->tab);
}
