/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** tests_bsq
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/bsq.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(bsq1, test_one_column, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    struct stat bytes;
    stat("tests/maps/intermediate_map_one_column_with_obstacles_25pc", &bytes);
    size_t size = bytes.st_size;
    int fd = open("tests/maps/solved/intermediate_map_one_column_with_obstacles_25pc", O_RDONLY);
    char *buffer = malloc(sizeof(char) * size + 1);

    read(fd, buffer, size);
    bsq1("tests/maps/intermediate_map_one_column_with_obstacles_25pc", b);
    cr_assert_stdout_eq_str(buffer);
    free(buffer);
}

Test(bsq1, test_one_line, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    struct stat bytes;
    stat("tests/maps/intermediate_map_one_line_with_obstacles_25pc", &bytes);
    size_t size = bytes.st_size;
    int fd = open("tests/maps/solved/intermediate_map_one_line_with_obstacles_25pc", O_RDONLY);
    char *buffer = malloc(sizeof(char) * size + 1);

    read(fd, buffer, size);
    bsq1("tests/maps/intermediate_map_one_line_with_obstacles_25pc", b);
    cr_assert_stdout_eq_str(buffer);
    free(buffer);
}

Test(bsq1, test1, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    struct stat bytes;
    stat("tests/maps/intermediate_map_97_21_with_obstacles_25pc", &bytes);
    size_t size = bytes.st_size;
    int fd = open("tests/maps/solved/intermediate_map_97_21_with_obstacles_25pc", O_RDONLY);
    char *buffer = malloc(sizeof(char) * size + 1);

    read(fd, buffer, size);
    bsq1("tests/maps/intermediate_map_97_21_with_obstacles_25pc", b);
    cr_assert_stdout_eq_str(buffer);
    free(buffer);
}

Test(bsq1, test2, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    struct stat bytes;
    stat("tests/maps/intermediate_map_187_187_with_obstacles_50pc", &bytes);
    size_t size = bytes.st_size;
    int fd = open("tests/maps/solved/intermediate_map_187_187_with_obstacles_50pc", O_RDONLY);
    char *buffer = malloc(sizeof(char) * size + 1);

    read(fd, buffer, size);
    bsq1("tests/maps/intermediate_map_187_187_with_obstacles_50pc", b);
    cr_assert_stdout_eq_str(buffer);
    free(buffer);
}

Test(bsq1, one_empty_box, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    struct stat bytes;
    stat("tests/maps/intermediate_map_one_empty_box", &bytes);
    size_t size = bytes.st_size;
    int fd = open("tests/maps/solved/intermediate_map_one_empty_box", O_RDONLY);
    char *buffer = malloc(sizeof(char) * size + 1);

    read(fd, buffer, size);
    bsq1("tests/maps/intermediate_map_one_empty_box", b);
    cr_assert_stdout_eq_str(buffer);
    free(buffer);
}

Test(bsq1, one_filled_box, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    struct stat bytes;
    stat("tests/maps/intermediate_map_one_filled_box", &bytes);
    size_t size = bytes.st_size;
    int fd = open("tests/maps/solved/intermediate_map_one_filled_box", O_RDONLY);
    char *buffer = malloc(sizeof(char) * size + 1);

    read(fd, buffer, size);
    bsq1("tests/maps/intermediate_map_one_filled_box", b);
    cr_assert_stdout_eq_str(buffer);
    free(buffer);
}

Test(bsq1, test_ultim, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    struct stat bytes;
    stat("tests/maps/intermediate_map_10000_10000", &bytes);
    size_t size = bytes.st_size;
    int fd = open("tests/maps/solved/intermediate_map_10000_10000", O_RDONLY);
    char *buffer = malloc(sizeof(char) * size + 1);

    read(fd, buffer, size);
    bsq1("tests/maps/intermediate_map_10000_10000", b);
    cr_assert_stdout_eq_str(buffer);
    free(buffer);
}

Test(bsq1, file_without_nb, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test1", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, invalid_char_in_file, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test2", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, only_nb, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test3", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, invalid_file, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/lalalalal", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, directory_instead_file, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, invalid_char_one_line, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test4", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, invalid_char_one_col, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test11", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, invalid_nb, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test5", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, empty_file, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test7", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, not_same_cols, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test8", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, not_same_cols2, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test10", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, nb_but_empty_line, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/mapstest9", b);

    cr_assert_eq(84, ret);
}

Test(bsq1, nb_lines_diff, .init = redirect_all_std)
{
    struct bsq *b = malloc(sizeof(struct bsq));
    int ret = bsq1("tests/maps/test12", b);

    cr_assert_eq(84, ret);
}
