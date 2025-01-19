CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME_BONUS = checker
SRC = function_utiliz_1.c function_utiliz_2.c function_utiliz_3.c \
		function_utiliz_4.c push_swap.c function_utiliz_5.c function_utiliz_6.c function_utiliz_7.c \
		function_utiliz_8.c
OBJ = $(SRC:.c=.o)
B_SRC = push_swap_bonus.c function_utiliz_3_bonus.c src/function_utiliz_1_bonus.c \
		src/get_next_line.c src/function_utiliz_2_bonus.c  src/function_utiliz_4_bonus.c \
		src/function_utiliz_5_bonus.c src/function_utiliz_6_bonus.c
BOB = $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BOB)
	$(CC) $(CFLAGS) $(BOB) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJ) $(BOB)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re
