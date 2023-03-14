/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** fs_get_number_rows
*/

int fs_get_number_cols(char *buffer, int nb_rows)
{
    int i;
    int k;
    char end;

    for (k = 0; buffer[k] != '\n'; k++);
    ++k;
    if (nb_rows == 1) {
        end = '\0';
    } else
        end = '\n';
    for (i = 0; buffer[k] != end; k++, i++);
    return (i);
}
