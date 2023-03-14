##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

CC		=	gcc

SRC		=	main.c						\
			bsq.c						\
			sources/alloc_mem.c				\
			sources/calcul_tab.c				\
			sources/fill_tab.c				\
			sources/free_mem.c				\
			sources/fs_get_number_cols.c			\
			sources/fs_get_number_from_first_line.c		\
			sources/get_smallest.c				\
			sources/replace_tab.c				\
			sources/sev_char.c				\
			sources/one_char.c				\

SRC2	=		bsq.c						\
			sources/alloc_mem.c				\
			sources/calcul_tab.c				\
			sources/fill_tab.c				\
			sources/free_mem.c				\
			sources/fs_get_number_cols.c			\
			sources/fs_get_number_from_first_line.c		\
			sources/get_smallest.c				\
			sources/replace_tab.c				\
			sources/sev_char.c				\
			sources/one_char.c				\

FTESTS		=	--coverage -lcriterion

TEST_SRC	=	tests/tests_bsq.c	\

TEST		=	unit_tests

OBJ		=	$(SRC:.c=.o)

NAME		=	bsq

CFLAGS		=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -I include/bsq.h -o $(NAME) $(FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.c~
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

re:	fclean all tests_run

tests_run:
		$(CC) -o $(TEST) $(TEST_SRC) $(SRC2) $(FLAGS) -I include/ $(FTESTS)
		./$(TEST)
		gcovr --exclude tests/
