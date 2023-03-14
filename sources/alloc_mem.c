/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** alloc_mem
*/

#include "../include/bsq.h"

void alloc_mem(struct bsq *b)
{
    b->tab = malloc(sizeof(int) * b->nb_rows * b->nb_cols);
    for (int i = 0; i < b->nb_rows; i++) {
        b->tab[i] = malloc(sizeof(int) * b->nb_cols);
    }
}
