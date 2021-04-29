#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for bistro
##

SRC	=	my_putstr.c			\
		my_putchar.c		\
		my_put_nbr.c		\
		my_getnbr.c			\
		initialisation.c	\
		rendering.c 		\
		useful.c			\
		move.c 				\
		audio.c 			\
		animation.c 		\
		manage.c 			\
		player_controls.c	\
		create.c 			\
		menu.c 				\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:    $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f .#*

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	clean all
