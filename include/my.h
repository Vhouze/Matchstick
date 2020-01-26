/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my.h
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MY_H_
#define MY_H_

typedef struct map_s
{
    int nb;
    int line;
    int column;
    int x;
    char **tab;
}map_t;

typedef struct pturn_s
{
    int line;
    int match;
    char *str;
    size_t len;
    int max_sticks;
}pturn_t;

int my_strlen(char *);
int my_putstr(char *);
int my_putnbr(int);
int my_getnbr(char *);
char **my_tab(map_t *);
void print_map(map_t *);
int countsticks(map_t *);
int *check_last_pipe(map_t *);
char **delete_stick(map_t *, pturn_t *);
int check_stick(map_t *, pturn_t *);
int check_last_stick(map_t *, pturn_t *);
int my_game(map_t *, pturn_t *);
int player_turn(map_t *, pturn_t *);
int player_line(map_t *, pturn_t *);
int player_matches(map_t *, pturn_t *);
int player_matches_second(map_t *, pturn_t *);
int player_matches_third(map_t *, pturn_t *);
int player_matches_fourth(map_t *, pturn_t *);
int ai_turn(map_t *, pturn_t *);
void ai_rand_line(map_t *, pturn_t *, int *);
void ai_rand_matches(map_t *, pturn_t *, int, int *);

#endif
