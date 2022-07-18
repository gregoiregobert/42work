# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:28:31 by ggobert           #+#    #+#              #
#    Updated: 2021/12/15 11:30:20 by ggobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			print_tool.c \
			print_tool2.c \
			print_tool3.c \
			print_ft_convert.c \
			print_ft_convert2.c


OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC		=	gcc

RM		= 	rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs $@ ${OBJS}

all:		${NAME}

clean: 
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
