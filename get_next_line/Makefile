CC      = cc
CFLAGS  = -Wall -Werror -Wextra -g
AR      = ar rcs
RM      = rm -rf

SRC     = get_next_line.c get_next_line_utils.c
OBJ     = $(SRC:.c=.o)
NAME    = get_next_line.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re