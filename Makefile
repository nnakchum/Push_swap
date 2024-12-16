NAME = push_swap
BONUS_NAME = checker
GET_NEXT_LINE = get_next_line.a
FT_PRINTF = ft_printf.a

SRC_FILES =	push_swap.c command_1.c command_2.c command_3.c \
		sort_1.c sort_2.c utilities_1.c utilities_2.c \
		ft_split.c
BONUS_FILES = checker.c
SRC_DIR = src/
BONUS_DIR = bonus/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
BONUS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
OBJ = ${SRC:.c=.o}
OBJB = ${BONUS:.c=.o}
OBJBB = ${filter-out src/push_swap.o ,${OBJ}}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
FSANITIZE	= -fsanitize=address -g3
LDFLAGS = -L $(SRC_DIR) 
INCLUDE = -I include
RM = rm -rf

all:		$(NAME)

$(NAME) : $(OBJ)
		@make -C get_next_line
		@cp get_next_line/get_next_line.a .
		@make -C ft_printf
		@cp ft_printf/ft_printf.a .
		$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(GET_NEXT_LINE) $(FT_PRINTF) -o $(NAME)

bonus : $(NAME) $(OBJB)
		$(CC) $(CFLAGS) $(OBJBB) $(OBJB) $(INCLUDE) $(GET_NEXT_LINE) $(FT_PRINTF) -o $(BONUS_NAME)

clean :
		make clean -C get_next_line
		make clean -C ft_printf
		${RM} ${OBJ}
		${RM} ${OBJB}

fclean : clean
		@make fclean -C get_next_line
		@make fclean -C ft_printf
		${RM} $(NAME)
		${RM} $(BONUS_NAME)
		${RM} $(GET_NEXT_LINE)
		${RM} get_next_line/$(FT_PRINTF)
		${RM} $(FT_PRINTF)
		${RM} pft_rintf/$(FT_PRINTF)

re : fclean all

.PHONY:		all clean fclean re