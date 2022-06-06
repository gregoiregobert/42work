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

NAME	=	training
SRCS	=	main.c 
OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f
CC		=	gcc
LIBFT	=	../libft/libft.a
LIB_DIR	=	../libft
CFLAGS	=	-Wall -Werror -Wextra -g3
SUPPR	=	\033[00m
GRAS	=	\033[01m
CLIGNO	=	\033[05m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RED		=	\033[31m
WHITE	=	\033[37m

all			: $(NAME)

$(LIBFT)	:	
	@make -sC $(LIB_DIR)

$(NAME)		: $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	@echo "$(GRAS)$(YELLOW)Training $(SUPPR)$(CLIGNO)Compilation$(SUPPR)"

%.o			: %.c libft/*.c
	@$(CC) $(CFLAGS) -c $< -o $@


clean		:
	@make clean -sC $(LIB_DIR)
	@$(RM) $(OBJS)
	@echo "$(BLUE)$(GRAS)CLEAN$(SUPPR)"

fclean		: clean
	@make fclean -sC $(LIB_DIR)
	@$(RM) $(NAME) 
	@echo "$(GRAS)$(WHITE)All $(RED)gone...$(SUPPR)"

re			: fclean all

.PHONY		: all clean fclean re bonus
