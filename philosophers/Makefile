NAME		=	philosopher
CFLAGS		=	-Wall -Werror -Wextra
SRCS		=	main.c				\
				err_msg.c			\
				parsing_manager.c	\
				utils.c				
OBJS		=	$(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))
DEPS		=	$(OBJS:.o=.d)
RM			=	rm -rf
HEADERS		=	includes 
SRCS_PATH	=	srcs
OBJS_PATH	=	objs
vpath %.h $(HEADERS)
vpath %.c $(SRCS_PATH)
vpath %.o $(OBJS_PATH)

all = $(NAME)

$(NAME)			:	$(OBJS)
	@gcc $(CFLAGS) $(OBJS) -I $(HEADERS) -o $(NAME)

$(OBJ_PATH)/%.o	:	%.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(OBJS)			:	| $(OBJS_PATH)

(OBJ_PATH)		:
	@mkdir -p $(OBJS_PATH)

clean			:
	@$(RM) $(OBJS_PATH)

fclean			:
	@make clean
	@$(RM) $(NAME)

-include $(DEPS)

.PHONY			:	all clean fclean re
