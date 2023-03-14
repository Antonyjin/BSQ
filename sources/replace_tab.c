/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** replace_tab
*/

#include "../include/bsq.h"

void replace_tab(char *buffer, struct bsq *b, int size)
{
    int i;
    int l;
    int p = 0;
    int pos = 0;
    int rows = b->num_rows;
    int cols = b->num_cols;

    for (i = 0; buffer[i] != '\n'; i++);
    buffer += i + 1;
    for (int m = 0; m != b->num; m++) {
        for (l = 0; l != b->num; l++) {
            pos = b->nb_cols * rows + cols - l - 1 + rows + 1 - p;
            buffer[pos] = 'x';
        }
        l = 0;
        p += (b->nb_cols + 1);
    }
    write (1, buffer, size - i - 2);
    write(1, "\n", 1);
}
