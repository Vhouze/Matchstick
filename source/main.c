/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** main
*/

#include "my.h"

int my_str_isalpha(char *str)
{
    while (*str) {
        if (!((*str > 64 && *str < 91) || (*str > 96 && *str < 123)))
            return (0);
        ++str;
    }
    return (1);
}

map_t *init_struct_m(char **av)
{
    map_t *m = malloc(sizeof(map_t));

    m->nb = my_getnbr(av[1]);
    m->tab = my_tab(m);
    return (m);
}

pturn_t *init_struct_p(char **av)
{
    pturn_t *p = malloc(sizeof(pturn_t));

    p->max_sticks = my_getnbr(av[2]);
    return (p);
}

void my_free(map_t *m, pturn_t *p)
{
    for (int a = 0; m->tab[a]; a++)
        free(m->tab[a]);
    free(m->tab);
    free(m);
    free(p);
}

int main(int ac, char **av)
{
    int x = 0;
    if (ac != 3)
        return (84);
    else {
        if (my_str_isalpha(av[1]) == 1 || my_str_isalpha(av[2]) == 1)
            return (84);
        map_t *m = init_struct_m(av);
        pturn_t *p = init_struct_p(av);
        if (m->nb < 1 || m->nb > 99 || p->max_sticks < 1)
            return (84);
        print_map(m);
        x = my_game(m, p);
        my_free(m, p);
        if (x == 1)
            return (1);
        else if (x == 2)
            return (2);
        else
            return (0);
    }
}
