CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = function_utiliz_1.c function_utiliz_2.c function_utiliz_3.c push_swap.c
OBJ = ${SRC:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
re : fclean all

.phony : re fclean clean all
