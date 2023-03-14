/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** main
*/

#include "include/bsq.h"

int main(int ac, char **av)
{
    struct bsq *b = malloc(sizeof(struct bsq));

    if (ac != 2) {
        return (84);
    }
    if (bsq1(av[1], b) == 84)
        return (84);
    free(b);
    return (0);
}
