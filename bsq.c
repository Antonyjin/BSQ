/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** bsq
*/

#include "include/bsq.h"

int check_nb(struct bsq *b, char *buffer, int size)
{
    if (size < 0)
        return (84);
    b->nb_rows = fs_get_number_from_first_line(buffer);
    if (b->nb_rows < 1)
        return (84);
    b->nb_cols = fs_get_number_cols(buffer, b->nb_rows);
    if (b->nb_cols < 1)
        return (84);
    return (0);
}

int bsq1(char const *filepath, struct bsq *b)
{
    struct stat bytes;
    stat(filepath, &bytes);
    size_t size = bytes.st_size;
    b->error = 0;

    b->fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * size + 1);
    if (read(b->fd, buffer, size) <= 0)
        return (84);
    if (check_nb(b, buffer, size) == 84)
        return (84);
    buffer[size] = '\0';
    close(b->fd);
    if (b->nb_cols == 1 || b->nb_rows == 1) {
        b->error = one_char(buffer, size);
    } else {
        b->error = sev_char(buffer, b, size);
    }
    free(buffer);
    return (b->error);
}
