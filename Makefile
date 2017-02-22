##
## Makefile for Project in /home/shielder/Projects/
##
## Made by Maxime PICOT
## Login   <shielder@epitech.net>
##
## Started on  Mon Nov 21 09:49:22 2016 Maxime PICOT
## Last update Wed Feb 22 16:03:04 2017 Maxime PICOT
##

COMP	=	gcc

SRC	=	src/add_alums.c		\
		src/error.c		\
		src/get_next_line.c	\
		src/game.c		\
		src/ia.c		\
		src/my_putnbr.c		\
		src/check_win.c		\
		src/misc.c		\
		src/misc2.c		\
		src/map_generator.c	\
		src/main.c	

CFLAGS	=	-I./include/ -Wall -Wextra -W -g

LDLIBS	=	-L./lib/my

LDFLAGS	=	

OBJ	=	$(SRC:src/%.c=obj/%.o)

RM	=	rm -f

NAME	=	matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMP) -o $(NAME) $(OBJ)  $(LDLIBS) $(LDFLAGS)

obj/%.o:	src/%.c
		@mkdir -p obj/
		$(COMP) -o $@ -c $< $(CFLAGS)

clean:
		$(RM) $(OBJ)
		$(RM) -rf obj/

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
