# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palbanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 13:38:54 by palbanes          #+#    #+#              #
#    Updated: 2022/04/16 18:10:10 by palbanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

NAMEBONUS	= checker

LIB_DIR		= ./libft

LIBFT		= ./libft/libft.a

HEADER		= -I./push_swap.h

SRCS		= main.c list_utils.c parsing.c \
		  push_a.c push_b.c swaps.c rotates.c r_rotates.c \
		  algo_back_to_a.c algo_fill_b.c algo.c algo_utils.c \

SRCSBONUS	= push_a_only.c push_b_only.c rotates.c r_rotates.c swaps.c \
		  parsing.c list_utils.c algo_utils.c checker.c checker_utils.c checker_util.c

OBJS		= ${SRCS:.c=.o}

OBJSBONUS	= ${SRCSBONUS:.c=.o}

RM		= rm -f

CC		= gcc

FLAGS		= -Wall -Werror -Wextra -g3

all		: ${NAME}

bonus		: ${NAMEBONUS}

${NAMEBONUS}	: ${OBJSBONUS} ${LIBFT}
			@echo "\033[33m---Compiling Bonus--"
			@${CC} ${FLAGS} ${OBJSBONUS} -o ${NAMEBONUS} ${LIBFT}
			@echo "\033[33m >>OK"

${NAME}		: ${OBJS} ${LIBFT}
			@echo "\033[35m-----Compiling------"
			@${CC} ${FLAGS} ${OBJS} -o ${NAME} ${LIBFT}
			@echo "\033[35m >>OK"
			
${LIBFT}	:
			@echo "\033[34m---Building Libft---"
			@make -sC libft
			@echo "\033[34m >>OK"
			
%.o		: %.c libft/*.c
			@${CC} ${CFLAGS} -c $< -o $@


clean		:
			@echo "\033[32m---Cleaning Libft---"
			@make clean -sC ${LIB_DIR}
			@echo "\033[32m >>OK"
			@echo "\033[32m--Cleaning Objects--"
			${RM} ${OBJS} ${OBJSBONUS}
			@echo "\033[32m >>OK"

fclean		: clean
			@echo "\033[32m----Cleaning All----"
			@make fclean -sC ${LIB_DIR}
			${RM} ${NAME} ${NAMEBONUS}
			@echo "\033[32m >>OK"

re		: fclean all

.PHONY		: all clean fclean re bonus
