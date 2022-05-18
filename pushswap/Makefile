CC = gcc 
CFLAGS = -Wall -Werror -Wextra
EXEC = push_swap
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $<

%.o : %.c
