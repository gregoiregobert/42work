CC			=	gcc -g3 -fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror
FLAGS_LIB	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME		=	so_long
MLX			=	minilibx-linux/libmlx.a
MLX_DIR 	=	minilibx-linux
LIBFT		=	./libft/libft.a
LIB_DIR		=	./libft
SRC			=	main.c						\
				handle_keypress.c			\
				initialize.c				\
				open_fd.c					\
				dimension_rect.c			\
				free_map.c					\
				parsing.c					\
				rect_check.c				\
				wall_check.c				\
				item_position_out_check.c	\
				symbole_check.c				\
				pars_manager.c				\
				check_args.c				\
				msg_err.c					\
				msg_err_1.c					\
				display_tile.c				\
				display_tile_flower.c		\
				display_tile_hive.c			\
				display_tile_bee.c			\
				display_map.c				\
				init_img.c					\
				map_manager.c				\
				perror_exit.c				\
				dir_up.c					\
				dir_down.c					\
				dir_left.c					\
				dir_right.c					\
				no_c.c						\
				exit_properly.c				\
				destroy_img.c				\
				cut_nl.c					\
				handle_cross.c				\
				position_perso.c			\
				img_protect.c				\
				find_way.c					\
				test_up.c					\
				test_down.c					\
				test_right.c				\
				test_left.c					\
				backtrack_move.c
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
