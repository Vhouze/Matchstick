/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my_game
*/

#include "my.h"

int my_game_loop_player(map_t *m, pturn_t *p, int turn, int player)
{
    if (countsticks(m) > 0 && turn == 0) {
        player = player_turn(m, p);
        if (player == -6665)
            return (-6665);
        m->tab = delete_stick(m, p);
        print_map(m);
        turn = 1;
    }
    return (turn);
}

int my_game_loop_ai(map_t *m, pturn_t *p, int turn)
{
    if (countsticks(m) > 0 && turn == 1) {
        ai_turn(m, p);
        m->tab = delete_stick(m, p);
        print_map(m);
        turn = 0;
    }
    return (turn);
}

int my_game(map_t *m, pturn_t *p)
{
    int turn = 0;
    int player = 0;

    while (countsticks(m) > 0) {
        turn = my_game_loop_player(m, p, turn, player);
        if (turn == -6665)
            return (-6665);
        turn = my_game_loop_ai(m, p, turn);
        if (turn == -6665)
            return (-6665);
    }
    if (countsticks(m) == 0) {
        if (turn == 1) {
            my_putstr("You lost, too bad...\n");
            return (2);
        } else
            my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}
