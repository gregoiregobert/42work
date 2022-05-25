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
SRCB	=	my_checker/main.c \
			my_checker/checker_fct.c 
OBJ		=	$(SRC:.c=.o)
OBJB	=	$(SRCB:.c=.o)
RM 		=	rm -rf
SUPPR	=	\033[00m
GRAS	=	\033[01m
CLIGNO	=	\033[05m
YELLOW 	=	\033[33m
GREY	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
BLUE	=	\033[34m
PURPLE	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m
INVERSE	=	\033[07m

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "	$(WHITE)Compilation $(YELLOW)$(GRAS)$(CLIGNO)OK"

bonus	:	$(OBJB)
	$(CC) $(CFLAGS) -o $@ $^

%.o		:	%.c
	@$(CC) -o $@ -c $<

clean	:
	@$(RM) *.o

fclean	:	clean
	@$(RM) $(NAME)
	@echo "$(GRAS)$(RED)Trash all"

re		:	fclean all

.PHONY	:	all clean fclean re