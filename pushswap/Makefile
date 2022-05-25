CC		=	gcc 
CFLAGS	=	-Wall -Werror -Wextra -g3
NAME	=	push_swap
NAMEB	=	my_checker
LIBFT	=	../libft/libft.a
LIB_DIR	=	../libft
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
			utils.c 
SRCB	=	./my_checker/main_bonus.c \
			./my_checker/checker_fct.c 
OBJ		=	$(SRC:.c=.o)
OBJB	=	$(SRCB:.c=.o)
RM 		=	rm -rf
SUPPR	=	\033[00m
GRAS	=	\033[01m
CLIGNO	=	\033[05m
GREEN	=	\033[32m
RED		=	\033[31m
WHITE	=	\033[37m

all			:	$(NAME)

bonus		:	$(NAMEB)

$(LIBFT)	:
	@make -sC $(LIB_DIR)

$(NAME)		:	$(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(WHITE)Compilation $(GRAS)Push_Swap $(GREEN)$(GRAS)$(CLIGNO)OK$(SUPPR)"

$(NAMEB)	:	$(OBJB) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB) $(LIBFT)
	@echo "$(YELLOW)BONUS DONE"

%.o			:	%.c libft/*.c
	@$(CC) -o $@ -c $<

clean		:
	@make clean -sC $(LIB_DIR)
	@$(RM) $(OBJ) $(OBJB)

fclean		:	clean
	@make fclean -sC $(LIB_DIR)
	@$(RM) $(NAME) $(NAMEB)
	@echo "$(SUPPR)$(WHITE)Push_Swap is $(RED)$(GRAS)$(CLIGNO)DEAD"

re			:	fclean all

.PHONY		:	all clean fclean re