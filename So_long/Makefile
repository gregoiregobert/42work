CC			=	gcc 
CFLAGS		=	-Wall -Werror -Wextra
FLAGS_LIB	=	-lmlx -lm -lXext -lX11 
NAME		=	so_long
MLX			=	minilibx-linux/libmlx.a
MLX_DIR 	=	minilibx-linux
LIBFT		=	../libft/libft.a
LIB_DIR		=	../libft
SRC			=	main.c	\
				handle_input.c
OBJ			=	$(SRC:.c=.o)
RM 			=	rm -rf
SUPPR		=	\033[00m
GRAS		=	\033[01m
CLIGNO		=	\033[05m
GREEN		=	\033[32m
YELLOW		=	\033[33m
RED			=	\033[31m
WHITE		=	\033[37m

all			:	$(NAME)

$(LIBFT)	:
	@make -sC $(LIB_DIR)

$(MLX)		:
	@make -sC $(MLX_DIR)

$(NAME)		:	$(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) -L $(MLX_DIR) $(FLAGS_LIB) -o $(NAME) $(LIBFT)
	@echo "$(WHITE)Compilation $(GRAS)so_long $(GREEN)$(GRAS)$(CLIGNO)OK$(SUPPR)"

%.o			:	%.c libft/*.c
	@$(CC) -o $@ -c $<

clean		:
	@make clean -sC $(LIB_DIR)
	@make clean -sC $(MLX_DIR)
	@$(RM) $(OBJ) $(OBJB)

fclean		:	clean
	@make fclean -sC $(LIB_DIR)
	@$(RM) $(NAME) $(NAMEB)
	@echo "$(SUPPR)$(WHITE)so_long is $(RED)$(GRAS)$(CLIGNO)DEAD"

re			:	fclean all

.PHONY		:	all clean fclean re
