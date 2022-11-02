NAME		= gnl_training
SRCS		=	gnl.c 	\
				main.c	
CC			=  gcc
CFLAGS		= -Wall -Werror -Wextra -D BUFFER_SIZE=5
OBJ_PATH	= obj
RM			=  rm -rf
OBJ		=	$(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))
DEPS		= $(OBJ:.o=.d)

vpath %.o $(OBJ_PATH)

all				:	$(NAME)

$(NAME)			:	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)/%.o :	%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)			:	| $(OBJ_PATH)

$(OBJ_PATH)		:
		mkdir -p $(OBJ_PATH)

clean			:
	$(RM) $(OBJ_PATH)

fclean			:
	make clean
	$(RM) $(NAME)

re				:
	make fclean
	make all

-include $(DEPS)

.PHONY:			all clean fclean re