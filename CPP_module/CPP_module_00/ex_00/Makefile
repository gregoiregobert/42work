NAME		=	megaphone
OBJ_PATH	=	objs
SRCS		=	main.cpp		
CC			=	g++
CFLAGS		=	-MMD -Wall -Werror -Wextra -std=c++98
RM			=	rm -rf
OBJS		=	$(addprefix $(OBJ_PATH)/,$(SRCS:.cpp=.o))
DEPS		=	$(OBJS:.o=.d)

SUPPR		=	\033[00m
GRAS		=	\033[01m
CLIGNO		=	\033[05m
GREEN		=	\033[32m
YELLOW		=	\033[33m
RED			=	\033[31m
WHITE		=	\033[37m

vpath @%.o $(OBJ_PATH)

all				: $(NAME)

$(NAME)			: $(OBJS)
	@echo "$(WHITE)*** Compilation ***"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n    $(GRAS)CPP_ex_00 $(GREEN)$(GRAS)$(CLIGNO)OK$(SUPPR)\n"

$(OBJ_PATH)/%.o	: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS)			: | $(OBJ_PATH)

$(OBJ_PATH)		:
	@mkdir -p $(OBJ_PATH)

clean			:
	@${RM} $(OBJ_PATH)

fclean			:
	@make clean
	@${RM} ${NAME}

re				:
	@make fclean
	@make all

-include $(DEPS)

.PHONY			: all clean fclean re
