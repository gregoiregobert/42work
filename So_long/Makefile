CC			=	gcc 
CFLAGS		=	
FLAGS_LIB	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME		=	so_long
MLX			=	minilibx-linux/libmlx.a
MLX_DIR 	=	minilibx-linux
LIBFT		=	./libft/libft.a
LIB_DIR		=	./libft
SRC			=	main.c	\
				handle_keypress.c	\
				render.c	\
				initialize.c	\
				open_fd.c	\
				dimension_rect.c	\
				free_map.c	\
				parsing.c	\
				rect_check.c	\
				wall_check.c	\
				item_position_out_check.c \
				symbole_check.c	\
				pars_manager.c	\
				check_args.c	\
				msg_err.c	\
				display_tile.c	\
				display_map.c	\
				init_img.c	\
				map_manager.c	\
				perror_exit.c	\
				up_dir.c	\
				down_dir.c	\
				left_dir.c	\
				right_dir.c	\
				no_c.c	\
				exit_properly.c	\
				destroy_img.c
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
	@$(CC) $(OBJ) -L $(MLX_DIR) $(FLAGS_LIB) -o $(NAME) $(LIBFT)
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
	@echo "$(WHITE)so_long is $(RED)$(GRAS)$(CLIGNO)DEAD$(SUPPR)"

re			:	fclean all

.PHONY		:	all clean fclean re