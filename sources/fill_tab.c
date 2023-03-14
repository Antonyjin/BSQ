/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** fill_tab
*/

#include "../include/bsq.h"

int check_character(char c, struct bsq *b, int l, int j)
{
    if ((c == '\n' && j != b->nb_cols) || j > b->nb_cols)
        return (84);
    if (c != 'o' && c != '.' && c != '\0' && c != '\n')
        return (84);
    if (c == '.') {
        b->tab[l][j] = 1;
        return (0);
    }
    if (c == 'o')
        b->tab[l][j] = 0;
    return (0);
}

int check_line(int error, char c)
{
    if (c != '\0')
        return (84);
    return (error);
}

int fill_tab(char *buffer, struct bsq *b)
{
    int i = 0;
    int j = 0;
    int l = 0;
    int error = 0;

    for (; buffer[i] != '\n'; i++);
    i++;
    while (l != b->nb_rows) {
        for (; j != b->nb_cols && error == 0; j++, i++) {
            error = check_character(buffer[i], b, l, j);
        }
        if (error == 84) {
            break;
        }
        j = 0;
        i++;
        l++;
    }
    error = check_line(error, buffer[i]);
    return (error);
}
