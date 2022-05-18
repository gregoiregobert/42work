CC = gcc 
CFLAGS = -Wall -Werror -Wextra
EXEC = push_swap
SRC = 	algo.c \
		check_better_move.c \
		check.c \
		LIS.c \
		lst_utils.c \
		lst_utils_2.c \
		main.c \
		operation.c \
		operation_2.c \
		parsing.c \
		sort.c \
		utils.c \
		../libft/ft_isdigit.c 
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $<

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(EXEC)