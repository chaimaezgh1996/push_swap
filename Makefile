CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = function_to_movs_a.c test_bigen.c push_swap.c help_function.c mouvs.c function_to_movs.c help_a.c help_b.c help_c.c help_d.c mouvs_a.c mouvs_b.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c function_to_movs_a_bonus.c help_function_bonus.c mouvs_bonus.c function_to_movs_bonus.c help_a_bonus.c help_b_bonus.c help_c_bonus.c help_d_bonus.c mouvs_a_bonus.c mouvs_b_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = push_swap
HEADER = push_swap.h

NAME_BONUS = checker
HEADER_BONUS = checker.h
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus