NAME		=	ex_02
OBJ_PATH	=	objs
SRCS		=	main.cpp
CC			=	c++
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
	@echo -n "C"
	@sleep 1e-1
	@echo -n "o"
	@sleep 1e-1
	@echo -n "m"
	@sleep 1e-1
	@echo -n "p"
	@sleep 1e-1
	@echo -n "i"
	@sleep 1e-1
	@echo -n "l"
	@sleep 1e-1
	@echo -n "a"
	@sleep 1e-1
	@echo -n "t"
	@sleep 1e-1
	@echo -n "i"
	@sleep 1e-1
	@echo -n "o"
	@sleep 1e-1
	@echo "n"
	@sleep 1e-1
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GRAS)CPP_ex_02 $(GREEN)$(GRAS)$(CLIGNO)OK$(SUPPR)"

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
