CC		=	gcc 
CFLAGS	=	-Wall -Werror -Wextra -g3
NAME	=	push_swap
NAMEB	=	checker_bonus
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
SRCB	=	main_bonus.c \
			checker_fct.c \
			parsing.c \
			check.c \
			check_2.c \
			operation.c \
			operation_2.c \
			lst_utils.c \
			lst_utils_2.c \
			utils.c 
OBJ		=	$(SRC:.c=.o)
OBJB	=	$(SRCB:.c=.o)
RM 		=	rm -rf
SUPPR	=	\033[00m
GRAS	=	\033[01m
CLIGNO	=	\033[05m
GREEN	=	\033[32m
YELLOW	=	\033[33m
RED		=	\033[31m
WHITE	=	\033[37m

all			:	$(NAME)

bonus		:	$(NAMEB)

$(LIBFT)	:
	@make -sC $(LIB_DIR)

$(NAMEB)	:	$(OBJB) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB) $(LIBFT)
	@echo "$(GRAS)$(WHITE)Bonus $(YELLOW)$(CLIGNO)DONE$(SUPPR)"

$(NAME)		:	$(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(WHITE)Compilation $(GRAS)Push_Swap $(GREEN)$(GRAS)$(CLIGNO)OK$(SUPPR)"

%.o			:	%.c libft/*.c
	@$(CC) -o $@ -c $<

clean		:
	@make clean -sC $(LIB_DIR)
	@$(RM) $(OBJ) $(OBJB)

fclean		:	clean
	@make fclean -sC $(LIB_DIR)
	@$(RM) $(NAME) $(NAMEB)
	@echo "$(SUPPR)$(WHITE)Push_Swap is $(RED)$(GRAS)$(CLIGNO)DEAD"

re		:	fclean all

.PHONY		:	all clean fclean re
