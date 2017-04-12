##
## Makefile for *** in /home/leandre/***
## 
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
## 
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Thu Apr 13 01:31:36 2017 Léandre Blanchard
##

NAME	= tetris

CC	= gcc

LIB	= -lncursesw -L./lib -lmy

SRCS	= main.c \
	  init.c \
	  menu.c \
	  play.c \
	  tetriminos.c \
	  falling.c \
	  break_lines.c \
	  move.c \
	  end.c \
	  rotate.c

OBJ	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	+= -W -g3 -Werror -Wall -Wextra -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
