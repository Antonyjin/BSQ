/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** calcul_tab
*/

#include "../include/bsq.h"

void check_small_num(struct bsq *b, int y, int x)
{
    int i = b->tab[y - 1][x - 1];
    int j = b->tab[y][x - 1];
    int k = b->tab[y - 1][x];

    b->tab[y][x] = get_smallest(i, j, k) + 1;
    if (b->num < b->tab[y][x]) {
        b->num = b->tab[y][x];
        b->num_rows = y;
        b->num_cols = x;
    }
}

void calcul_line(struct bsq *b, int y, int x)
{
    while (x != b->nb_cols) {
        if (b->tab[y][x] == 0) {
            x++;
        } else {
            check_small_num(b, y, x);
            x++;
        }
    }
}

void calcul_tab(struct bsq *b)
{
    int x = 1;
    int y = 1;

    b->num = b->tab[y][x];
    b->num_rows = y;
    b->num_cols = x;
    while (y != b->nb_rows) {
        calcul_line(b, y, x);
        y++;
    }
}
