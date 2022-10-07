NAME		=	philosopher
CFLAGS		=	-MMD -Wall -Werror -Wextra
SRCS		=	main.c				\
				err_msg.c			\
				parsing_manager.c	\
				utils.c				\
				init_data.c
OBJS		=	$(addprefix $(OBJS_PATH)/,$(SRCS:.c=.o))
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

$(OBJS_PATH)/%.o	:	%.c
	@gcc $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(OBJS)			:	| $(OBJS_PATH)

$(OBJS_PATH)		:
	@mkdir -p $(OBJS_PATH)

clean			:
	@$(RM) $(OBJS_PATH)

fclean			:
	@make clean
	@$(RM) $(NAME)

re				:
	@make fclean
	@make all

-include $(DEPS)

.PHONY			:	all clean fclean re
