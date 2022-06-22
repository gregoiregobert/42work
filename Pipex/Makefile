CC		=	gcc 
CFLAGS	=	-Wall -Werror -Wextra -g3
NAME	=	pipex
NAMEB	=	pipex_bonus
LIBFT	=	../libft/libft.a
LIB_DIR	=	../libft
SRC		=	main.c	\
			parsing_err.c	\
			parsing_err2.c	\
			parsing_pipex2_out_bonus.c	\
			parsing_pipex.c	\
			exec_pipex.c	\
			exec_pipex2.c	\
			exec_err.c	\
			free_all.c
SRCB	=	main.c	\
			parsing_err.c	\
			parsing_err2.c	\
			parsing_pipex2.c	\
			parsing_pipex.c	\
			exec_pipex.c	\
			exec_pipex2.c	\
			exec_err.c	\
			free_all.c
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

bonus		: 	$(NAMEB)

$(LIBFT)	:
	@make -sC $(LIB_DIR)

$(NAME)		:	$(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(WHITE)Compilation $(GRAS)Pipex $(GREEN)$(GRAS)$(CLIGNO)OK$(SUPPR)"

$(NAMEB)	:	$(OBJB) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB) $(LIBFT)
	@echo "$(WHITE)Compilation $(GRAS)Pipex $(YELLOW)BONUS $(GREEN)$(GRAS)$(CLIGNO)OK$(SUPPR)"

%.o			:	%.c libft/*.c
	@$(CC) -o $@ -c $<

clean		:
	@make clean -sC $(LIB_DIR)
	@$(RM) $(OBJ) $(OBJB)

fclean		:	clean
	@make fclean -sC $(LIB_DIR)
	@$(RM) $(NAME) $(NAMEB)
	@echo "$(SUPPR)$(WHITE)Pipex is $(RED)$(GRAS)$(CLIGNO)DEAD$(SUPPR)"

re			:	fclean all

.PHONY		:	all clean fclean re
