/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** free_mem
*/

#include "../include/bsq.h"

void free_mem(struct bsq *b)
{
    for (int i = 0; i < b->nb_rows; i++) {
        free(b->tab[i]);
    }
    free(b->tab);
}
