/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** get_smaller
*/

int get_smallest(int a, int b, int c)
{
    int res = 0;

    if (a < b && a < c) {
        res = a;
    } else if (b < c) {
        res = b;
    } else
        res = c;
    return (res);
}
