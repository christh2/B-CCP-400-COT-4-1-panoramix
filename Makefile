##
## EPITECH PROJECT, 2024
## panoramix
## File description:
## Makefile
##

SRC	=	src/druide.c	\
		src/gaulois.c	\
		src/marmite.c   \
		src/panoramix.c

NAME 	=	panoramix


all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -g3

clean:
	rm -f *#
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	fclean all
