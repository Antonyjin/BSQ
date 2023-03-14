/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** one_char
*/

#include "../include/bsq.h"

int check_char(char *buffer)
{
    int error = 0;

    for (int k = 0; buffer[k] != '\0'; k++) {
        if (buffer[k] != '.' && buffer[k] != 'o'
            && buffer[k] != '\n' && buffer[k] != '\0') {
            error = 84;
            break;
        }
    }
    return (error);
}

int one_char(char *buffer, int size)
{
    int i;

    for (i = 0; buffer[i] != '\n'; i++);
    buffer += i + 1;
    if (check_char(buffer) == 84)
        return (84);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '.')
            buffer[i] = 'x';
        if (buffer[i] == 'x')
            break;
    }
    write (1, buffer, size - (i + 2));
    write (1, "\n", 1);
    return (0);
}
