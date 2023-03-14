/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** fs_get_number_from_first_line
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void fs_understand_return_of_read(int fd , char *buffer , int size);

int my_getnbr(char *str)
{
    int	a = 0;
    int	b = 1;

    while (*str != 0 && *str >= '0' && *str <= '9') {
        a = a * 10;
        a = a + *str - 48;
        str = str + 1;
    }
    a = a * b;
    return (a);
}

int fs_get_number_from_first_line(char *buffer)
{
    char nbr[30000];
    int i = 0;
    int a = 0;
    int error = 0;

    for (; buffer[i] != '\n'; i++) {
        if (buffer[i] < '0' || buffer[i] > '9') {
            error = -1;
            break;
        }
        nbr[i] = buffer[i];
    }
    if (buffer[i + 1] == '\0' || error == -1)
        return (-1);
    nbr[i] = '\0';
    a = my_getnbr(nbr);
    return (a);
}
