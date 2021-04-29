##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for my_hunter
##

SRC	=	src/my_runner.c		\

OBJ	=	$(SRC)

NAME = my_runner

all: makelib
	gcc -o $(NAME) src/$(NAME).c -L./lib -lmy -I./includes -l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window

makelib:
	make -C lib/my

clean:
	make -C lib/my clean

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)

re: fclean

run:
	./my_runner -h