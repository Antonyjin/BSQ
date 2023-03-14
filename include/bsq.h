/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

typedef struct bsq {
    int **tab;
    int fd;
    int a;
    int b;
    int c;
    int size;
    int error;
    int nb_cols;
    int nb_rows;
    int num;
    int num_rows;
    int num_cols;
}bsq;

void my_putchar(char c);
int bsq1(char const *filepath, struct bsq *b);
void alloc_mem(struct bsq *b);
int fs_get_number_from_first_line(char const *filepath);
int fs_get_number_cols(char *buffer, int nb_rows);
int fill_tab(char *buffer, struct bsq *b);
void calcul_tab(struct bsq *b);
int get_smallest(int a, int b, int c);
void replace_tab(char *buffer, struct bsq *b, int size);
void free_mem(struct bsq *b);
int one_char(char *buffer, int size);
int sev_char(char *buffer, struct bsq *b, int size);

#endif /* !BSQ_H_ */
