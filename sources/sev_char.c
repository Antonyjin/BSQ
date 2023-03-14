/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** sev_char
*/

#include "../include/bsq.h"

int sev_char(char *buffer, struct bsq *b, int size)
{
    alloc_mem(b);
    b->error = fill_tab(buffer, b);
    if (b->error == 84)
        return (b->error);
    calcul_tab(b);
    replace_tab(buffer, b, size);
    free_mem(b);
    return (b->error);
}
