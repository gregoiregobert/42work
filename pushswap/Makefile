CC		=	gcc 
CFLAGS	=	-Wall -Werror -Wextra -g3
NAME	=	push_swap
SRC		=	algo.c \
			check_better_move.c \
			check_better_move_2.c \
			check.c \
			check_2.c \
			LIS.c \
			lst_utils.c \
			lst_utils_2.c \
			main.c \
			operation.c \
			operation_2.c \
			parsing.c \
			sort.c \
			small_sort.c \
			small_sort_2.c \
			utils.c \
			../libft/ft_isdigit.c \
			../libft/ft_atoi.c \
			../libft/ft_strlen.c
OBJ		=	$(SRC:.c=.o)
RM 		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o		:	%.c
	$(CC) -o $@ -c $<

clean	:
	@$(RM) *.o

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re